#!/usr/bin/perl -w
#
# Author: Bert JW Regeer
# Created: Nov 27, 2005
# Version: 0.1
# Descrip: Uses pf or any other program to add an IP address to a blocked
#          list that is not allowed to access neither ftp or ssh, two things
#          that could be used to gain unauthorized access to the system by
#          guessing usernames. SSHD is more vulnerable, so we monitor that
#          first.

#   Copyright (c) 2004, Geoffrey Garside
#   Copyright (c) 2005, Bert JW Regeer
#   All rights reserved.
#
#   Redistribution and use in source and binary forms, with or 
#   without modification, are permitted provided that the following 
#   conditions are met:
#
#     o Redistributions of source code must retain the above 
#       copyright notice, this list of conditions and the following 
#       disclaimer.
#     o Redistributions in binary form must reproduce the above 
#       copyright notice, this list of conditions and the following 
#       disclaimer in the documentation and/or other materials 
#       provided with the distribution.
#     o Neither the name of the Geoffrey Garside or Bert JW Regeer  
#       nor the names of its contributors may be used to endorse 
#       or promote products derived from this software without specific  
#       prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
#   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
#   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
#   FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
#   COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
#   INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
#   BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
#   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
#   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
#   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
#   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
#   POSSIBILITY OF SUCH DAMAGE.

# First version came as audit_auth written by Geoffrey Garside from http://geffy.co.uk/
# it was modified to automatically block IP's by Bert JW Regeer

use strict;
package auditban;
# Start the program
&run();     # run, go, process

# Hashes to store the kind of error
# If the username is wrong, you get 3 chances to try before being blocked
# If password being used is wrong for a user you get 10 chances before being blocked

my (@user, @invalid);

sub run {

        while (<>) {
                # fancy a quick munch
                chomp;
  
                # only search for sshd entries
                if (/sshd/) {
                        my $username;
                        my $ip;
                        if (/Failed/) {
                                # Get IP address they were coming from, as well as the username that failed
                                if (/[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}/) {
                                        $ip = $&;
                                }
                                if (/invalid user/) {
                                        next;
                                }
                                if (/Failed .*? for ([a-zA-Z0-9_-]*)/) {
                                        $username = $1;
                                }
                                &addentry($ip, $username, "failed");
                                next;
                        }
                        
                        if (/Invalid/) {
                                # Get IP address they were coming from, as well as the username that is invalid
                                if (/[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}/) {
                                        $ip = $&;
                                }
                                if (/Invalid user ([a-zA-Z0-9_-]*)/) {
                                        $username = $1;
                                }
                                &addentry($ip, $username, "invalid");
                                next;
                        }

                        if (/Accepted/) {
                                if (/[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}/) {
                                        $ip = $&;
                                }
                                if (/Accepted .*? for ([a-zA-Z0-9_-]*)/) {
                                        $username = $1;
                                }
                                &removeentry($ip, $username);
                                next;
                        }
                 }
        }
}

sub addentry {
        our %user;
        our %invalid;
        my ($ip, $username, $type) = @_;

        if ($type eq "failed") {
                # Fine, the user failed his or her password, they get a total of 10 tries before they are blocked. Basically an infinite times if from different IP's.
                if (exists $user{$ip}) {
                        $user{$ip} += 1;
                }
                else {
                        $user{$ip} = 1;
                }
                print STDERR << "EOF";
$username from $ip has $user{$ip} invalid logins out of 10
EOF
                if ($user{$ip} == 10) {
                        &banip($ip);
                }
        }
        if ($type eq "invalid") {
                # This person has three tries to get a correct username otherwise they are blocked
                if (exists $invalid{$ip}) {
                        $invalid{$ip} += 1;
                }
                else {
                        $invalid{$ip} = 1;
                }
                print STDERR << "EOF";
Idiot from $ip has tried $username and has $invalid{$ip} bad logins out of 3
EOF
                if ($invalid{$ip} == 3) {
                        &banip($ip);
                }
        }
}

sub removeentry {
        our %user;
        my ($ip, $username) = @_;

        if (exists $user{$ip}) {
                $user{$ip} -= 1;
        }
        else {
                $user{$ip} = 0;
        }
        print STDERR << "EOF";
$username from $ip has $user{$ip} invalid logins. Just logged in successfully!
EOF
}

sub banip {
        my ($ip) = @_;
        my $bancommand = "/sbin/pfctl -T add -t accountout $ip 2>&1 |";
        open(BAN, $bancommand);
        while (<BAN>) {
                if (/1\/1 addresses added\./) {
                        print STDERR << "EOF";
We banned someone at $ip.
EOF
                }
        }
        close(BAN);
}
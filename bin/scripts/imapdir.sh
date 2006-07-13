#!/bin/sh
##
 # Copyright 2006 Bert JW Regeer. All rights  reserved.
 #
 #
 # Redistribution and use in source and binary forms, with or without
 # modification, are permitted provided that the following conditions
 # are met:
 # 1. Redistributions of source code must retain the above copyright
 #    notice, this list of conditions and the following disclaimer.
 # 2. Redistributions in binary form must reproduce the above copyright
 #    notice, this list of conditions and the following disclaimer in the
 #    documentation and/or other materials provided with the distribution.
 #
 # THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 # ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 # IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 # ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 # FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 # DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 # OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 # HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 # LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
 # The views and conclusions contained in the software and  documentation are
 # those of the authors and should not be  interpreted as representing official
 # policies, either expressed  or implied, of bsdPanel project.
 #
 ##

##
 # This script is used to create IMAPdir folders for a vpopmail structure, this is needed
 # when the IMAPD is binc-imap and it is set to IMAPdir support. It will check if all the
 # right directories have been created for both spamassassin and IMAPdir, as well as the
 # that the symlink from INBOX -> ../Maildir is in order, if not it will fix the error.
 # This script can be run from cron, as it does nothing if everything is in order.
 ## 

OLDPWD=$PWD
# Find all the domains that exist in vpopmail. Hardcoded path, symlink the domains dir if you move it
for i in `find /usr/local/vpopmail/domains/ -type d -maxdepth 1 | grep -v '^.$' | grep -v 'domains/$'`; do
	cd $i
	echo "Domain: $i"
	# Find all the users in that domain
	for e in `find . -type d -maxdepth 1 | grep -v '^.$'`; do
		cd $e
		echo "  User: $e"
		# Check if an IMAPdir exists
		if [ ! -d IMAPdir ]; then
			mkdir IMAPdir
			chmod 700 IMAPdir
			chown vpopmail:vchkpw IMAPdir
		fi
		
		# Enter the IMAPdir
		cd IMAPdir
		# Check if INBOX is a symlink
		if [ ! -L INBOX ]; then
			# Check if INBOX is a directory
			if [ -d INBOX ]; then
				rm -rf INBOX
			fi
			# Create the proper symlink
			ln -s ../Maildir INBOX
		fi
		cd ..
		
		# Create spamassassin directory
		if [ ! -d .spamassassin ]; then
			mkdir .spamassassin
			chmod 700 .spamassassin
			chown vpopmail:vchkpw .spamassassin
		fi
		cd $i
	done
done
cd $OLDPWD
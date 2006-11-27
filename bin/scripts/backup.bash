#!/usr/local/bin/bash

# This file REQUIRES bash, and can not be run under /bin/sh!

###
 # Copyright 2006 Bert JW Regeer. All rights  reserved.
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
###

for HOMEDIR in `/usr/bin/find /usr/home -type d -maxdepth 1 | grep -v '^.$'`; do
	if [ -f $HOMEDIR/.exclude ]; then
		echo "Exclude found for $HOMEDIR"
		while read line; do
			if [ "${line:0:1}" != "/" ]; then
				# They are missing a full path, we will be nice and add it
				TMPLINE="$HOMEDIR/$line"
				line=$TMPLINE
			fi
			echo "	Excluding $line"
			echo $line >> /tmp/exclude.$$
		done < $HOMEDIR/.exclude
	fi
done

mount | grep /backup

if [ $? -ne 0 ]; then
	/sbin/mount /backup
	if [ $? -ne 0 ]; then
		logger -s -p user.err -t backup "Backup drive could not be mounted! Bailing!"
		/sbin/umount -f /backup
		exit 1
	fi
fi

BACKUPDIR="/backup/`date "+%Y-%m-%d"`"
OLDDIR="/backup/`date -v-14d "+%Y-%m-%d"`"

if [ ! -d $BACKUPDIR ]; then
	mkdir $BACKUPDIR
fi

if [ $? -ne 0 ]; then
	logger -s -p user.err -t backup "Could not create backup folder $BACKUPDIR. Bailing!"
	/sbin/umount -f /backup
	exit 1
fi

# We got this far, now we have to run rsync. Rsync is very verbose on purpose

/usr/local/bin/rsync -av --relative --delete /usr/home/ $BACKUPDIR --exclude-from=/tmp/exclude.$$

EXITCODE=$?

if [ $EXITCODE -ne 0 ]; then
	if [ $EXITCODE -ne 24 ]; then
		logger -s -p user.err -t backup "rsync failed. Do not trust backup ($BACKUPDIR)"
		/sbin/umount /backup
		exit 1
	fi
fi


echo "Backup complete! Deleting oldest backup (14 days ago)"

if [ -d $OLDDIR ]; then
	rm -rf $OLDDIR
fi

/sbin/umount /backup
/bin/rm -f /tmp/exclude.$$

logger -s -p user.notice -t backup "Backup complete at $BACKUPDIR."
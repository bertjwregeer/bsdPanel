# Copyright X-Istence.com
# Author:
#
# Jan-Willem Regeer (bsdpanel-scripts@x-istence.com)

#Path to the source directory.
SRCDIR=/usr/src
#Path to cgi-bin directory.
CGIBIN=/www/cgi-bin
#Do not change anything below!
PROG=	changepass
SRCS=	changepass.cpp pw_scan.c
BINOWN=root
BINMODE=4555
WARNS?= 4
NO_WERROR=yes
.PATH:	${SRCDIR}/usr.sbin/pwd_mkdb ${SRCDIR}/lib/libc/gen
CFLAGS+=-I${SRCDIR}/usr.sbin/pwd_mkdb -I${SRCDIR}/lib/libc/gen
CFLAGS+=-DYP -I.

DPADD=  ${LIBCRYPT} ${LIBUTIL}
LDADD+= -lcrypt -lutil

.include <bsd.prog.mk>


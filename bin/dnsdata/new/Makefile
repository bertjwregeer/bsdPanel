CXX = g++			# Our compiler
CXXFLAGS = -c		# Compilation
SRC_FILES = Exception.cc \
            Net_Address.cc \
            Net_IpAddress.cc \
            Net_IpAddressException.cc

clean:
	-rm *.o *~ .depend

depend:
	mkdep ${CXXFLAGS} ${SRC_FILES}

test:
	@echo Making Test Applications




# Dependencies
Dns_Record.o Net_Address.o : Math.o
Dns_CName.o Dns_Host.o Dns_NameServer.o Dns_Text.o : Dns_Record.o
Dns_Address.o Dns_Alias.o Dns_MailExchange.o : Dns_Host.o

Net_IpAddress.o Net_DomainName.o : Net_Address.o

Net_IpAddressException.o Net_DomainNameException.o : Exception.o
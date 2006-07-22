# Makefile for dns module of bsdPanel
# 
# Written by: Geoffrey Garside <ggarside@geffy.co.uk>

all: exceptions net dns

exceptions:
	@echo building exceptions

net: net_address net_ipaddress net_domainname
	@echo building net space

net_address:
	@echo building address

net_ipaddress:
	@echo building ipaddress

net_domainname:
	@echo building domainname

dns: dns_zone
	@echo building dns space

dns_zone: dns_record dns_host dns_nameserver dns_cname dns_text
	@echo building $@

dns_record:
	@echo building record

dns_host: dns_address dns_alias dns_mailexchange
	@echo building host

dns_address:
	@echo building address

dns_alias:
	@echo building alias

dns_mailexchange:
	@echo building mailexchange

dns_nameserver: dns_startofauth
	@echo building nameserver

dns_startofauth:
	@echo building startorauthority

dns_cname:
	@echo building cname

dns_text:
	@echo building text

clean:
	@echo cleaning


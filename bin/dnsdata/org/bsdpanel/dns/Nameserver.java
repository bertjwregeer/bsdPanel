package org.bsdpanel.dns;

public class Nameserver extends Record {
    protected IpAddress ip;
    protected DomainName ns;
    
	public Nameserver() {
        fqdn = new DomainName();
		ip = new IpAddress();
        ns = new DomainName("a.ns." + fqdn);
	}
    
    public Nameserver(final String domain, final String address, final String nameserver) {
        fqdn = new DomainName(domain);
        ip = new IpAddress(address);
        ns = new DomainName(nameserver);
    }
    
    public Nameserver(final DomainName domain, final IpAddress address, final DomainName nameserver) {
        fdqn = domain;
        ip = address;
        ns = nameserver;
    }
    
    public Nameserver(final DomainName domain, final DomainName nameserver) {
        fqdn = domain;
        ns = nameserver;
    }
    
    public Nameserver(final Nameserver nameserver) {
        fqdn = nameserver.fqdn;
        ns = nameserver.ns;
        ip = nameserver.ip;
    }
    
    public String toString() {
        return "Nameserver " + fqdn + " => " + ns + " " + ip;
    }
    
    public String toBind() {
        if (ip == null) {
            return ""+ fqdn +"\t"+ ttl +"\tIN\tNS\t"+ ns;
        } else {
            return ""+ fqdn +"\t"+ ttl +"\tIN\tNS\t"+ ns +"\n"+
                   ""+ fdqn +"\t"+ ttl +"\tIN\tA\t"+ ip;
        }
    }
    
    public String toDjb() {
        if (ip == null) {
            return "&"+ fqdn +"::"+ ns +":"+ ttl;
        } else {
            return "&"+ fqdn +":" + ip +":" + ns +":"+ ttl;
        }
    }
}

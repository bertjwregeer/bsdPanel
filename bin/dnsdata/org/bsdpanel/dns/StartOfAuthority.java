public class StartOfAuthority extends Nameserver {
    protected String soaAdmin;
    public StartOfAuthority() {
        super();
        soaAdmin = "admin."+ domain;
    }
    
    public StartOfAuthority(final String domain, final String address, final String nameserver) {
        super(domain, address, nameserver);
        soaAdmin = "admin."+ fqdn;
    }
    
    public StartOfAuthority(final String domain, final String address, final String nameserver, final String admin) {
        super(domain, address, nameserver);
        soaAdmin = admin + "."+ fqdn;
    }
    
    public StartOfAuthority(final StartOfAuthority soa) {
        fqdn = soa.fqdn;
        ip = soa.ip;
        ns = soa.ns;
        soaAdmin = soa.soaAdmin;
    }
    
    public String toBind() {
        StringBuffer output = new StringBuffer();
        output.append(fqdn +"\tIN\SOA\t"+ 
    }
    
    public String toDjb() {
        if (ip == null) {
            return "."+ fqdn +"::"+ ns +":"+ ttl;
        } else {
            return "."+ fqdn +":" + ip +":" + ns +":"+ ttl;
        }
    }
}
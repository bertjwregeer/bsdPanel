/**
 * The Start of Authority is a required piece of the DNS specification
 * 
 *
 *
 *
 *
 */

package org.bsdpanel.dns;

public class StartOfAuthority extends Nameserver {
    protected String soaAdmin;
    
    protected String serverSerial;
    protected String serverRefresh;
    protected String serverRetry;
    protected String serverExpire;
    protected String serverCache;
    
    public StartOfAuthority() {
        super();
        soaAdmin = "hostmaster."+ fqdn;
    }
    
    public StartOfAuthority(final String domain, final String address, final String nameserver) {
        super(domain, address, nameserver);
        soaAdmin = "hostmaster."+ fqdn;
    }
    
    public StartOfAuthority(final String domain, final String address, final String nameserver, final String admin) {
        super(domain, address, nameserver);
        soaAdmin = admin +"."+ fqdn;
    }
    
    public StartOfAuthority(final StartOfAuthority soa) {
        fqdn = soa.fqdn;
        ip = soa.ip;
        ns = soa.ns;
        soaAdmin = soa.soaAdmin;
    }
    
    public String toBind() {
        StringBuffer output = new StringBuffer();
        output.append(fqdn +"\tIN\tSOA\t"+ fqdn +".\t"+ soaAdmin +".\t(\n");
        output.append("\t\t\t\t\t"+ serverSerial +"\n");
        output.append("\t\t\t\t\t"+ serverRefresh +"\n");
        output.append("\t\t\t\t\t"+ serverRetry +"\n");
        output.append("\t\t\t\t\t"+ serverExpire +"\n");
        output.append("\t\t\t\t\t"+ serverCache +")\n");
        
        return output.toString();
    }
    
    public String toDjb() {
        if (ip == null) {
            return "."+ fqdn +"::"+ ns +":"+ ttl;
        } else {
            return "."+ fqdn +":" + ip +":" + ns +":"+ ttl;
        }
    }
}

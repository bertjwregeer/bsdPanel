public class Subdomain extends DomainName {
    protected String subdomain;
    public Subdomain() {
        subdomain = "";
    }
    
    public Subdomain(final String sub) throws DomainNameException {
        try {
            sub = checkAddress(sub);
            subdomain = sub;
        } catch (DomainNameException e) {
            subdomain = "";
        }
    }
    
    public Subdomain(final Subdomain sub) {
        subdomain = sub.subdomain;
    }
    
    public static boolean isValid(final String address) {
        try {
            address = checkAddress(address);
            return true;
        } catch (DomainNameException e) {
            return false;
        }
    }
    
    public String toString() {
        return subdomain;
    }
    
    protected String checkAddress(String address) throws DomainNameException {
        if (!super.isValid(address)) {
            // ok, we dont have something which ends in a tld
            // now we need to check to see if its still valid ;)
            return address;
        } else {
            throw DomainNameException();
        }
    }
}

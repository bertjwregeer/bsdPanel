/**
 * DNS Zone Class
 * This represents a DNS zone which in itself
 * is a collection of DNS records
 * This class requires that certain Zone components
 * are present so that a zone can be properly created.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 1.0
 * @copyright 2005
 * @license http://bsdpanel.org/license
 */

package org.bsdpanel.dns;


public class Zone {
	protected Nameserver primary;
	protected Nameserver secondary;
	
	protected Host domain;
	protected Alias www;
	
	protected LinkedList records;	// this list will store additional records of type A, MX, CNAME and TXT
	
	protected MailExchange mx;
	
	protected int TTL;
	
	// BiND Zone Components
	// Export to a BiNDZone class
	//private Maintainer maintainer;
	
	public Zone() {
		TTL = 86400;
	}
	
	public Zone(final Nameserver pPrimary, final Nameserver pSecondary) {
		primary = pPrimary;
		secondary = pSecondary;
		
		TTL = 86400;
	}
	
	public Zone(final Nameserver pPrimary, final Nameserver pSecondary, final String name) {
		this(pPrimary, pSecondary);
		
		name = checkName(name);
		
		createDefaults(name);
		
		TTL = 86400;
	}
	
	public Zone(final Nameserver pPrimary, final Nameserver pSecondary, final Host pDomain) {
		primary = pPrimary;
		secondary = pSecondary;
		
		domain = pDomain;
		www = domain.alias();
		mx = domain.mailExchange();
		
		TTL = 86400;
	}
	
	public Zone(final Nameserver pPrimary, final Nameserver pSecondary, final Host pDomain, final Alias pWww, final MailExchange pMx) {
		primary = pPrimary;
		secondary = pSecondary;
		domain = pDomain;
		www = pWww;
		mx = pMx;
		
		TTL = 86400;
	}
	
	protected String checkName(final String pName) {
		// some sort of regular expression here to look for
		// three www's and a dot at the beginning and a 
		// trailing slash at the end. We dont want those.
		// So we will remove them. We could check the tld
		// as well, but its probably not worth it.
	}
	
	protected void createDefaults(final String name) {
		domain = new Host(name);
		www = domain.alias();
		mx = domain.mailExchange();
	}
}

/************************************************************
 *  bsdPanel DNS Nameserver section
 *  djbDNS Entry Class
 * 
 *  Author: StealthNinja
 *  eMail: coder@stealth-ninja.co.uk
 ************************************************************
 * The classType is a single character representation of the 
 * different classes of DNS entries. Mapped in djbdns as
 * "." produces an A, NS and SOA record (Authorative Nameserver)
 * "&" produces an A and an NS record
 * "=" produces an A and a PTR record, creating forward and
 *	reverse DNS entries
 * "+" produces an A record with no PTR for rDNS
 * "@" produces an MX and an A record for a MailExchanger
 * "C" produces a CNAME for point a name at another name
 ************************************************************/

import java.util.StringTokenizer;

public class DNSEntry implements Comparable {
    private static int iEntries = 0;	/* So we can keep track of the number of DNS Entries we have */
    private static final String sep = ":";	/* djbdns separator */
    
    private char classType;			/* See notes above on values stored */
    private String fqdn;			/* fqdn - Fully Qualified Domain Name */
    private String ip;			/* IP Address */
    private String x;			/* x is sometimes required for certain records */
    private int dist;			/* default distance for MX Records */
    private int ttl;			/* Time to Live of the DNS record */
    private String timestamp;		/* Used in some cases to allow for domain mapping change overs */
    private String lo;			/* Client Location */
    private String comment;			/* to allow for a commented data file */
    
    public DNSEntry() {
        // set the classType to a # so only a comment is produced for output
        // even if the data is written with the classType of # it will be 
        // ignored by djbdns as a comment
        classType = '#';
        comment = "Empty Construction";
    }
	
    public DNSEntry(final String pDNSEntry) {
        final char tChar = pDNSEntry.charAt(0);
        switch(tChar) {
            case '.': constructNS(pDNSEntry); break;
            case '&': constructNS(pDNSEntry); break;
            case '=': constructHost(pDNSEntry); break;
            case '+': constructHost(pDNSEntry); break;
            case 'C': constructHost(pDNSEntry); break;
            case '@': constructMX(pDNSEntry); break;
            case '#': constructComment(pDNSEntry); break;
        }

        iEntries++;
    }
	
    // Constructor SubFunctions
    private void constructNS(final String pNSEntry) {
        StringTokenizer tToken = new StringTokenizer(pNSEntry, sep);
        String part = tToken.nextToken();
        classType = part.charAt(0);
        fqdn = part.substring(1);
        ip = tToken.nextToken();
        x = tToken.nextToken();

        // optional so these sections might not be there
        if (tToken.hasMoreTokens()) {
            String tTTLString = tToken.nextToken();
            if (tTTLString.compareTo("") != 0)
                ttl = Integer.parseInt(tTTLString);
        }
            if (tToken.hasMoreTokens())
                timestamp = tToken.nextToken();
            if (tToken.hasMoreTokens())
                lo = tToken.nextToken();
    }
    
    private void constructHost(final String pHostEntry) {
        StringTokenizer tToken = new StringTokenizer(pHostEntry, sep);
        String part = tToken.nextToken();
        classType = part.charAt(0);
        fqdn = part.substring(1);
        ip = tToken.nextToken();
        
        // optional so these sections might not be there
        if (tToken.hasMoreTokens()) {
            String tTTLString = tToken.nextToken();
            if (tTTLString.compareTo("") != 0)
                ttl = Integer.parseInt(tTTLString);
        }
        if (tToken.hasMoreTokens())
            timestamp = tToken.nextToken();
        if (tToken.hasMoreTokens())
            lo = tToken.nextToken();
    }

    private void constructMX(final String pMXEntry) {
        StringTokenizer tToken = new StringTokenizer(pMXEntry, sep);
        String part = tToken.nextToken();
        classType = part.charAt(0);
        fqdn = part.substring(1);
        ip = tToken.nextToken();
        x = tToken.nextToken();

        // optional so these sections might not be there
        if (tToken.hasMoreTokens()) {
            String tDistString = tToken.nextToken();
            if (tDistString.compareTo("") != 0)
                dist = Integer.parseInt(tDistString);
            }
            if (tToken.hasMoreTokens()) {
                String tTTLString = tToken.nextToken();
                if (tTTLString.compareTo("") != 0)
                    ttl = Integer.parseInt(tTTLString);
            }
            if (tToken.hasMoreTokens())
                timestamp = tToken.nextToken();
            if (tToken.hasMoreTokens())
                lo = tToken.nextToken();
    }
    
    private void constructComment(final String pComment) {
        classType = pComment.charAt(0);
        comment = pComment.substring(1).trim();
    }
    
    // Get and Set Methods for fields
    public static int getEntries() {
        return iEntries;
    }
    
    public char classType() {
        return classType;
    }
    public String fqdn() {
        return fqdn;
    }
    public String ip() {
        return ip;
    }
    public String x() {
        return x;
    }
    public int dist() {
        return dist;
    }
    public int ttl() {
        return ttl;
    }
    public String timestamp() {
        return timestamp;
    }
    public String lo() {
        return lo;
    }
    public String comment() {
        return comment;
    }
    public static String delimiter() {
        return sep;
    }

    public void set_classType(final char pClassType) {
classType = pClassType;
}
public void set_fqdn(final String pFQDN) {
	fqdn = pFQDN;
}
public void set_ip(final String pIP) {
	ip = pIP;
}
public void set_x(final String pX) {
	x = pX;
}
public void set_dist(final int pDist) {
	dist = pDist;
}
public void set_ttl(final int pTTL) {
	ttl = pTTL;
}
public void set_timestamp(final String pTimestamp) {
	timestamp = pTimestamp;
}
public void set_lo(final String pLO) {
	lo = pLO;
}

public void set_comment(final String pComment) {
	comment = pComment;
}

// toString output method, outputs into the same format the djbdns data text file
public String toString() {
	String tOutput;
	switch(classType) {
		case '.': tOutput = nsString(); break;
		case '&': tOutput = nsString(); break;
		case '=': tOutput = hostString(); break;
		case '+': tOutput = hostString(); break;
		case 'C': tOutput = hostString(); break;
		case '@': tOutput = mxString(); break;
		case '#': tOutput = commentString(); break;
		default: tOutput = "#malformed class instance"; break;	/* return an undamaging comment */
	}
	return tOutput;
}

// toString SubFunctions
private String nsString() {
    // Primary NS 		.fqdn:ip:x:ttl:timestamp:lo
    // Secondary NS 	&fqdn:ip:x:ttl:timestamp:lo
    
    StringBuffer tOut = new StringBuffer("" + classType + fqdn + sep + ip + sep + x + sep);
    // remaining to conditionally be included to the string
    //+ sep + ttl + sep + timestamp + sep + lo
    if (ttl != 0)
        tOut.append(ttl + sep);
    else
        tOut.append(sep);
    
    if (timestamp != null)
        tOut.append(timestamp + sep);
    else
        tOut.append(sep);
    
    if (lo != null)
        tOut.append(lo);
    
    while (tOut.charAt(tOut.length() - 1) == ':') {
        tOut.deleteCharAt(tOut.length() - 1);
    }
    return tOut.toString();
}

private String hostString() {
    // Host to IP		=fqdn:ip:ttl:timestamp:lo
    // Alias to Host	+fqdn:ip:ttl:timestamp:lo
    // CNAME		Cfqdn:p:ttl:timestamp:lo
    StringBuffer tOut = new StringBuffer("" + classType + fqdn + sep + ip + sep);
    if (ttl != 0)
        tOut.append(ttl + sep);
    else
        tOut.append(sep);
    
    if (timestamp != null)
        tOut.append(timestamp + sep);
    else
        tOut.append(sep);
    
    if (lo != null)
        tOut.append(lo);
    
    while (tOut.charAt(tOut.length() - 1) == ':') {
        tOut.deleteCharAt(tOut.length() - 1);
    }
    
    return tOut.toString();
}

    private String mxString() {
        // Mail Exchange	@fqdn:ip:x:dist:ttl:timestamp:lo
        StringBuffer tOut = new StringBuffer("" + classType + fqdn + sep + ip + sep + x + sep); // + dist + sep + ttl + sep + timestamp + sep + lo);
        if (dist != 0)
            tOut.append(dist + sep);
        else
            tOut.append(sep);
       
        if (ttl != 0)
            tOut.append(ttl + sep);
        else
            tOut.append(sep);
        
        if (timestamp != null)
            tOut.append(timestamp + sep);
        else
            tOut.append(sep);
        
        if (lo != null)
            tOut.append(lo);
            while (tOut.charAt(tOut.length() - 1) == ':') {
            tOut.deleteCharAt(tOut.length() - 1);
        }
                
        return tOut.toString();
    }

    private String commentString() {
        return "" + classType + " " + comment;
    }

    public int hashCode() {
        return classType;
    }
        
    public int compareTo(final Object pObject) {
        if (pObject == null || getClass() != pObject.getClass()) {
            return -1;
        }
        
        DNSEntry pEntry = (DNSEntry) pObject;
        return compareTo(pEntry);
    }

    public int compareTo(final DNSEntry pEntry) {
        if (classType == pEntry.classType() && fqdn.equals(pEntry.fqdn()) && ip.equals(pEntry.ip())) {
            return 0;
        } else {
            return 1;
        }
    }
}
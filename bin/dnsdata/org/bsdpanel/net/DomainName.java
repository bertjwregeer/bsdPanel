public class DomainName extends Address {
	private String name;
	private String[] countryCode = {"ac", "ad", "ae", "af", "ag", "ai", "al", 
									"am", "an", "ao", "aq", "ar", "as", "at", 
									"au", "aw", "ax", "az", "ba", "bb", "bd", 
									"be", "bf", "bg", "bh", "bi", "bj", "bm", 
									"bn", "bo", "br", "bs", "bt", "bv", "bw", 
									"by", "bz", "ca", "cc", "cd", "cf", "cg", 
									"ch", "ci", "ck", "cl", "cm", "cn", "co", 
									"cr", "cs", "cu", "cv", "cx", "cy", "cz", 
									"de", "dj", "dk", "dm", "do", "dz", "ec", 
									"ee", "eg", "eh", "er", "es", "et", "fi", 
									"fj", "fk", "fm", "fo", "fr", "ga", "gb", 
									"gd", "ge", "gf", "gg", "gh", "gi", "gl", 
									"gm", "gn", "gp", "gq", "gr", "gs", "gt", 
									"gu", "gw", "gy", "hk", "hm", "hn", "hr", 
									"ht", "hu", "id", "ie", "il", "im", "in", 
									"io", "iq", "ir", "is", "it", "je", "jm", 
									"jo", "jp", "ke", "kg", "kh", "ki", "km", 
									"kn", "kp", "kr", "kw", "ky", "kz", "la", 
									"lb", "lc", "li", "lk", "lr", "ls", "lt", 
									"lu", "lv", "ly", "ma", "mc", "md", "mg", 
									"mh", "mk", "ml", "mm", "mn", "mo", "mp", 
									"mq", "mr", "ms", "mt", "mu", "mv", "mw", 
									"mx", "my", "mz", "na", "nc", "ne", "nf", 
									"ng", "ni", "nl", "no", "np", "nr", "nu", 
									"nz", "om", "pa", "pe", "pf", "pg", "ph", 
									"pk", "pl", "pm", "pn", "pr", "ps", "pt", 
									"pw", "py", "qa", "re", "ro", "ru", "rw", 
									"sa", "sb", "sc", "sd", "se", "sg", "sh", 
									"si", "sj", "sk", "sl", "sm", "sn", "so", 
									"sr", "st", "sv", "sy", "sz", "tc", "td", 
									"tf", "tg", "th", "tj", "tk", "tl", "tm", 
									"tn", "to", "tp", "tr", "tt", "tv", "tw", 
									"tz", "ua", "ug", "uk", "um", "us", "uy", 
									"uz", "va", "vc", "ve", "vg", "vi", "vn", 
									"vu", "wf", "ws", "ye", "yt", "yu", "za", 
									"zm", "zw" };
	private String globalCode = { "com", "net", "org", "edu" };
	private String newNameCode = { "name", "info" };

	
	public DomainName() {
		name = "example.com";
	}
	
	public DomainName(final String pName) {
		try {
			pName = checkAddress(pName);
		} catch (DomainNameException e) {
			pName = "example.com";
		}
		
		name = pName;
	}
	
	public DomainName(DomainName pName) {
		name = pName.name;
	}
	
	public String toString() {
		return name + ".";
	}
    
    public static boolean isValid(final String address) {
        try {
            address = checkAddress(address);
            return true;
        } catch (DomainNameException e) {
            return false;
        }
    }
	
	protected String checkAddress(final String address) throws AddressException {
		String parts[] = address.split(delimiter);
		boolean valid = false;
		
		if (parts[parts.length - 1].length() == 2) {
			// we have a ccTLD, if its not then its a .tv address
			for (int i = 0; i < countryCode.length; i++) {
				if (countryCode[i].equals(parts[parts.length - 1])) {
					// the country code is alright
					valid = true;
				} else if (parts[parts.length - 1].equals("tv")) {
					// we have a .tv domain
					valid = true;
				}
			}
		} else if (parts[parts.length - 1].length() == 3) {
			// we have a gTLD
			for (int i = 0; i < globalCode.length; i++) {
				if (globalCode[i].equals(parts[parts.length - 1])) {
					// we have a valid gTLD domain
					valid = true;
				}
			}
		} else if (parts[parts.length - 1].length() == 4) {
			// got one of them new name thingers
			for (int i = 0; i < newNameCode.length; i++) {
				if (newNameCode[i].equals(parts[parts.length - 1])) {
					// we have a valid new.net name
					valid = true;
				}
			}
		}
		
		if (valid) {
			return address;
		} else {
			throw InvalidDomainException();
		}
	}
}
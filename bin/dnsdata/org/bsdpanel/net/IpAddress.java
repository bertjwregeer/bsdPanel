public class IpAddress extends Address {
	private int[] octet;
	private final String local = "127.0.0.1";
	
	public IpAddress() {
		 storeAddress(local);
	}
	
	public IpAddress(String ip) {
		ip.trim();
		
		try {
			ip = checkAddress(ip);
		} catch (IpAddressException e) {
			ip = local;
		}
		
		storeAddress(ip);
	}
	
	public IpAddress(IpAddress address) {
		octet = address.octet;
	}
	
	public String toString() {
		StringBuffer output = new StringBuffer();
		for (int i = 0; i < octet.length; i++) {
			output.append(octet[i]);
		}
		
		return output;
	}
    
    public static boolean isValid(final String address) {
        try {
            address = checkAddress(address);
            return true;
        } catch (IpAddressException e) {
            return false;
        }
    }
	
	private void storeAddress(final String address) {
		String parts[] = address.split(delimiter);
		
		for (int i = 0; i < parts.length; i++) {
			octet[i] = Integer.parseInt(parts[i]);
		}
	}
	
	protected String checkAddress(final String address) throws AddressException {
		String parts[] = address.split(delimiter);
		boolean valid = false;
		
		// Check to make sure the address has the right number of parts
		if (parts.length == 4) {
			// Check to make sure the octet parts are actually integers
			for (int i = 0; i < parts.length; i++) {
				if (isInt(parts[i])) {
					valid = true;
				} else {
					valid = false;
				}
			}
		}
		
		if (valid) {
			return address;
		} else {
			throw InvalidIpAddressException();
		}
	}
	
	private boolean isInt(final String integer) {
		int number;
		try {
			number = Integer.parseInt(integer);
			return true;
		} catch (Exception e) {
			return false;
		}
	}
}

package org.bsdpanel.net;

public abstract class Address {
	protected final String delimiter ".";
	
	protected abstract String checkAddress(final String address) throws InvalidAddressException;
	public abstract String toString();
    public abstract static boolean isValid(final String address);
}

package org.bsdpanel.dns;

public class Text extends Record {
	protected String contents;
	public Text() {
		contents = "";
	}
    
    public Text(final String text) {
        contents = text;
    }
    
    public Text(final Text text) {
        contents = text.contents;
    }
    
    public String toString() {
        return contents;
    }
    
    public String toBind() {
        return "" + fqdn.toString() + "\tIN TXT \"" + contents + "\"";
    }
    
    public String toDjb() {
        return "";
    }
}

public abstract class Record {
	protected DomainName fqdn;
    protected int ttl = 14400;
	
	public abstract String toString();
    public abstract String toBind();
    public abstract String toDjb();
}
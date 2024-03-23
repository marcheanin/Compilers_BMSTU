public class Token {
    public final DomainTag tag;
    public final Fragment coords;

    public String value;

    protected Token(DomainTag tag, String value, Position starting, Position following) {
        this.tag = tag;
        this.value = value;
        this.coords = new Fragment(starting, following);
    }

    @Override
    public String toString() {
        if (tag == DomainTag.STR_LITERAL) {
            value = value.substring(1, value.length() - 1);
            value = value.replaceAll("::", ":");
        }
        if (tag.name().contains("IDENT"))
            return "IDENT" + " " + coords.toString() + ": " + value;
        else
            return tag.name() + " " + coords.toString() + ": " + value;
    }
}

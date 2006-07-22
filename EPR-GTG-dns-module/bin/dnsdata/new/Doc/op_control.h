namespace bsdPanel
{
    namespace Dns
    {
        enum OPCODE
        {
            MASTER,
            SLAVE,
            NEW,
            LOAD,
            DELETE,
            ADD,
            OK,
            QUIT,
            COMMIT
        };
        
        enum OPTYPE
        {
            A,
            NS,
            SOA,
            MX,
            TXT,
            CNAME
        };
    }
}
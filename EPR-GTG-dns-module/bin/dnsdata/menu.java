/************************************************************
 *  bsdPanel DNS Nameserver section
 *  djbDNS data manipulation client menus
 * 
 *  Author: StealthNinja
 *  eMail: coder@stealth-ninja.co.uk
 *
 *  $Id$
 ************************************************************/

public class menu {
    public static void start() {
        System.out.println("Main Menu");
        System.out.println("[1] Add DNS Entry");
        System.out.println("[2] Del DNS Entry");
        System.out.println("[3] Show Entries");
        System.out.println("[4] Save Entries");
        System.out.println("[9] Exit");
        System.out.print("::> ");
        System.out.flush();
    }
    
    public static void addDNS() {
        System.out.println("Add a DNS Entry Menu");
        System.out.println("[1] Add SOA NS Entry");
        System.out.println("[2] Add NS Entry");
        System.out.println("[3] Add Host Entry");
        System.out.println("[4] Add Host Alias");
        System.out.println("[5] Add CNAME Entry");
        System.out.println("[6] Add MX Entry");
        System.out.println("[9] back");
        System.out.print("::> ");
        System.out.flush();
    }
    
    public static void delDNS() {
        System.out.println("Remove a DNS Entry Menu");
        System.out.println("[1] Del SOA NS Entry");
        System.out.println("[2] Del NS Entry");
        System.out.println("[3] Del Host Entry");
        System.out.println("[4] Del Host Alias");
        System.out.println("[5] Del CNAME Entry");
        System.out.println("[6] Del MX Entry");
        System.out.println("[9] back");
        System.out.print("::> ");
        System.out.flush();
    }
    
    public static void showDNS() {
        System.out.println("Show DNS Entry Menu");
        System.out.println("This shows the DNS Entries\nas they would appear in\nthe data file");
        System.out.println("[1] Show All Entries");
        System.out.println("[2] Show SOA NS Entry");
        System.out.println("[3] Show NS Entry");
        System.out.println("[4] Show Host Entry");
        System.out.println("[5] Show Host Alias");
        System.out.println("[6] Show CNAME Entry");
        System.out.println("[7] Show MX Entry");
        System.out.println("[9] back");
        System.out.print("::> ");
        System.out.flush();
    }
}

/************************************************************
 *  bsdPanel DNS Nameserver section
 *  djbDNS Entry Class Demo Client
 * 
 *  Author: StealthNinja
 *  eMail: coder@stealth-ninja.co.uk
 ************************************************************/

import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.File;
import java.util.StringTokenizer;
import java.util.Set;
import java.util.TreeSet;
import java.util.Iterator;

public class dnsdata {
    private static BufferedReader iKeyboard
        = new BufferedReader(new InputStreamReader(System.in));
    private static int exit = 0;
    
    // storage vars
    private static String iFile;        // djbdns data file path from the commandline
    private static Set iDataFile;       // a Set with natural ordering to store the Entries
    
    public static void main(final String[] pArgs) throws IOException {
        // get the main data filename from the commandline
        if (pArgs.length < 1) {
            System.out.println("Usage: dnsdata datafile");
            System.exit(0);
        }
        iFile = pArgs[0];
        File dataFile = new File(iFile);
        if (!(dataFile.exists() && dataFile.isFile() && dataFile.canRead() && dataFile.canWrite())) {
            System.out.println("Data File cannot be found, is not a file, or cannot be read or written to");
            System.out.println("Please check the path and file permissions and try again");
            System.exit(0);
        }
        
        iDataFile = new TreeSet();
        openData();
        
        printHeader();
        
        while (exit == 0) {
            iGetMenuChoice();
        }
    }
    
    private static void iGetMenuChoice() throws IOException {
        String tPath = "0";
        String tLine = "";
        int path = 0;
        
        while(exit == 0) {
            try {
                path = Integer.parseInt(tPath);
            } catch (Exception e) {
                path = 0;
            }
            
            switch(path) {
                default:
                    menu.start();
                    tLine = iKeyboard.readLine();
                    tPath = tLine;
                    break;
                case 1: /* Add DNS */
                    menu.addDNS();
                    tLine = iKeyboard.readLine();
                    tPath = tPath + tLine;
                    break;
                case 2: /* Del DNS */
                    menu.delDNS();
                    tLine = iKeyboard.readLine();
                    tPath = tPath + tLine;
                    break;
                case 3: /* Show DNS */
                    menu.showDNS();
                    tLine = iKeyboard.readLine();
                    tPath = tPath + tLine;
                    break;
                case 4: /* Write out Data File */
                    System.out.print("\nWriting Data... ");
                    saveData();
                    System.out.println("done");
                    tPath = "0";
                    break;
                case 9: /* exit */
                    saveData();
                    exit = 1;
                    break;
                case 11: /* Add SOA NS Entry */
                    createNS('.');
                    tPath = "1";
                    break;
                case 12: /* Add NS Entry */
                    createNS('&');
                    tPath = "1";
                    break;
                case 13: /* Add Host Entry */
                    createHost('=');
                    tPath = "1";
                    break;
                case 14: /* Add Host Alias */
                    createHost('+');
                    tPath = "1";
                    break;
                case 15: /* Add CNAME Entry */
                    createHost('C');
                    tPath = "1";
                    break;
                case 16: /* Add MX Entry */
                    createMX();
                    tPath = "1";
                    break;
                case 19: /* back to main */
                    tPath = "0";
                    break;
                case 21: /* Del SOA NS Entry */
                    removeEntry('.');
                    tPath = "2";
                    break;
                case 22: /* Del NS Entry */
                    removeEntry('&');
                    tPath = "2";
                    break;
                case 23: /* Del Host Entry */
                    removeEntry('=');
                    tPath = "2";
                    break;
                case 24: /* Del Host Alias */
                    removeEntry('+');
                    tPath = "2";
                    break;
                case 25: /* Del CNAME Entry */
                    removeEntry('C');
                    tPath = "2";
                    break;
                case 26: /* Del MX Entry */
                    removeEntry('@');
                    tPath = "2";
                    break;
                case 29: /* back to main */
                    tPath = "0";
                    break;
                case 31: /* Show All */
                    showDNSRecords();
                    tPath = "3";
                    break;
                case 32: /* Show SOA NS Entry */
                    showDNSRecords('.');
                    tPath = "3";
                    break;
                case 33: /* Show NS Entry */
                    showDNSRecords('&');
                    tPath = "3";
                    break;
                case 34: /* Show Host Entry */
                    showDNSRecords('=');
                    tPath = "3";
                    break;
                case 35: /* Show Host Alias */
                    showDNSRecords('+');
                    tPath = "3";
                    break;
                case 36: /* Show CNAME Entry */
                    showDNSRecords('C');
                    tPath = "3";
                    break;
                case 37: /* Show MX Entry */
                    showDNSRecords('@');
                    tPath = "3";
                    break;
                case 39: /* back to main */
                    tPath = "0";
                    break;
            }
        }
    }
    
    private static void showDNSRecords() {
        // just call the function which takes a parameter for each now
        System.out.println("# djbdns data file");
        System.out.println("# DNS Record Entries");
        showDNSRecords('.');
        showDNSRecords('&');
        showDNSRecords('=');
        showDNSRecords('+');
        showDNSRecords('C');
        showDNSRecords('@');
    }
    
    private static void showDNSRecords(final char type) {
        switch (type) {
            case '.': /* Print SOA NS Records */
                System.out.println("# SOA NS Records");
                break;
            case '&': /* Print non-SOA NS Records */
                System.out.println("# non SOA NS Records");
                break;
            case '=': /* Print Host Records */
                System.out.println("# Host Records");
                break;
            case '+': /* Print Alias Records */
                System.out.println("# Aliases");
                break;
            case 'C': /* Print CNAME Records */
                System.out.println("# CNAME Entries");
                break;
            case '@': /* Print MX Records */
                System.out.println("# MX Records");
                break;
        }
        
        final Iterator iterator = iDataFile.iterator();
        while (iterator.hasNext()) {
            DNSEntry entry = (DNSEntry)iterator.next();
            if (entry.toString().charAt(0) == type) {
                System.out.println(entry);
            }
        }
    }
    
    private static void openData() throws IOException {
        final BufferedReader inputHandle = new BufferedReader(new FileReader(iFile));
        
        while(true) {
            final String fileEntry = inputHandle.readLine();
            if (fileEntry == null)
                break;
            if (fileEntry.length() > 0 && fileEntry.charAt(0) != '#') {
                DNSEntry newEntry = new DNSEntry(fileEntry);
                iDataFile.add(newEntry);
            }
        }
        
        inputHandle.close();
    }
    
    private static void saveData() throws IOException {
        final PrintWriter outputHandle = new PrintWriter(new BufferedWriter(new FileWriter(iFile)));
        final Iterator iterator = iDataFile.iterator();
        
        outputHandle.println("# djbdns data file");
        outputHandle.println("# DNS Record Entries");
        
        outputHandle.println("# SOA NS Records");
        outputHandle.println(printDNSRecords('.'));
        
        outputHandle.println("# non SOA NS Records");
        outputHandle.println(printDNSRecords('&'));
        
        outputHandle.println("# Host Records");
        outputHandle.println(printDNSRecords('='));
        
        outputHandle.println("# Aliases");
        outputHandle.println(printDNSRecords('+'));
        
        outputHandle.println("# CNAME Entries");
        outputHandle.println(printDNSRecords('C'));
        
        outputHandle.println("# MX Records");
        outputHandle.println(printDNSRecords('@'));
        
        outputHandle.close();
    }

    private static String printDNSRecords(final char type) {
        StringBuffer output = new StringBuffer();
        final Iterator iterator = iDataFile.iterator();
        while (iterator.hasNext()) {
            DNSEntry entry = (DNSEntry)iterator.next();
            if (entry.toString().charAt(0) == type) {
                output.append(entry.toString());
                output.append("\n");
            }
        }
        return output.toString();
    }
    
    private static void createNS(final char type) throws IOException {
        // Primary NS        .fqdn:ip:x:ttl:timestamp:lo
        // Secondary NS      &fqdn:ip:x:ttl:timestamp:lo
        System.out.print("FQDN [example.com]: ");
        System.out.flush();
        final String tFQDN = iKeyboard.readLine();
        System.out.print("IP [xxx.xxx.xxx.xxx]: ");
        System.out.flush();
        final String tIP = iKeyboard.readLine();
        System.out.print("X [a => a.ns.example.com]: ");
        System.out.flush();
        final String tX = iKeyboard.readLine();
        System.out.print("TTL [optional]: ");
        System.out.flush();
        final String tTTL = iKeyboard.readLine();
        System.out.print("TimeStamp [optional]: ");
        System.out.flush();
        final String tTS = iKeyboard.readLine();
        System.out.print("Location [optional]: ");
        System.out.flush();
        final String tLO = iKeyboard.readLine();
        
        // construct string
        StringBuffer entry = new StringBuffer("" + type + tFQDN + ":" + tIP + ":" + 
            tX + ":" + tTTL + ":" + tTS + ":" + tLO);
        while (entry.charAt(entry.length() - 1) == ':') {
            entry.deleteCharAt(entry.length() - 1);
        }
        
        DNSEntry tEntry = new DNSEntry(entry.toString());
        iDataFile.add(tEntry);
    }
    private static void createHost(final char type) throws IOException {
        // Host to IP        =fqdn:ip:ttl:timestamp:lo
        // Alias to Host     +fqdn:ip:ttl:timestamp:lo
        // CNAME             Cfqdn:ip:ttl:timestamp:lo
        System.out.print("FQDN [example.com or sub.example.com]: ");
        System.out.flush();
        final String tFQDN = iKeyboard.readLine();
        if (type == 'C')
            System.out.print("Points to [must be a fqdn]: ");
        else
            System.out.print("IP [xxx.xxx.xxx.xxx]: ");
        System.out.flush();
        final String tIP = iKeyboard.readLine();
        System.out.print("TTL [optional]: ");
        System.out.flush();
        final String tTTL = iKeyboard.readLine();
        System.out.print("TimeStamp [optional]: ");
        System.out.flush();
        final String tTS = iKeyboard.readLine();
        System.out.print("Location [optional]: ");
        System.out.flush();
        final String tLO = iKeyboard.readLine();
        
        // construct string
        StringBuffer entry = new StringBuffer("" + type + tFQDN + ":" + tIP + ":" + 
            tTTL + ":" + tTS + ":" + tLO);
        while (entry.charAt(entry.length() - 1) == ':') {
            entry.deleteCharAt(entry.length() - 1);
        }
        
        DNSEntry tEntry = new DNSEntry(entry.toString());
        iDataFile.add(tEntry);
    }
    private static void createMX() throws IOException {
        // Mail Exchange    @fqdn:ip:x:dist:ttl:timestamp:lo
        System.out.print("FQDN [example.com]: ");
        System.out.flush();
        final String tFQDN = iKeyboard.readLine();
        System.out.print("IP [xxx.xxx.xxx.xxx]: ");
        System.out.flush();
        final String tIP = iKeyboard.readLine();
        System.out.print("X [a => a.mx.example.com]: ");
        System.out.flush();
        final String tX = iKeyboard.readLine();
        System.out.print("Distance [optional]: ");
        System.out.flush();
        final String tDist = iKeyboard.readLine();
        System.out.print("TTL [optional]: ");
        System.out.flush();
        final String tTTL = iKeyboard.readLine();
        System.out.print("TimeStamp [optional]: ");
        System.out.flush();
        final String tTS = iKeyboard.readLine();
        System.out.print("Location [optional]: ");
        System.out.flush();
        final String tLO = iKeyboard.readLine();
        
        // construct string
        StringBuffer entry = new StringBuffer("" + '@' + tFQDN + ":" + tIP + ":" + 
            tX + ":" + tDist + ":" + tTTL + ":" + tTS + ":" + tLO);
        while (entry.charAt(entry.length() - 1) == ':') {
            entry.deleteCharAt(entry.length() - 1);
        }
        
        DNSEntry tEntry = new DNSEntry(entry.toString());
        iDataFile.add(tEntry);
    }
    private static void removeEntry(final char type) throws IOException {
        System.out.println("Existing Records");
        showDNSRecords(type);
        
        System.out.println("Enter the string as shown in the existing list");
        System.out.print("::> ");
        System.out.flush();
        final String match = iKeyboard.readLine();
        
        DNSEntry matchingEntry = new DNSEntry(match);
        iDataFile.remove(matchingEntry);
    }
    
    private static void printHeader() {
        System.out.println("StealthNinja djbDNS Data File Manipulation Client");
        System.out.println("This client demonstrates the functions and uses");
        System.out.println("of the DNSEntry class, for the editting of the ");
        System.out.println("djbDNS data file from which its DNS zones are created");
        System.out.println("\n");
    }
}

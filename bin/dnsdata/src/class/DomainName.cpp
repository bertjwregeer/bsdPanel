/**
* DomainName class implementation. Performs basic checking
* of domain names.
*
* @author Geoffrey Garside <ggarside@got-w00t.co.uk>
* @author Jan-Willem Regeer <xistence@x-istence.com>
* @version 0.1
* @copyright Geoffrey Garside 2005
* @copyright X-Istence.com 2005
* @licence http://licence.got-w00t.co.uk/project Project
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "DomainName.h"
#include "DomainNameException.h"

bsdPanelNet::DomainName::DomainName() {
    domainCount++;
    name = "example.com";
}

bsdPanelNet::DomainName::DomainName(const std::string& domainName) {
    domainCount++;
    initCheckVars();
    try {
        domainName = checkAddress(domainName);
    } catch (DomainNameException e) {
        domainName = "example.com";
    }
    destroyCheckVars();
    
    name = domainName;
}

bsdPanelNet::DomainName::~DomainName() {
    domainCount--;
    destroyCheckVars();
}

bool bsdPanelNet::DomainName::isValid(std::string const& address) {
    try {
        address = checkAddress(address);
        return true;
    } catch (DomainNameException e) {
        return false;
    }
}


/** see page 143 of C++ for Java Programmers for another split function */
std::vector<std::string> bsdPanelNet::DomainName::splitName(const std::string& address) {
        std::string t;
        std::vector<std::string> v;
        std::istringstream strm(address);
        while (std::getline(strm, t, delimiter)) {
                v.push_back(t);
        }
        
        return v;
}

/**
* Properly ported to C++ now.
*/
std::string bsdPanelNet::DomainName::checkAddress(const std::string& address) {
    std::vector<std::string> parts = splitName(address);
        
    // weeeeeee this should actually work :-P
    std::vector<std::string>::iterator code =
        find (domainCode.begin(), domainCode.end(), parts.at(parts.size() - 1));
    if ( code != domainCode.end() ) {
        return address;
    } else {
        throw DomainNameException("Domain suffix invalid");
    }
}

std::ostream& bsdPanelNet::operator << (std::ostream& os, const DomainName& domainName) {
        os << domainName.name;
}

void bsdPanelNet::DomainName::destroyCheckVars() {
    if (domainCount < 1)
        delete domainCode;
}

// /*/TODO/*/ This is an expensive operation. Should be done once, after that it should be a global variable which can be used over and over again
void bsdPanelNet::DomainName::initCheckVars() {
    if (domainCount < 1)
        initDomainCodes();
}
void bsdPanelNet::DomainName::initDomainCodes() {
    domainCode.resize(257);
    
    // Country Level Domain Names
    domainCode.push_back("ac");
    domainCode.push_back("ad");
    domainCode.push_back("ae");
    domainCode.push_back("af");
    domainCode.push_back("ag");
    domainCode.push_back("ai");
    domainCode.push_back("al");
    domainCode.push_back("am");
    domainCode.push_back("an");
    domainCode.push_back("ao");
    domainCode.push_back("aq");
    domainCode.push_back("ar");
    domainCode.push_back("as");
    domainCode.push_back("at");
    domainCode.push_back("au");
    domainCode.push_back("aw");
    domainCode.push_back("ax");
    domainCode.push_back("az");
    domainCode.push_back("ba");
    domainCode.push_back("bb");
    domainCode.push_back("bd");
    domainCode.push_back("be");
    domainCode.push_back("bf");
    domainCode.push_back("bg");
    domainCode.push_back("bh");
    domainCode.push_back("bi");
    domainCode.push_back("bj");
    domainCode.push_back("bm");
    domainCode.push_back("bn");
    domainCode.push_back("bo");
    domainCode.push_back("br");
    domainCode.push_back("bs");
    domainCode.push_back("bt");
    domainCode.push_back("bv");
    domainCode.push_back("bw");
    domainCode.push_back("by");
    domainCode.push_back("bz");
    domainCode.push_back("ca");
    domainCode.push_back("cc");
    domainCode.push_back("cd");
    domainCode.push_back("cf");
    domainCode.push_back("cg");
    domainCode.push_back("ch");
    domainCode.push_back("ci");
    domainCode.push_back("ck");
    domainCode.push_back("cl");
    domainCode.push_back("cm");
    domainCode.push_back("cn");
    domainCode.push_back("co");
    domainCode.push_back("cr");
    domainCode.push_back("cs");
    domainCode.push_back("cu");
    domainCode.push_back("cv");
    domainCode.push_back("cx");
    domainCode.push_back("cy");
    domainCode.push_back("cz");
    domainCode.push_back("de");
    domainCode.push_back("dj");
    domainCode.push_back("dk");
    domainCode.push_back("dm");
    domainCode.push_back("do");
    domainCode.push_back("dz");
    domainCode.push_back("ec");
    domainCode.push_back("ee");
    domainCode.push_back("eg");
    domainCode.push_back("eh");
    domainCode.push_back("er");
    domainCode.push_back("es");
    domainCode.push_back("et");
    domainCode.push_back("fi");
    domainCode.push_back("fj");
    domainCode.push_back("fk");
    domainCode.push_back("fm");
    domainCode.push_back("fo");
    domainCode.push_back("fr");
    domainCode.push_back("ga");
    domainCode.push_back("gb");
    domainCode.push_back("gd");
    domainCode.push_back("ge");
    domainCode.push_back("gf");
    domainCode.push_back("gg");
    domainCode.push_back("gh");
    domainCode.push_back("gi");
    domainCode.push_back("gl");
    domainCode.push_back("gm");
    domainCode.push_back("gn");
    domainCode.push_back("gp");
    domainCode.push_back("gq");
    domainCode.push_back("gr");
    domainCode.push_back("gs");
    domainCode.push_back("gt");
    domainCode.push_back("gu");
    domainCode.push_back("gw");
    domainCode.push_back("gy");
    domainCode.push_back("hk");
    domainCode.push_back("hm");
    domainCode.push_back("hn");
    domainCode.push_back("hr");
    domainCode.push_back("ht");
    domainCode.push_back("hu");
    domainCode.push_back("id");
    domainCode.push_back("ie");
    domainCode.push_back("il");
    domainCode.push_back("im");
    domainCode.push_back("in");
    domainCode.push_back("io");
    domainCode.push_back("iq");
    domainCode.push_back("ir");
    domainCode.push_back("is");
    domainCode.push_back("it");
    domainCode.push_back("je");
    domainCode.push_back("jm");
    domainCode.push_back("jo");
    domainCode.push_back("jp");
    domainCode.push_back("ke");
    domainCode.push_back("kg");
    domainCode.push_back("kh");
    domainCode.push_back("ki");
    domainCode.push_back("km");
    domainCode.push_back("kn");
    domainCode.push_back("kp");
    domainCode.push_back("kr");
    domainCode.push_back("kw");
    domainCode.push_back("ky");
    domainCode.push_back("kz");
    domainCode.push_back("la");
    domainCode.push_back("lb");
    domainCode.push_back("lc");
    domainCode.push_back("li");
    domainCode.push_back("lk");
    domainCode.push_back("lr");
    domainCode.push_back("ls");
    domainCode.push_back("lt");
    domainCode.push_back("lu");
    domainCode.push_back("lv");
    domainCode.push_back("ly");
    domainCode.push_back("ma");
    domainCode.push_back("mc");
    domainCode.push_back("md");
    domainCode.push_back("mg");
    domainCode.push_back("mh");
    domainCode.push_back("mk");
    domainCode.push_back("ml");
    domainCode.push_back("mm");
    domainCode.push_back("mn");
    domainCode.push_back("mo");
    domainCode.push_back("mp");
    domainCode.push_back("mq");
    domainCode.push_back("mr");
    domainCode.push_back("ms");
    domainCode.push_back("mt");
    domainCode.push_back("mu");
    domainCode.push_back("mv");
    domainCode.push_back("mw");
    domainCode.push_back("mx");
    domainCode.push_back("my");
    domainCode.push_back("mz");
    domainCode.push_back("na");
    domainCode.push_back("nc");
    domainCode.push_back("ne");
    domainCode.push_back("nf");
    domainCode.push_back("ng");
    domainCode.push_back("ni");
    domainCode.push_back("nl");
    domainCode.push_back("no");
    domainCode.push_back("np");
    domainCode.push_back("nr");
    domainCode.push_back("nu");
    domainCode.push_back("nz");
    domainCode.push_back("om");
    domainCode.push_back("pa");
    domainCode.push_back("pe");
    domainCode.push_back("pf");
    domainCode.push_back("pg");
    domainCode.push_back("ph");
    domainCode.push_back("pk");
    domainCode.push_back("pl");
    domainCode.push_back("pm");
    domainCode.push_back("pn");
    domainCode.push_back("pr");
    domainCode.push_back("ps");
    domainCode.push_back("pt");
    domainCode.push_back("pw");
    domainCode.push_back("py");
    domainCode.push_back("qa");
    domainCode.push_back("re");
    domainCode.push_back("ro");
    domainCode.push_back("ru");
    domainCode.push_back("rw");
    domainCode.push_back("sa");
    domainCode.push_back("sb");
    domainCode.push_back("sc");
    domainCode.push_back("sd");
    domainCode.push_back("se");
    domainCode.push_back("sg");
    domainCode.push_back("sh");
    domainCode.push_back("si");
    domainCode.push_back("sj");
    domainCode.push_back("sk");
    domainCode.push_back("sl");
    domainCode.push_back("sm");
    domainCode.push_back("sn");
    domainCode.push_back("so");
    domainCode.push_back("sr");
    domainCode.push_back("st");
    domainCode.push_back("sv");
    domainCode.push_back("sy");
    domainCode.push_back("sz");
    domainCode.push_back("tc");
    domainCode.push_back("td");
    domainCode.push_back("tf");
    domainCode.push_back("tg");
    domainCode.push_back("th");
    domainCode.push_back("tj");
    domainCode.push_back("tk");
    domainCode.push_back("tl");
    domainCode.push_back("tm");
    domainCode.push_back("tn");
    domainCode.push_back("to");
    domainCode.push_back("tp");
    domainCode.push_back("tr");
    domainCode.push_back("tt");
    domainCode.push_back("tv");
    domainCode.push_back("tw");
    domainCode.push_back("tz");
    domainCode.push_back("ua");
    domainCode.push_back("ug");
    domainCode.push_back("uk");
    domainCode.push_back("um");
    domainCode.push_back("us");
    domainCode.push_back("uy");
    domainCode.push_back("uz");
    domainCode.push_back("va");
    domainCode.push_back("vc");
    domainCode.push_back("ve");
    domainCode.push_back("vg");
    domainCode.push_back("vi");
    domainCode.push_back("vn");
    domainCode.push_back("vu");
    domainCode.push_back("wf");
    domainCode.push_back("ws");
    domainCode.push_back("ye");
    domainCode.push_back("yt");
    domainCode.push_back("yu");
    domainCode.push_back("za");
    domainCode.push_back("zm");
    domainCode.push_back("zw");

    // Global Top Level Domain Names
    domainCode.push_back("com");
    domainCode.push_back("net");
    domainCode.push_back("org");
    domainCode.push_back("edu");
    domainCode.push_back("mil");
    domainCode.push_back("gov");
    domainCode.push_back("biz");
    
    // New.net Domain Names
    domainCode.push_back("name");
    domainCode.push_back("info");
    domainCode.push_back("museum");
}

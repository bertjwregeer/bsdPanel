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
* @Revision: $Id$ 
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "DomainName.h"

bsdPanelNet::DomainName::DomainName() {
    name = "example.com";
}

bsdPanelNet::DomainName::DomainName(std::string const& domainName) {
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
        destroyCheckVars();
        
        delete name;
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
        std::istringstream strm(s);
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
        
    // /*/TODO/*/ Untested code. Should work though, but from prior knowledge, it probably won't :P
    if (countryCode.find( parts.at(parts.size() - 1) ) ) {
        return address;
    } else if (parts.at(parts.size() - 1) == "tv" ) {
        return address
    } else if (globalCodes.find ( parts.size() - 1) ) {
        return address;
    } else if (newNameCodes.find( parts.size() - 1) ) {
        return address;
    } else {
        throw InvalidDomainException();
    }
}

std::ostream& bsdPanelNet::operator << (std::ostream& os, const DomainName& domainName) {
        os << domainName.name;
}

void bsdPanelNet::DomainName::destroyCheckVars() {
    delete countryCode;
    delete globalCode;
    delete newNameCode;
}

// /*/TODO/*/ This is an expensive operation. Should be done once, after that it should be a global variable which can be used over and over again
void bsdPanelNet::DomainName::initCheckVars() {
        initCountryCodes();
        initGlobalCodes();
        initNewNameCodes();
}
void bsdPanelNet::DomainName::initCountryCodes() {
    countryCode.resize(247);
    countryCode.push_back("ac");
    countryCode.push_back("ad");
    countryCode.push_back("ae");
    countryCode.push_back("af");
    countryCode.push_back("ag");
    countryCode.push_back("ai");
    countryCode.push_back("al");
    countryCode.push_back("am");
    countryCode.push_back("an");
    countryCode.push_back("ao");
    countryCode.push_back("aq");
    countryCode.push_back("ar");
    countryCode.push_back("as");
    countryCode.push_back("at");
    countryCode.push_back("au");
    countryCode.push_back("aw");
    countryCode.push_back("ax");
    countryCode.push_back("az");
    countryCode.push_back("ba");
    countryCode.push_back("bb");
    countryCode.push_back("bd");
    countryCode.push_back("be");
    countryCode.push_back("bf");
    countryCode.push_back("bg");
    countryCode.push_back("bh");
    countryCode.push_back("bi");
    countryCode.push_back("bj");
    countryCode.push_back("bm");
    countryCode.push_back("bn");
    countryCode.push_back("bo");
    countryCode.push_back("br");
    countryCode.push_back("bs");
    countryCode.push_back("bt");
    countryCode.push_back("bv");
    countryCode.push_back("bw");
    countryCode.push_back("by");
    countryCode.push_back("bz");
    countryCode.push_back("ca");
    countryCode.push_back("cc");
    countryCode.push_back("cd");
    countryCode.push_back("cf");
    countryCode.push_back("cg");
    countryCode.push_back("ch");
    countryCode.push_back("ci");
    countryCode.push_back("ck");
    countryCode.push_back("cl");
    countryCode.push_back("cm");
    countryCode.push_back("cn");
    countryCode.push_back("co");
    countryCode.push_back("cr");
    countryCode.push_back("cs");
    countryCode.push_back("cu");
    countryCode.push_back("cv");
    countryCode.push_back("cx");
    countryCode.push_back("cy");
    countryCode.push_back("cz");
    countryCode.push_back("de");
    countryCode.push_back("dj");
    countryCode.push_back("dk");
    countryCode.push_back("dm");
    countryCode.push_back("do");
    countryCode.push_back("dz");
    countryCode.push_back("ec");
    countryCode.push_back("ee");
    countryCode.push_back("eg");
    countryCode.push_back("eh");
    countryCode.push_back("er");
    countryCode.push_back("es");
    countryCode.push_back("et");
    countryCode.push_back("fi");
    countryCode.push_back("fj");
    countryCode.push_back("fk");
    countryCode.push_back("fm");
    countryCode.push_back("fo");
    countryCode.push_back("fr");
    countryCode.push_back("ga");
    countryCode.push_back("gb");
    countryCode.push_back("gd");
    countryCode.push_back("ge");
    countryCode.push_back("gf");
    countryCode.push_back("gg");
    countryCode.push_back("gh");
    countryCode.push_back("gi");
    countryCode.push_back("gl");
    countryCode.push_back("gm");
    countryCode.push_back("gn");
    countryCode.push_back("gp");
    countryCode.push_back("gq");
    countryCode.push_back("gr");
    countryCode.push_back("gs");
    countryCode.push_back("gt");
    countryCode.push_back("gu");
    countryCode.push_back("gw");
    countryCode.push_back("gy");
    countryCode.push_back("hk");
    countryCode.push_back("hm");
    countryCode.push_back("hn");
    countryCode.push_back("hr");
    countryCode.push_back("ht");
    countryCode.push_back("hu");
    countryCode.push_back("id");
    countryCode.push_back("ie");
    countryCode.push_back("il");
    countryCode.push_back("im");
    countryCode.push_back("in");
    countryCode.push_back("io");
    countryCode.push_back("iq");
    countryCode.push_back("ir");
    countryCode.push_back("is");
    countryCode.push_back("it");
    countryCode.push_back("je");
    countryCode.push_back("jm");
    countryCode.push_back("jo");
    countryCode.push_back("jp");
    countryCode.push_back("ke");
    countryCode.push_back("kg");
    countryCode.push_back("kh");
    countryCode.push_back("ki");
    countryCode.push_back("km");
    countryCode.push_back("kn");
    countryCode.push_back("kp");
    countryCode.push_back("kr");
    countryCode.push_back("kw");
    countryCode.push_back("ky");
    countryCode.push_back("kz");
    countryCode.push_back("la");
    countryCode.push_back("lb");
    countryCode.push_back("lc");
    countryCode.push_back("li");
    countryCode.push_back("lk");
    countryCode.push_back("lr");
    countryCode.push_back("ls");
    countryCode.push_back("lt");
    countryCode.push_back("lu");
    countryCode.push_back("lv");
    countryCode.push_back("ly");
    countryCode.push_back("ma");
    countryCode.push_back("mc");
    countryCode.push_back("md");
    countryCode.push_back("mg");
    countryCode.push_back("mh");
    countryCode.push_back("mk");
    countryCode.push_back("ml");
    countryCode.push_back("mm");
    countryCode.push_back("mn");
    countryCode.push_back("mo");
    countryCode.push_back("mp");
    countryCode.push_back("mq");
    countryCode.push_back("mr");
    countryCode.push_back("ms");
    countryCode.push_back("mt");
    countryCode.push_back("mu");
    countryCode.push_back("mv");
    countryCode.push_back("mw");
    countryCode.push_back("mx");
    countryCode.push_back("my");
    countryCode.push_back("mz");
    countryCode.push_back("na");
    countryCode.push_back("nc");
    countryCode.push_back("ne");
    countryCode.push_back("nf");
    countryCode.push_back("ng");
    countryCode.push_back("ni");
    countryCode.push_back("nl");
    countryCode.push_back("no");
    countryCode.push_back("np");
    countryCode.push_back("nr");
    countryCode.push_back("nu");
    countryCode.push_back("nz");
    countryCode.push_back("om");
    countryCode.push_back("pa");
    countryCode.push_back("pe");
    countryCode.push_back("pf");
    countryCode.push_back("pg");
    countryCode.push_back("ph");
    countryCode.push_back("pk");
    countryCode.push_back("pl");
    countryCode.push_back("pm");
    countryCode.push_back("pn");
    countryCode.push_back("pr");
    countryCode.push_back("ps");
    countryCode.push_back("pt");
    countryCode.push_back("pw");
    countryCode.push_back("py");
    countryCode.push_back("qa");
    countryCode.push_back("re");
    countryCode.push_back("ro");
    countryCode.push_back("ru");
    countryCode.push_back("rw");
    countryCode.push_back("sa");
    countryCode.push_back("sb");
    countryCode.push_back("sc");
    countryCode.push_back("sd");
    countryCode.push_back("se");
    countryCode.push_back("sg");
    countryCode.push_back("sh");
    countryCode.push_back("si");
    countryCode.push_back("sj");
    countryCode.push_back("sk");
    countryCode.push_back("sl");
    countryCode.push_back("sm");
    countryCode.push_back("sn");
    countryCode.push_back("so");
    countryCode.push_back("sr");
    countryCode.push_back("st");
    countryCode.push_back("sv");
    countryCode.push_back("sy");
    countryCode.push_back("sz");
    countryCode.push_back("tc");
    countryCode.push_back("td");
    countryCode.push_back("tf");
    countryCode.push_back("tg");
    countryCode.push_back("th");
    countryCode.push_back("tj");
    countryCode.push_back("tk");
    countryCode.push_back("tl");
    countryCode.push_back("tm");
    countryCode.push_back("tn");
    countryCode.push_back("to");
    countryCode.push_back("tp");
    countryCode.push_back("tr");
    countryCode.push_back("tt");
    countryCode.push_back("tv");
    countryCode.push_back("tw");
    countryCode.push_back("tz");
    countryCode.push_back("ua");
    countryCode.push_back("ug");
    countryCode.push_back("uk");
    countryCode.push_back("um");
    countryCode.push_back("us");
    countryCode.push_back("uy");
    countryCode.push_back("uz");
    countryCode.push_back("va");
    countryCode.push_back("vc");
    countryCode.push_back("ve");
    countryCode.push_back("vg");
    countryCode.push_back("vi");
    countryCode.push_back("vn");
    countryCode.push_back("vu");
    countryCode.push_back("wf");
    countryCode.push_back("ws");
    countryCode.push_back("ye");
    countryCode.push_back("yt");
    countryCode.push_back("yu");
    countryCode.push_back("za");
    countryCode.push_back("zm");
    countryCode.push_back("zw");
}

void bsdPanelNet::DomainName::initGlobalCodes() {
    globalCode.resize(7);
    globalCode.push_back("com");
    globalCode.push_back("net");
    globalCode.push_back("org");
    globalCode.push_back("edu");
    globalCode.push_back("mil");
    globalCode.push_back("gov");
    globalCode.push_back("biz");
}

void bsdPanelNet::DomainName::initNewNameCodes() {
    newNameCode.resize(2);
    newNameCode.push_back("name");
    newNameCode.push_back("info");

    // /*/TODO/*/ museum is another valid code, however, the current code does not work with it.
    // newNameCodes.push_back("museum");
}

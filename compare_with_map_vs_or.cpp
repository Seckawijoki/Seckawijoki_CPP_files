#include <iostream>
#include <set>
#include <map>
#include <string.h>
#include <time.h> 
#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_map>
 #include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;
namespace __gnu_cxx
 {
     template<> struct hash<const string>
     {
         size_t operator()(const string& s) const
         { return hash<const char*>()( s.c_str() ); } 
     };
     template<> struct hash<string>
     {
         size_t operator()(const string& s) const
         { return hash<const char*>()( s.c_str() ); }
     };
     template<> struct hash<const string&>
     {
         size_t operator()(const string& s) const
         { return hash<const char*>()( s.c_str() ); }
     };
 }
#else
#include <hash_map>
#include <hash_set>
using namespace std;
#endif
class ChannelList {
private:
	std::set<const char*> m_PackageCharArraySet;
	std::set<std::string> m_PackageStringSet;
//	std::map<std::string, bool> m_PackageStringBoolMap;
	hash_map<const std::string&, int> m_PackageStringBoolMap;
private:
	void initPackageCharArraySet(){
		m_PackageCharArraySet.insert("com.minitech.miniworld");
		m_PackageCharArraySet.insert("com.playmini.miniworld");
		m_PackageCharArraySet.insert("com.minitech.miniworld.nearme.gamecenter");
		m_PackageCharArraySet.insert("com.tencent.tmgp.minitech.miniworld");
		m_PackageCharArraySet.insert("com.minitech.miniworld.vivo");
		m_PackageCharArraySet.insert("com.minitech.miniworld.huawei");
		m_PackageCharArraySet.insert("com.minitech.miniworld.m4399");
		m_PackageCharArraySet.insert("com.minitech.miniworld.anzhi");
		m_PackageCharArraySet.insert("com.minitech.miniworld.coolpad");
		m_PackageCharArraySet.insert("com.minitech.miniworld.dcn");
		m_PackageCharArraySet.insert("com.minitech.miniworld.Egame");
		m_PackageCharArraySet.insert("com.minitech.miniworld.gg");
		m_PackageCharArraySet.insert("com.minitech.miniworld.iqiyi");
		m_PackageCharArraySet.insert("com.minitech.miniworld.jinli");
		m_PackageCharArraySet.insert("com.minitech.miniworld.jrtt");
		m_PackageCharArraySet.insert("com.minitech.miniworld.TMobile.Lenovo");
		m_PackageCharArraySet.insert("com.minitech.miniworld.meizu");
		m_PackageCharArraySet.insert("com.minitech.miniworld.TMobile.mi");
		m_PackageCharArraySet.insert("com.minitech.miniworld.Migu");
		m_PackageCharArraySet.insert("com.minitech.miniworld.test");
		m_PackageCharArraySet.insert("com.minitech.miniworld.samsung");
		m_PackageCharArraySet.insert("com.minitech.miniworld.sougou");
		m_PackageCharArraySet.insert("com.tencent.hall.minitech.miniworld");
		m_PackageCharArraySet.insert("com.minitech.miniworld.uc");
		m_PackageCharArraySet.insert("com.minitech.miniworld.wdj");
		m_PackageCharArraySet.insert("com.minitech.miniworld.TMobile.baidu");
		m_PackageCharArraySet.insert("com.minitech.miniworld.qihu");
		m_PackageCharArraySet.insert("com.playmini.miniworld.ow");
		m_PackageCharArraySet.insert("com.playmini.miniworld.test");
	}
	void initPackageStringSet(){
        m_PackageStringSet.insert(std::string("com.minitech.miniworld"));
        m_PackageStringSet.insert(std::string("com.playmini.miniworld"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.nearme.gamecenter"));
        m_PackageStringSet.insert(std::string("com.tencent.tmgp.minitech.miniworld"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.vivo"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.huawei"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.m4399"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.anzhi"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.coolpad"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.dcn"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.Egame"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.gg"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.iqiyi"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.jinli"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.jrtt"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.TMobile.Lenovo"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.meizu"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.TMobile.mi"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.Migu"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.test"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.samsung"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.sougou"));
        m_PackageStringSet.insert(std::string("com.tencent.hall.minitech.miniworld"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.uc"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.wdj"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.TMobile.baidu"));
        m_PackageStringSet.insert(std::string("com.minitech.miniworld.qihu"));
        m_PackageStringSet.insert(std::string("com.playmini.miniworld.ow"));
        m_PackageStringSet.insert(std::string("com.playmini.miniworld.test"));
	}
    void initPackageStringBoolMap() {
        m_PackageStringBoolMap["com.minitech.miniworld"] = 1;
        m_PackageStringBoolMap["com.playmini.miniworld"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.nearme.gamecenter"] = 1;
        m_PackageStringBoolMap["com.tencent.tmgp.minitech.miniworld"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.vivo"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.huawei"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.m4399"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.anzhi"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.coolpad"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.dcn"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.Egame"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.gg"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.iqiyi"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.jinli"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.jrtt"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.TMobile.Lenovo"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.meizu"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.TMobile.mi"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.Migu"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.test"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.samsung"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.sougou"] = 1;
        m_PackageStringBoolMap["com.tencent.hall.minitech.miniworld"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.uc"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.wdj"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.TMobile.baidu"] = 1;
        m_PackageStringBoolMap["com.minitech.miniworld.qihu"] = 1;
        m_PackageStringBoolMap["com.playmini.miniworld.ow"] = 1;
        m_PackageStringBoolMap["com.playmini.miniworld.test"] = 1;
    }
public:
	ChannelList(){
		initPackageCharArraySet();
		initPackageStringSet();
        initPackageStringBoolMap();
	}
	int findMap(std::string packageName){
		hash_map<const std::string&, int>::iterator iter = m_PackageStringBoolMap.find(packageName);
		if (iter != m_PackageStringBoolMap.end()){
			return iter->second;
		} else {
			return -1;
		}
	}
	bool matchPackageMap(const char* packageName) {
        return matchPackageMap(std::string(packageName));
    }
	bool matchPackageMap(std::string packageName) {
		hash_map<const std::string&, int>::iterator iter = m_PackageStringBoolMap.find(packageName);
        return iter != m_PackageStringBoolMap.end() && iter->second > 0;
        //return iter != m_PackageStringBoolMap.end();
        // return false;
    }
	bool matchPackageSet(const char* packageName) const {
		return m_PackageCharArraySet.find(packageName) != m_PackageCharArraySet.end();
	}
	bool matchPackageSet(std::string packageName) const {
		return m_PackageStringSet.find(packageName) != m_PackageStringSet.end();
	}
    bool matchPackage(std::string packageName) const {
        return 
            packageName.compare("com.minitech.miniworld") == 0
            || packageName.compare("com.playmini.miniworld") == 0
            || packageName.compare("com.minitech.miniworld.nearme.gamecenter") == 0
            || packageName.compare("com.tencent.tmgp.minitech.miniworld") == 0
            || packageName.compare("com.minitech.miniworld.vivo") == 0
            || packageName.compare("com.minitech.miniworld.huawei") == 0
            || packageName.compare("com.minitech.miniworld.m4399") == 0
            || packageName.compare("com.minitech.miniworld.anzhi") == 0
            || packageName.compare("com.minitech.miniworld.coolpad") == 0
            || packageName.compare("com.minitech.miniworld.dcn") == 0
            || packageName.compare("com.minitech.miniworld.Egame") == 0
            || packageName.compare("com.minitech.miniworld.gg") == 0
            || packageName.compare("com.minitech.miniworld.iqiyi") == 0
            || packageName.compare("com.minitech.miniworld.jinli") == 0
            || packageName.compare("com.minitech.miniworld.jrtt") == 0
            || packageName.compare("com.minitech.miniworld.TMobile.Lenovo") == 0
            || packageName.compare("com.minitech.miniworld.meizu") == 0
            || packageName.compare("com.minitech.miniworld.TMobile.mi") == 0
            || packageName.compare("com.minitech.miniworld.Migu") == 0
            || packageName.compare("com.minitech.miniworld.test") == 0
            || packageName.compare("com.minitech.miniworld.samsung") == 0
            || packageName.compare("com.minitech.miniworld.sougou") == 0
            || packageName.compare("com.tencent.hall.minitech.miniworld") == 0
            || packageName.compare("com.minitech.miniworld.uc") == 0
            || packageName.compare("com.minitech.miniworld.wdj") == 0
            || packageName.compare("com.minitech.miniworld.TMobile.baidu") == 0
            || packageName.compare("com.minitech.miniworld.qihu") == 0
            || packageName.compare("com.playmini.miniworld.ow") == 0
            || packageName.compare("com.playmini.miniworld.test") == 0
        ;
    }
    bool matchPackage(const char* packageName) const {
        return 
            strcmp(packageName, "com.minitech.miniworld") == 0
            || strcmp(packageName, "com.playmini.miniworld") == 0
            || strcmp(packageName, "com.minitech.miniworld.nearme.gamecenter") == 0
            || strcmp(packageName, "com.tencent.tmgp.minitech.miniworld") == 0
            || strcmp(packageName, "com.minitech.miniworld.vivo") == 0
            || strcmp(packageName, "com.minitech.miniworld.huawei") == 0
            || strcmp(packageName, "com.minitech.miniworld.m4399") == 0
            || strcmp(packageName, "com.minitech.miniworld.anzhi") == 0
            || strcmp(packageName, "com.minitech.miniworld.coolpad") == 0
            || strcmp(packageName, "com.minitech.miniworld.dcn") == 0
            || strcmp(packageName, "com.minitech.miniworld.Egame") == 0
            || strcmp(packageName, "com.minitech.miniworld.gg") == 0
            || strcmp(packageName, "com.minitech.miniworld.iqiyi") == 0
            || strcmp(packageName, "com.minitech.miniworld.jinli") == 0
            || strcmp(packageName, "com.minitech.miniworld.jrtt") == 0
            || strcmp(packageName, "com.minitech.miniworld.TMobile.Lenovo") == 0
            || strcmp(packageName, "com.minitech.miniworld.meizu") == 0
            || strcmp(packageName, "com.minitech.miniworld.TMobile.mi") == 0
            || strcmp(packageName, "com.minitech.miniworld.Migu") == 0
            || strcmp(packageName, "com.minitech.miniworld.test") == 0
            || strcmp(packageName, "com.minitech.miniworld.samsung") == 0
            || strcmp(packageName, "com.minitech.miniworld.sougou") == 0
            || strcmp(packageName, "com.tencent.hall.minitech.miniworld") == 0
            || strcmp(packageName, "com.minitech.miniworld.uc") == 0
            || strcmp(packageName, "com.minitech.miniworld.wdj") == 0
            || strcmp(packageName, "com.minitech.miniworld.TMobile.baidu") == 0
            || strcmp(packageName, "com.minitech.miniworld.qihu") == 0
            || strcmp(packageName, "com.playmini.miniworld.ow") == 0
            || strcmp(packageName, "com.playmini.miniworld.test") == 0
        ;
    }
	const char* find(const char* packageName){
		std::set<const char*>::iterator iter;
		iter = m_PackageCharArraySet.find(packageName);
		if (iter != m_PackageCharArraySet.end()){
			return *iter;	
		} else {
			return "";
		}
	} 
	std::string find(std::string packageName){
		std::set<std::string>::iterator iter;
		for (iter = m_PackageStringSet.begin(); iter != m_PackageStringSet.end(); ++iter){
			cout<<&iter<<" "<<*iter<<endl;
		}
		iter = m_PackageStringSet.find(packageName);
		if (iter != m_PackageStringSet.end()){
			return *iter;	
		} else {
			return "";
		}
	} 
};
int main(){
//	const std::string packageName = "com.tencent.hall.minitech.miniworld";
	const std::string packageName = "com.minitech.miniworld";
	ChannelList channelList;
	
	cout<<channelList.findMap(packageName)<<endl;
//	cout<<channelList.find(packageName)<<endl;
//	cout<<channelList.find(packageName.c_str())<<endl;
//	cout<<(bool)channelList.matchPackage(packageName)<<endl;
//	cout<<(bool)channelList.matchPackage(packageName.c_str())<<endl;
//	cout<<(bool)channelList.matchPackageSet(packageName)<<endl;
//	cout<<(bool)channelList.matchPackageSet(packageName.c_str())<<endl;
	
	int count = 0;
	int starttime, endtime;
	
	starttime = clock();
	for (int i = 0; i < count ; ++i){
		channelList.matchPackage(packageName);
	}
	endtime = clock();
//	cout<<(endtime - starttime)<<endl;
	
	starttime = clock();
	for (int i = 0; i < count ; ++i){
		channelList.matchPackage(packageName.c_str());
	}
	endtime = clock();
//	cout<<(endtime - starttime)<<endl;
	
	starttime = clock();
	for (int i = 0; i < count ; ++i){
		channelList.matchPackageSet(packageName);
	}
	endtime = clock();
//	cout<<(endtime - starttime)<<endl;
	
	starttime = clock();
	for (int i = 0; i < count ; ++i){
		channelList.matchPackageSet(packageName.c_str());
	}
	endtime = clock();
//	cout<<(endtime - starttime)<<endl;
	
	
	return 0;
}

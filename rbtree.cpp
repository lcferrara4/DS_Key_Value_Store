// rbtree.cpp: RBTree Map
#include "map.h"
#include <algorithm>
// Methods --------------------------------------------------------------------
void            RBTreeMap::insert(const std::string &key, const std::string &value) {
        std::pair<std::map<std::string, std::string>::iterator, bool> test; 
        
        if (rbMap.count(key) == 0){
            test = rbMap.insert(std::make_pair(key, value));
            if(!test.second){
                return; 
            }
            entries++;
        }
        else{
            rbMap[key]=value; 
        }        
}
const Entry     RBTreeMap::search(const std::string &key) {
    
    std::map<std::string, std::string>::iterator it; 
    it = rbMap.find(key); 
    if (it != rbMap.end()){
        Entry result = std::make_pair(it->first, it->second);  
        return result; 
    }
    return NONE;
}
void            RBTreeMap::dump(std::ostream &os, DumpFlag flag) {
        switch(flag){
            case(0):
                for(auto it = rbMap.begin(); it != rbMap.end(); it++){
                os << it->first << "\n";
                }
                break; 
            case (1): 
                for(auto it = rbMap.begin(); it != rbMap.end(); it++){
                os << it->second << "\n";
                }
                break; 
            case (2):
                 for(auto it = rbMap.begin(); it != rbMap.end(); it++){
                os << it->first << "\t" << it->second << "\n";
                }
                break; 
            case(3):
                for(auto it = rbMap.begin(); it != rbMap.end(); it++){
                os << it->second << "\t" << it->first << "\n";
                }
                break; 
    }
}    
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
// unsorted.cpp: Unsorted Map

#include "map.h"
#include <vector>
#include <complex>
#include <iostream>
#include <string>

// Methods --------------------------------------------------------------------

void            UnsortedMap::insert(const std::string &key, const std::string &value) {
	for(int i=0; i<entries;i++){
		if(map[i].first == key){
			map[i].second = value;
			return;
		}
	}
	map.push_back(std::make_pair(key,value));
	entries = entries + 1;
}

const Entry     UnsortedMap::search(const std::string &key) {
	for(int i=0;i<entries;i++){
		if(map[i].first == key){
			return map[i];
		}
	}
    return NONE;
}

void            UnsortedMap::dump(std::ostream &os, DumpFlag flag) {
	if(flag == 0){
		for(int i=0;i<entries;i++){
			os << map[i].first << "\n";
		}
	}else if(flag == 1){
		for(int i=0;i<entries;i++){
			os << map[i].second << "\n";
		}
	}else if(flag == 2){
		for(int i=0;i<entries;i++){
			os << map[i].first << "\t" << map[i].second << "\n";
		}
	}else if(flag == 3){
		for(int i=0;i<entries;i++){
			os << map[i].second << "\t" << map[i].first << "\n";
		}
	}
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

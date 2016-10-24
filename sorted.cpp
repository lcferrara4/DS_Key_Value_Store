// sorted.cpp: Sorted Map

#include "map.h"

#include <algorithm>
#include <vector>
#include <iostream>
#include <unistd.h>

// Type Definitions ------------------------------------------------------------

typedef std::vector<Entry>::iterator IT;

// Prototypes ------------------------------------------------------------------

const Entry     binary_search(const IT &start, const IT &end, const std::string &key);

// Methods ---------------------------------------------------------------------

void            SortedMap::insert(const std::string &key, const std::string &value) {
	if(entries == 0){
		map.push_back(std::make_pair(key,value));
		entries = entries +1;
	}
	for(int i=0;i<entries;i++){
		if(map[i].first == key){
			map[i].second = value;
			return;
		}else if(map[i].first > key){
			map.insert(map.begin()+i,std::make_pair(key,value));
			entries = entries + 1;
			return;
		}
	}
	map.push_back(std::make_pair(key,value));
	entries = entries +1;
	return;
}

const Entry     SortedMap::search(const std::string &key) {
	IT start = map.begin();
	IT end = map.end();

    return binary_search(start, end, key);
}

void            SortedMap::dump(std::ostream &os, DumpFlag flag) {
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

// Internal Functions ----------------------------------------------------------

const Entry   binary_search(const IT &start, const IT &end, const std::string &target) {
	IT s = start;
	IT e = end;
	
	while (1){
		IT m = s + distance(s,e)/2;
		if(distance(s,e)/2 == 0 && m->first != target){
			return NONE;
		}else if(m->first < target){
			s = m;
		}else if(m->first > target){
			e = m;
		}else if(m->first == target){
			return *m;
		}
	}   
		
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

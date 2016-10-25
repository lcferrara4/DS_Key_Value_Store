// freqencies.cpp

#include "map.h"
#include <cassert>
#include <iostream>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <chrono>
#include <numeric>

// Main execution --------------------------------------------------------------
void usage(int status) {
    std::cout << "usage: map_test" << std::endl
              << "    -b BACKEND    Which Map backend (unsorted, sorted, bst, rbtree, treap)" << std::endl
              << " dump DUMP_KEY, DUMP_VALUE, DUMP_KEY_VALUE, DUMP_VALUE_KEY" << std::endl;

    exit(status);
}

std::string increment(const std::string &s){
	int num = stoi(s);
	num = num +1;
	return std::to_string(num);

}

void parse_command_line_options(int argc, char *argv[], Map *&map) {
    int c;

    while ((c = getopt(argc, argv, "hb:")) != -1) {
        switch (c) {
            case 'b':
                if (strcasecmp(optarg, "unsorted") == 0) {
                    map = new UnsortedMap();
                } else if (strcasecmp(optarg, "sorted") == 0) {
                    map = new SortedMap();
                } else if (strcasecmp(optarg, "bst") == 0) {
                    map = new BSTMap();
                } else if (strcasecmp(optarg, "rbtree") == 0) {
                    map = new RBTreeMap();
                } else if (strcasecmp(optarg, "treap") == 0) {
                    map = new TreapMap();
                } else {
                    usage(1);
                }
                break;
            case 'h':
                usage(0);
                break;
            default:
                usage(1);
                break;
        }
    }

    if (map == nullptr) {
    	map = new UnsortedMap();
    }
}

int main(int argc, char *argv[]) {
	Map *map = nullptr;

    if(argc !=4){
		usage(1);
	}
    parse_command_line_options(argc, argv, map);

    DumpFlag d;
    
    if (strcasecmp(argv[3], "DUMP_KEY") == 0 ){
    	d = DUMP_KEY;
   	} else if(strcasecmp(argv[3], "DUMP_VALUE") == 0 ){
   		d = DUMP_VALUE;
   	} else if(strcasecmp(argv[3], "DUMP_KEY_VALUE") == 0 ){
   		d = DUMP_KEY_VALUE;
   	} else if(strcasecmp(argv[3], "DUMP_VALUE_KEY") == 0 ){
   		d = DUMP_VALUE_KEY;
   	} else{
   		usage(1);
   	}

    std::string word;
    while(std::cin >> word){
    	auto result = map->search(word);
    	if(result == NONE){
    		map->insert(word,"1");
    	}else{
    		map->insert(word,increment(result.second));
    	}
    }
    map->dump(std::cout,d);
    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

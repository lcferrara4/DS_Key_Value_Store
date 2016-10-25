// map_bench.cpp

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
              << "    -b BACKEND    Which Map backend (unsorted, sorted, bst, rbtree, treap)" << std::endl;

    exit(status);
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

std::string int_to_key( int i, size_t padlength){
	std::string s = std::to_string(i);
	if( padlength > s.size() ){
		s.insert(0, padlength - s.size(), '0');
	}
	return s;
}

int main(int argc, char *argv[]) {
	Map *map = nullptr;

	parse_command_line_options(argc, argv, map);

	if(argc !=5){
		usage(1);
	}

	int N = atoi(argv[3]);
	size_t padlength = atoi(argv[4]);


	auto start = std::chrono::high_resolution_clock::now();
	
	// Insert 1 - N
    for (int i = 0; i < N; i++) {
		std::string s = int_to_key(i, padlength); 
    	map->insert(s, s);
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end-start;
    std::cout << "Time to insert: " << diff.count() << std::endl;

	start = std::chrono::high_resolution_clock::now();
    
    // Search 1 - N
    for (int i = 0; i < N; i++) {
		std::string s = int_to_key(i, padlength); 
		assert(map->search(s) != NONE);
    }

    end = std::chrono::high_resolution_clock::now();

    diff = end-start;
    std::cout << "Time to insert: " << diff.count() << std::endl;

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

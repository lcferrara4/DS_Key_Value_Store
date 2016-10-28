// map.h
#pragma once
// Includes --------------------------------------------------------------------
#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <map>
// Type definitions ------------------------------------------------------------
typedef enum {
    DUMP_KEY,
    DUMP_VALUE,
    DUMP_KEY_VALUE,
    DUMP_VALUE_KEY,
} DumpFlag;
typedef std::pair<std::string, std::string> Entry;
// Constants -------------------------------------------------------------------
extern const Entry NONE;
// Structures ------------------------------------------------------------------
struct Node {
    Entry entry;
    int     priority;
    Node    *left;
    Node    *right;

	~Node(){
		delete left;
		delete right;
	}
};
// Classes ---------------------------------------------------------------------
class Map {
public:
    virtual void            insert(const std::string &key, const std::string &value) {}
    virtual const Entry     search(const std::string &key) { return NONE; }
    virtual void            dump(std::ostream &os, DumpFlag flag) {}
    virtual                ~Map() {}
};
class UnsortedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            int entries = 0;
            std::vector<Entry> map;
};
class SortedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            int entries = 0;
            std::vector<Entry> map;
};
class BSTMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
            ~BSTMap();
private:
    Node * root = nullptr;
};
class RBTreeMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            int entries; 
            std::map<std::string, std::string> rbMap; 
};
class TreapMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
            ~TreapMap();
private:
    Node * root = nullptr;
};

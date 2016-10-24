// bst.cpp: BST Map

#include "map.h"

#include <stdexcept>

// Prototypes ------------------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value);
Node *search_r(Node *node, const std::string &key);
void    dump_r(Node *node, std::ostream &os, DumpFlag flag);

// Methods ---------------------------------------------------------------------

void            BSTMap::insert(const std::string &key, const std::string &value) {

	Node * n = insert_r(root,key,value);

}

const Entry     BSTMap::search(const std::string &key) {
	Node * n = search_r(root,key);
	if(n != nullptr){
		return n->entry;
	}else{
		return NONE;
	}
    
}

void            BSTMap::dump(std::ostream &os, DumpFlag flag) {

}

// Internal Functions ----------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
	if(node == nullptr){
		node = new Node;
		node->entry = std::make_pair(key,value);
		node->priority = 0;
		node->left = nullptr;
		node->right = nullptr;
		return node;
	}else if(node->entry.first > key){
		return insert_r(node->left,key,value);
	}else{
		return insert_r(node->right,key,value);
	}
}

Node *search_r(Node *node, const std::string &key) {
	if(node->entry.first == key || node == nullptr){
		return node;
	}else if (node->entry.first > key){
		return search_r(node->left,key);
	}else{
		return search_r(node->right,key);
	}
    return nullptr;
}

void dump_r(Node *node, std::ostream &os, DumpFlag flag) {
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

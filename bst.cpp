// bst.cpp: BST Map

#include "map.h"

#include <stdexcept>

// Prototypes ------------------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value);
Node *search_r(Node *node, const std::string &key);
void    dump_r(Node *node, std::ostream &os, DumpFlag flag);

// Methods ---------------------------------------------------------------------

BSTMap::~BSTMap(){
	delete root;
}

void            BSTMap::insert(const std::string &key, const std::string &value) {
	root = insert_r(root,key,value);
}

const Entry     BSTMap::search(const std::string &key) {
	Node * n = search_r(root,key);
	if(n == nullptr){
		return NONE;
	}else{
		return n->entry;
	} 
}

void            BSTMap::dump(std::ostream &os, DumpFlag flag) {
	dump_r(root,os,flag);
}

// Internal Functions ----------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
	if(node == nullptr){
		node = new Node;
		node->entry = std::make_pair(key,value);
		node->priority = 0;
		node->left = nullptr;
		node->right = nullptr;
	}else if(node->entry.first > key){  
		 node -> left = insert_r(node->left,key,value);
	}else if(node->entry.first == key){  
		node->entry.second = value; 
	}else{
		 node -> right = insert_r(node->right,key,value);
	}
	return node; 
}

Node *search_r(Node *node, const std::string &key) {
	if(node == nullptr || node->entry.first == key){
		return node;
	}else if (node->entry.first > key){
		 return search_r(node->left,key);
	}else{
		 return search_r(node->right,key);
	}
	return node;
}

void dump_r(Node *node, std::ostream &os, DumpFlag flag) {
	if(node == nullptr){
		return;
	}
	if(flag == 0){
		dump_r(node->left,os,flag); 
		os<<node->entry.first<<"\n"; 
		dump_r(node->right,os,flag); 
		
	}else if(flag == 1){
		dump_r(node->left,os,flag); 
		os<<node->entry.second<<"\n"; 
		dump_r(node->right,os,flag); 
		
	}else if(flag == 2){
		dump_r(node->left,os,flag); 
		os<<node->entry.first<<"\t"<<node->entry.second<<"\n";  
		dump_r(node->right,os,flag); 
		
	}else if(flag == 3){
		dump_r(node->left,os,flag); 
		os<<node->entry.second<<"\t"<<node->entry.first<<"\n";
		dump_r(node->right,os,flag); 
		
	}
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

#pragma once
#include<iostream>
#include"BSTNode.h"
using namespace std;
class BSTTree
{
public:
	void insert(BSTNode* &x, BSTNode* &p);
	void *deletenode(BSTNode* &x, BSTNode * &p);
	BSTNode *findmin(BSTNode* &p);
	BSTNode *search(int i, int y,BSTNode* &n);
	int preheight(BSTNode* &root);
	int height(BSTNode* &root);
	void show(BSTNode* &root,string s);
	string prepareDotString(BSTNode *&root);

	BSTNode *root;
	BSTTree() {
		root = nullptr;
	}

};


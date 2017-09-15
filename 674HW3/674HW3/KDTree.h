#pragma once
#include<iostream>
#include"KDNode.h"
using namespace std;
class KDTree
{
public:
	void insert(KDNode* &x, KDNode *&p, int flag);
	void predeletenode(KDNode* &p, KDNode*&x, int depth);
	KDNode *deletenode(KDNode *&p, KDNode*&x);
	KDNode *prefindmin(KDNode* &p,int d,int depth);
	KDNode *findmin(KDNode * &p, int d);
	KDNode *minKDNode(KDNode *x, KDNode *y, KDNode *z, int flag);
	

	KDNode *search(int x, int y, int z,KDNode* &root,int flag);
	int preheight(KDNode* &root);
	int height(KDNode* &root);
	void show(KDNode* &root,string s);
	string prepareDotString(KDNode *&root);

	KDNode *root;
	KDTree() {
		root = NULL;
	}

};

#pragma once

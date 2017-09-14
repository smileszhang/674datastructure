#include<iostream>
#include"BSTNode.h"
#include"BSTTree.h"
#include <fstream>
#include<string>
using namespace std;
void BSTTree::insert(BSTNode* &x,BSTNode * &p) {
	if (p == NULL)
		p = x;
	else if (x->key <= p->key)
	{
		if (p->leftlink != NULL)
			insert(x, p->leftlink);
		else
			p->leftlink = x;
	}
	else
	{
		if (p->rightlink != NULL)
			insert(x, p->rightlink);
		else
			p->rightlink = x;
	}

}
void *BSTTree::deletenode(BSTNode* &x,BSTNode* &p) {
	if (p == NULL)
		return NULL;
	else if (search(x->key, p)!=NULL)
	{
		if (x->leftlink != NULL) insert(x->leftlink, x->rightlink);
	}
	p = x->rightlink; 
	delete x;


	/*if (p == NULL)
		return NULL;
	else if (x->key <= p->key)
		p->leftlink = deletenode(x, p->leftlink);
	else if (x->key > p->key)
		p->rightlink = deletenode(x, p->rightlink);
	else if (p->leftlink == NULL || p->rightlink == NULL) {
		BSTNode *repl=NULL;
		if (p->leftlink == NULL) repl = p->rightlink;
		if (p->rightlink == NULL)repl = p->leftlink;
		return repl;
	}
	else {
		p->key = findmin(p->rightlink)->key;
		p->rightlink = deletenode(p, p->rightlink);
	}
	return p;*/
}
BSTNode *BSTTree::findmin(BSTNode* &p) {
	while (p->leftlink != NULL)
		p = p->leftlink;
	return p;
}
BSTNode *BSTTree::search(int x,BSTNode* &root) {
	if (root == NULL)
		return NULL;
	else if (x == root->key) return root;
	else if(x<root->key) return search(x,root->leftlink);
	else if (x > root->key)
		return search(x,root->rightlink);
}
int BSTTree::preheight(BSTNode* &root) {
	if (root == NULL)
		return -1;
	else
	{
		int lh = preheight(root->leftlink);
		int rh = preheight(root->rightlink);
		return 1 + (lh > rh ? lh: rh);
	}
}
int BSTTree::height(BSTNode* &root) {
	int h=preheight(root);
	return h+1;
}

string BSTTree::prepareDotString(BSTNode * &root) {
	string s = "";
	if (root != NULL) {
		if (root->leftlink) {
			s += "\"" + to_string(root->key) + "," + to_string(root->value) + "\"" + "->" + "\"" + to_string(root->leftlink->key) + "," + to_string(root->leftlink->value) + "\"" + ";" + "\n";
			s += prepareDotString(root->leftlink);
		}
		if (root->rightlink) {
			s += "\"" + to_string(root->key) + "," + to_string(root->value) + "\"" + "->" + "\"" + to_string(root->rightlink->key) + "," + to_string(root->rightlink->value) + "\"" + ";" + "\n";
			s += prepareDotString(root->rightlink);
		}
	}
	return s;
}

void BSTTree::show(BSTNode* &root,string s) {

	ofstream outfile;
	outfile.open(s);
	if (outfile.is_open())
	{
		outfile << "digraph G{" << endl;
		outfile << prepareDotString(root) << endl;
		outfile << "}";
		outfile.close();
	}
	else
	{
		cout << "can not open files" << endl;
	}
}

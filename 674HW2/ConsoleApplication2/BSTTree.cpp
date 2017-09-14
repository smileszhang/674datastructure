#include<iostream>
#include"BSTNode.h"
#include"BSTTree.h"
#include <fstream>
#include<string>
using namespace std;
void BSTTree::insert(BSTNode* &x,BSTNode * &p) {
	if (p == nullptr)
		p = x;
	else if (x->key <= p->key)
	{
		if (p->leftlink != nullptr)
			insert(x, p->leftlink);
		else
			p->leftlink = x;
	}
	else
	{
		if (p->rightlink != nullptr)
			insert(x, p->rightlink);
		else
			p->rightlink = x;
	}

}
void *BSTTree::deletenode(BSTNode* &x,BSTNode* &p) {
	if (p == nullptr)
		return nullptr;
	else if (search(x->key, x->value, p)!=nullptr)
	{
		if (x->leftlink != nullptr) insert(x->leftlink, x->rightlink);
	}
	p = x->rightlink; 
	delete x;


	/*if (p == nullptr)
		return nullptr;
	else if (x->key <= p->key)
		p->leftlink = deletenode(x, p->leftlink);
	else if (x->key > p->key)
		p->rightlink = deletenode(x, p->rightlink);
	else if (p->leftlink == nullptr || p->rightlink == nullptr) {
		BSTNode *repl=nullptr;
		if (p->leftlink == nullptr) repl = p->rightlink;
		if (p->rightlink == nullptr)repl = p->leftlink;
		return repl;
	}
	else {
		p->key = findmin(p->rightlink)->key;
		p->rightlink = deletenode(p, p->rightlink);
	}
	return p;*/
}
BSTNode *BSTTree::findmin(BSTNode* &p) {
	while (p->leftlink != nullptr)
		p = p->leftlink;
	return p;
}
BSTNode *BSTTree::search(int x,int y,BSTNode* &root) {
	if (root == nullptr)
		return nullptr;
	else if (x == root->key&&y==root->value) return root;
	else if(x<root->key) return search(x,y,root->leftlink);
	else if (x > root->key)
		return search(x,y,root->rightlink);
}
int BSTTree::preheight(BSTNode* &root) {
	if (root == nullptr)
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
	if (root != nullptr) {
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

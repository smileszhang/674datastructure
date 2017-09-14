#include<iostream>
#include"KDNode.h"
#include"KDTree.h"
#include<fstream>
#include<string>

using namespace std;
void KDTree::insert(KDNode* &x, KDNode *&p, int flag)
{
	/*if (p == nullptr)
	{
		KDNode *temp = new KDNode;
		for (int i = 0; i < 2; i++)
			temp->flag[i] = flag[i];
		temp->leftlink = temp->rightlink = nullptr;
	}*/

	if (p == nullptr)
	{
		p = x;
	}
	else if (flag % 2 == 0) {
		if (x->k_x <= p->k_x)
		{
			if (p->leftlink != nullptr)
			{
				flag++;
				insert(x, p->leftlink, flag);
			}
			else
				p->leftlink = x;
		}
		else
		{
			if (p->rightlink != nullptr)
			{
				flag++;
				insert(x, p->rightlink, flag);
			}
			else
				p->rightlink = x;
		}

	}
	else if (flag % 2 == 1)
	{
		if (x->k_y <= p->k_y)
		{
			if (p->leftlink != nullptr)
			{
				flag++;
				insert(x, p->leftlink, flag);
			}
			else
				p->leftlink = x;
		}
		else
		{
			if (p->rightlink != nullptr)
			{
				flag++;
				insert(x, p->rightlink, flag);
			}
			else
				p->rightlink = x;
		}
	}
}

int KDTree::preheight(KDNode* &root) {
	if (root == nullptr)
		return -1;
	else
	{
		int lh = preheight(root->leftlink);
		int rh = preheight(root->rightlink);
		return 1 + (lh > rh ? lh : rh);
	}
}

int KDTree::height(KDNode* &root) {
	int h = preheight(root);
	return h + 1;
}

KDNode *KDTree::search(int x, int y, int z, KDNode* &root, int flag) {
	if (root == nullptr)
		return nullptr;
	else if (flag % 2 == 0) {
		if (x < root->k_x)
		{
			flag++;
			return search(x, y, z, root->leftlink, flag);
		}
		else if (x > root->k_x)
		{
			flag++;
			return search(x, y, z, root->rightlink, flag);
		}
		else if (x == root->k_x&&y == root->k_y&&z == root->value)
			return root;
	}
	else if (flag % 2 == 1) {
		if (y < root->k_y)
		{
			flag++;
			return search(x, y, z, root->leftlink, flag);
		}
		else if (y > root->k_y)
		{
			flag++;
			return search(x, y, z, root->rightlink, flag);
		}
		else if (x == root->k_x&&y == root->k_y&&z == root->value)
			return root;
	}
}


KDNode *KDTree::minKDNode(KDNode *x, KDNode *y, KDNode *z, int d) {
	KDNode *res = x;
	if (y != nullptr&&y->flag[d] < res->flag[d])
		res = y;
	if (z != nullptr&&z->flag[d] < res->flag[d])
		res = z;
	return res;
	/*if (d == 0) {
		if (y != nullptr&&y->k_x < res->k_x)
			res = y;
		if (z != nullptr&&z->k_x < res->k_x)
			res = z;
	}
	else if (d == 1) {
		if (y != nullptr&&y->k_y < res->k_y)
			res = y;
		if (z != nullptr&&z->k_y < res->k_y)
			res = z;
		}
	return res;*/
}
KDNode *KDTree::prefindmin(KDNode* &p, int d, int depth) {
	if (p == nullptr)
		return nullptr;
	int cd = depth % 2;
	if (cd == d)
	{	
		if (p->leftlink == nullptr)
			return p;
		return prefindmin(p->leftlink, d, depth + 1);
	}
	return minKDNode(p, prefindmin(p->leftlink, d, depth + 1), prefindmin(p->rightlink, d, depth + 1), d);
}
KDNode *KDTree::findmin(KDNode *&p, int d)
{
	return prefindmin(p, d, 0);
}

KDNode *KDTree::predeletenode(KDNode* &p, KDNode*&x, int depth)
{
	if (p == nullptr)
		return nullptr;
	int cd = depth % 2;
	if (p->flag[0] == x->flag[0] && p->flag[1] == x->flag[1]&&p->value==x->value)
	{
		if (p->rightlink != nullptr) {
			KDNode *min = findmin(p->rightlink, cd);
			p->flag[0] = min->flag[0];
			p->flag[1] = min->flag[1];
			p->value = min->value;
			p->rightlink = predeletenode(p->rightlink, min, depth + 1);
		}
		else if (p->leftlink != nullptr)
		{
			p->rightlink = p->leftlink;
			p = predeletenode(p, x, depth);
			/*
			KDNode *min = findmin(p->leftlink, cd);
			p->flag[0] = min->flag[0];
			p->flag[1] = min->flag[1];
			p->value = min->value;
			p->rightlink = predeletenode(p->leftlink, min, depth + 1);
			*/
		}
		else
		{
			delete p;
			return nullptr;
		}
		return p;
	}

	if (x->flag[cd] < p->flag[cd])
	{
		p->leftlink = predeletenode(p->leftlink,x,depth + 1);
		p->rightlink = predeletenode(p->rightlink,x, depth + 1);
		return p;
	}
}
KDNode *KDTree::deletenode(KDNode *&p, KDNode*&x)
{
	 KDNode *res=predeletenode(p, x, 0);
	 res->k_x = res->flag[0];
	 res->k_y = res->flag[1];
	 return res;

}
void KDTree::show(KDNode* &root, string s) {
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
string KDTree::prepareDotString(KDNode *&root) {
	string s = "";
	if (root->leftlink) {
		s += "\"" + to_string(root->k_x) + "," + to_string(root->k_y) + "," + to_string(root->value) + "\"" + "->" + "\"" + to_string(root->leftlink->k_x) + "," + to_string(root->leftlink->k_y) + "," + to_string(root->leftlink->value) + "\"" + ";" + "\n";
		s += prepareDotString(root->leftlink);
	}
	if (root->rightlink) {
		s += "\"" + to_string(root->k_x) + "," + to_string(root->k_y) + "," + to_string(root->value) + "\"" + "->" + "\"" + to_string(root->rightlink->k_x) + "," + to_string(root->rightlink->k_y) + "," + to_string(root->rightlink->value) + "\"" + ";" + "\n";
		s += prepareDotString(root->rightlink);
	}
	return s;
}
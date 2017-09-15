#include<iostream>
#include"KDNode.h"
#include"KDTree.h"
#include<fstream>
#include<string>

using namespace std;
void KDTree::insert(KDNode* &x, KDNode *&p, int flag)
{
	if (p == NULL)
	{
		p = x;
		x->flag = flag % 2;
	}
	else if (flag % 2 == 0) 
	{
		if (x->k_x <= p->k_x)
		{
			if (p->leftlink != NULL)
			{
				flag++;
				
				insert(x, p->leftlink, flag);
			}
			else
			{
				p->leftlink = x;
				x->flag = (flag + 1) % 2;
			}

		}
		else
		{
			if (p->rightlink != NULL)
			{
				flag++;
				
				insert(x, p->rightlink, flag);
			}
			else
			{
				p->rightlink = x;
				x->flag = (flag+1) % 2;
			}
		}
	}
	else if (flag % 2 == 1)
	{
		if (x->k_y <= p->k_y)
		{
			if (p->leftlink != NULL)
			{
				flag++;
				
				insert(x, p->leftlink, flag);
			}
			else
			{
				p->leftlink = x;
				x->flag = (flag+1) % 2;
			}
		}
		else
		{
			if (p->rightlink != NULL)
			{
				flag++;
				
				insert(x, p->rightlink, flag);
			}
			else
			{
				p->rightlink = x;
				x->flag = (flag+1) % 2;
			}
		}
	}
	
}

int KDTree::preheight(KDNode* &root) {
	if (root == NULL)
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
	if (root == NULL)
		return NULL;
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
	if (d == 1) {
		if (y != NULL&&y->k_y<res->k_y)
			res = y;
		if (z != NULL&&z->k_y<res->k_y)
			res = z;
	}
	else if (d == 0) {
		if (y != NULL&&y->k_x<res->k_x)
			res = y;
		if (z != NULL&&z->k_x<res->k_x)
			res = z;
	}
	
	return res;
}
KDNode *KDTree::prefindmin(KDNode* &p, int d, int depth) {
	if (p == NULL)
		return NULL;
	
	if (p->flag == d)
	{	
		if (p->leftlink == NULL)
			return p;
		return prefindmin(p->leftlink, d, depth + 1);
	}
	return minKDNode(p, prefindmin(p->leftlink, d, depth + 1), prefindmin(p->rightlink, d, depth + 1), d);
}
KDNode *KDTree::findmin(KDNode *&p, int d)
{
	return prefindmin(p, d, 0);
}


void KDTree::predeletenode(KDNode* &p, KDNode*&x, int depth)
{
	if (p == NULL)
		return;
	//if the delete node is current node
	if (p->k_x==x->k_x&&p->k_y==x->k_y&&p->value==x->value)
	{
		//if right child is not null
		if (p->rightlink != NULL) {
			KDNode *min = findmin(p->rightlink, p->flag);
			p->k_x = min->k_x;
			p->k_y = min->k_y;
			p->value = min->value;
			predeletenode(p->rightlink, min, depth + 1);
		}
		//if left child is not null
		else if (p->leftlink != NULL)
		{
			p->rightlink = p->leftlink;
			p->leftlink = NULL;
			predeletenode(p, x, depth);
			
		}
		else
		{
			p = NULL;
			return;
		}
		return;
	}
	
	if (p->flag==1)
	{
		if (x->k_y < p->k_y)
			predeletenode(p->leftlink, x, depth + 1);
		else
			predeletenode(p->rightlink, x, depth + 1);
		return;
	}
	else
	{
		if (x->k_x < p->k_x)
			predeletenode(p->leftlink, x, depth + 1);
		else
			predeletenode(p->rightlink, x, depth + 1);
		return;

	}

}
KDNode *KDTree::deletenode(KDNode *&p, KDNode*&x)
{
	 predeletenode(p, x, 0);
	 return p;

}
//to write in a dot file
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
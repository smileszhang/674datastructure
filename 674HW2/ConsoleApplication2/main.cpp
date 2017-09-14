#include<iostream>
#include"BSTNode.h"
#include"BSTTree.h"
#include"KDNode.h"
#include"KDTree.h"
#include <stdlib.h> 
#include <fstream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;
bool contains(int array[], int n,int count)
{
	for (int i = 0; i <= count; i++) 
	{
		if (array[i] == n)
			return true;
	}
	return false;
	
}
int main(){

	BSTNode *node[200];
	KDNode *knode[200];

	int k[200], d[200], x[200], y[200];
	//define k
	k[0] = 0;
	k[1] = 1000;
	for (int i = 2; i <200; i++)
	{
		k[i] = (k[i - 1] + k[i - 2]) / 2;
	}
	//define d
	for (int i = 0; i < 200; i++)
	{
		d[i] = i;
	}
	//define x
	x[0] = 0;
	x[1] = 500;
	for (int i = 2; i < 200; i++)
	{
		x[i] = (x[i - 1] + x[i - 2]) / 2;
	}
	//define y
	for (int i = 0; i < 200; i++)
	{
		y[i] = 500-x[i];
	}
	//define node
	for (int i = 0; i < 200; i++)
	{
		node[i] = new BSTNode();
		node[i]->key = k[i];
		node[i]->value = d[i];
	}
	//define knode
	
	for (int i = 0; i < 200; i++)
	{
		knode[i] = new KDNode();
		knode[i]->k_x = x[i];
		knode[i]->k_y = y[i];
		knode[i]->value = d[i];
		knode[i]->flag[0] = knode[i]->k_x;
		knode[i]->flag[1] = knode[i]->k_y;
	}
	

	//////////////////////////////////
	/////////////case 1///////////////
	//////////////////////////////////
	BSTTree t1;
	for (int i = 0; i < 16; i++)
	{
		t1.insert(node[i], t1.root);
	}
	t1.show(t1.root,"t1.dot");

	//////////////////////////////////
	/////////////case 2///////////////
	//////////////////////////////////
	KDTree k2;
	
	for (int i = 0; i < 16; i++)
	{
		k2.insert(knode[i], k2.root,0);
	}
	k2.show(k2.root,"t2.dot");

	//////////////////////////////////
	/////////////case 3///////////////
	//////////////////////////////////
	BSTTree t3;
	int array[200];
	int count=0;
	while (count < 200)
	{
		int j = rand() % 401;
		if (!contains(array, j, count))
		{
			array[count] = j;
			count++;
		}
	}

	for (int i = 0; i < 200; i++)
	{
		node[i]->key = array[i];
	}
	for (int i = 0; i < 50; i++)
	{
		t3.insert(node[i], t3.root);
	}
	
	cout << "n=No.of Nodes in the tree" << "   " << "Height of BST T3" << "   " << "lgn" << "   " << "";
	cout << "----------------------------------------------------------------------------------------------";
	cout << "                   " << 0 << "      " << t3.height(t3.root) << "     " << "N.A" << "     " << sqrt(0);
	for (int i = 20; i <=200; i=i+20)
	{
		double d, u;
		d = log10((double)i);
		u = sqrt(i);
		cout << "                   " << i << "      " << t3.height(t3.root) << "     " << d << "     " << u;

	}


}
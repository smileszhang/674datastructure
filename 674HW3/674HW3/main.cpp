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
bool contains1(int array[][2], int n,int l, int count)
{
	for (int i = 0; i <= count; i++)
	{
		if (array[i][0] == n&&array[i][1]==l)
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
	BSTNode *node2[200];
	for (int i = 0; i < 200; i++)
	{
		node2[i] = new BSTNode();
		node2[i]->key = array[i];
		node2[i]->value = d[i];
	}

	cout << "n=No.of Nodes in the tree" << "   " << "Height of BST T3" << "      " << "lgn" << "     " << "sqrt(n)" << endl;
	cout << "----------------------------------------------------------------------------------------------"<<endl;
	cout << "                   " << "0" << "         " << t3.height(t3.root)-1 << "          " << "N.A" << "           " << sqrt(0) << endl;
	for (int i = 0; i < 200; i++)
	{
		t3.insert(node2[i], t3.root);
		if ((i+1) % 20 == 0)
		{
			double d, u;
			d = log10((double)i);
			u = sqrt(i);
			cout << "                   " << i+1 << "         " << t3.height(t3.root) << "        " << d << "         " << u << endl;
		}
	}
	

	//////////////////////////////////
	/////////////case 4///////////////
	//////////////////////////////////
	KDTree k4;
	int array1[200][2];
	int count1 = 0;
	while (count1 < 200)
	{
		int j1 = rand() % 51;
		int w1 = rand() % 51;
		if (!contains1(array1, j1, w1,count1))
		{
			array1[count1][0] = j1;
			array1[count1][1] = w1;
			count1++;
		}
	}
	KDNode *knode1[200];
	for (int i = 0; i < 200; i++)
	{
		knode1[i] = new KDNode();
		knode1[i]->k_x = array1[i][0];
		knode1[i]->k_y = array1[i][1];
		knode1[i]->value = d[i];
	}
	cout << "n=No.of Nodes in the tree" << "   " << "Height of KD T4" << "      " << "lgn" << "     " << "sqrt(n)" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "                   " << "0" << "         " << k4.height(k4.root) - 1 << "          " << "N.A" << "           " << sqrt(0) << endl;
	for (int i = 0; i < 200; i++)
	{
		k4.insert(knode1[i], k4.root, 0);
		if ((i + 1) % 20 == 0)
		{
			double d, u;
			d = log10((double)i);
			u = sqrt(i);
			cout << "                   " << i + 1 << "         " << k4.height(k4.root) << "        " << d << "         " << u << endl;
		}
	}
	//////////////////////////////////
	/////////////case 5///////////////
	//////////////////////////////////
	BSTTree t5;
	BSTNode *node3[10];
	int array3[10];
	int count3 = 0;
	while(count3<10)
	{
		int j2 = rand() % 16;
		if (!contains(array3,j2,count3)) 
		{
			node3[count3] = new BSTNode();
			node3[count3]->key = node[j2]->key;
			node3[count3]->value = node[j2]->value;
			t5.insert(node3[count3], t5.root);
			count3++;
		}
	}
	t5.show(t5.root, "t5-a.dot");
	t5.deletenode(node3[0], t5.root);
	t5.show(t5.root, "t5-b.dot");
	
	//////////////////////////////////
	/////////////case 6///////////////
	//////////////////////////////////
	KDTree k6;
	KDNode *knode3[10];
	int array4[10][2];
	int count4 = 0;
	while (count4 < 10)
	{
		int j3 = rand() % 16;
		
		if (!contains1(array4, knode[j3]->k_x,knode[j3]->k_y, count4))
		{
			knode3[count4] = new KDNode();
			knode3[count4]->k_x = knode[j3]->k_x;
			knode3[count4]->k_y = knode[j3]->k_y;
			knode3[count4]->value = knode[j3]->value;
			k6.insert(knode3[count4], k6.root, 0);
			count4++;
		}
	}
	k6.show(k6.root, "t6-a.dot");
	k6.deletenode(k6.root, knode3[0]);
	k6.show(k6.root, "t6-b.dot");


	//////////////////////////////////
	/////////////case 7///////////////
	//////////////////////////////////
	BSTTree t7;
	BSTNode *node4[20];
	for (int i = 0; i < 10; i++)
	{
		node4[i] = new BSTNode();
		node4[i]->key = k[i + 1];
		node4[i]->value = d[i + 1];
	}
	for (int i = 10; i < 20; i++)
	{
		node4[i] = new BSTNode();
		node4[i]->key = k[i -9];
		node4[i]->value = d[i+1];
	}
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		t7.insert(node4[i], t7.root);
	}
	cout << "stage   " << "data item at root   " << "the root(after deletion)   " << "search for data with key"<<endl;
	
	
	
	for (int i = 0; i < 19; i++)
	{
		BSTNode *rt = t7.root;
		int rec = t7.root->key;
		cout << "  "<<i<< "        ["<<t7.root->key<<","<<t7.root->value << "]      ";
		t7.deletenode(rt, t7.root);
		cout << "     [" << t7.root->key<<","<< t7.root->value<< "]   ";
		if(t7.search(rec,t7.root)!=NULL)
			cout << "["<<t7.search(rec,t7.root)->key<<","<<t7.search(rec,t7.root)->value<<"]"<<endl;
		else
			cout <<"nil"<<endl;

		if (i == 10)
		{
			t7.show(t7.root, "t7.dot");
		}
	}
	cout << "  " << 19 << "        [" << t7.root->key << "," << t7.root->value << "]      ";
	cout << "      nil      "<<"    nil     "<<endl;
	//////////////////////////////////
	/////////////case 8///////////////
	//////////////////////////////////
	KDTree k8;
	KDNode *knode5[18];

	for (int pp = 0; pp < 6; pp++)
	{
		knode5[pp] = new KDNode();
		knode5[pp]->k_x = x[pp+1];
		knode5[pp]->k_y = y[pp+1];
		knode5[pp]->value = d[pp+1];
	}
	for (int i = 6; i < 12; i++)
	{
		knode5[i] = new KDNode();
		knode5[i]->k_x = x[i - 5];
		knode5[i]->k_y = y[i + 1];
		knode5[i]->value = d[i + 1];
	}
	for (int i = 12; i < 18; i++)
	{
		knode5[i] = new KDNode();
		knode5[i]->k_x = x[i - 5];
		knode5[i]->k_y = y[i - 11];
		knode5[i]->value = d[i + 1];
	}
	for (int i = 0; i < 18; i++)
	{
		k8.insert(knode5[i], k8.root,0);
	}
	cout << endl << "case 8"<<endl;
	int ii = 1;
	int count8 = 18;
	while (k8.root)
	{
		KDNode *kre=k8.root;
		k8.deletenode(k8.root,kre);
		count8--;
		if (k8.search(knode5[ii - 1]->k_x, knode5[ii - 1]->k_y, knode5[ii - 1]->value, k8.root, 0))
			cout << "[" << knode5[ii - 1]->k_x << "," << knode5[ii - 1]->k_y << "," << knode5[ii - 1]->value << "]"<<endl;
		ii++;
		if (count8 == 12)
			k8.show(k8.root, "t8-a.dot");
		if (count8 == 6)
			k8.show(k8.root, "t8-b.dot");
	}

}
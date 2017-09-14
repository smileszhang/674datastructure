#include<iostream>
#include"Data.h";

using namespace std;
//swap two data
void Data::swap(vector<Data> v, int i, int j)
{
	int tmp1 = v[i].key;
	int tmp2 = v[i].value;
	v[i].key = v[j].key;
	v[i].value = v[j].value;
	v[j].key = tmp1;
	v[j].value = tmp2;
}
//return the indice of leftchild
int Data::leftChild(int i)
{
	return 2 * i;
}
//return the indice of rightchild
int Data::rightChild(int i)
{
	return 2 * i + 1;
}
//return the indice of parent
int Data::parent(int i)
{
	return i / 2;
}

bool Data::comp(vector<Data> v, int i, int j)
{
	if (v[i].key < v[j].key)
	{
		return 1;
	}
	else return 0;
}
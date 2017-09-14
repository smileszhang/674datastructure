#include<iostream>
#include"Heap.h"
#include"Data.h"
#include<vector>

using namespace std;

void Heap::Min_heapify(vector<Data> &A, int i, int size)
{
	int min;
	int l = A[i].leftChild(i);
	int r = A[i].rightChild(i);
	if (l <= size&&A[l].key < A[i].key)
		min = l;
	else min = i;
	if (r <= size&&A[r].key < A[min].key)
		min = r;
	if (min != i)
	{
		swap(A[i], A[min]);
		Min_heapify(A, min, size); //for the rest element, doing min_heapify to maintain min-heap property of this node
	}
	
}

//to build a min-heap and maintain its property
void Heap::Build_min_heap(vector<Data> &A)
{
	for (int i = (A.size()-1) / 2; i > 0; i--)
	{
		Min_heapify(A, i,A.size()-1);
	}
}
// insert data into vector using push_back 
void Heap::Insert(vector<Data> &A, int key, int value)
{
	Data a;
	a.key = key;
	a.value = value;
	A.push_back(a);

}
// return the smallest key value
int Heap::All_minimun(vector<Data> &A)
{
	if (A.size() - 1 < 1)
	{
		cout << endl << "All_minimum: " << endl;
		cout << "heap underflow" << endl;
		return 0;
	}
	else
	{
		Build_min_heap(A);
		cout << endl << "All_minimum: " << endl;
		int min = A[1].key;
		for (int i = 1; i <= A.size() - 1; i++)
		{
			if (A[i].key == min)
				cout << "key,value: " << A[i].key << "," << A[i].value << endl;
		}
		return min;
	}
	
	
}
//decrease one data's key to a given value
void Heap::Decrease_key(vector<Data> &A, int i, int key)
{
	 if (key > A[i].key)
	{
		cout << "new key is larger than current key" << endl;
		return;
	}
	else
	{
		A[i].key = key;
		int p = A[i].parent(i);
		while (i > 1 && A[p].key > A[i].key)
		{
			Data tmp;
			tmp = A[i];
			A[i] = A[p];
			A[p] = tmp;
			i = p;
		}
	}
	
}

//print the smallest key value and delete that data
void Heap::Extract_all_min(vector<Data> &A)
{
	Build_min_heap(A);
	if (A.size() - 1 < 1)
	{

		cout << "heap underflow" << endl;
		return;
	}
	else
	{
		int min = A[1].key;
		cout << "key,value: " << A[1].key << "," << A[1].value << endl;
		A[1] = A[A.size() - 1];
		A.pop_back();
		//Min_heapify(A, 1, A.size()-1);

		for (int i = 1; i < A.size() - 1; i++)
		{
			if (A[i].key == min)
			{
				Extract_all_min(A);
			}
		}
	}
	
}
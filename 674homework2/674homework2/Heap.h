#pragma once
#include"Data.h"

class Heap
{
public:
	void Min_heapify(vector<Data> &A, int i, int size);
	void Build_min_heap(vector<Data> &A);
	void Insert(vector<Data> &A, int key, int value);
	int All_minimun(vector<Data> &A);
	void Decrease_key(vector<Data> &A, int i, int key);
	void Extract_all_min(vector<Data> &A);
	

};
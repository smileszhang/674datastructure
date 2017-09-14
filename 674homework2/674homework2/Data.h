#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Data
{
public:
	int key;
	int value;

	void swap(vector<Data> v, int i, int j);
	int leftChild(int i);
	int rightChild(int i);
	int parent(int i);
	bool comp(vector<Data> v, int i, int j);
};
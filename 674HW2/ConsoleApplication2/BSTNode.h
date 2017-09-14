#pragma once
#include<iostream>

using namespace std;
class BSTNode
{
public:
	BSTNode *leftlink;
	BSTNode *rightlink;
	int key;
	int value;
	BSTNode() {
		leftlink = nullptr;
		rightlink = nullptr;
	}
};
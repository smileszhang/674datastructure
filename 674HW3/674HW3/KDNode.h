#pragma once
#include<iostream>

using namespace std;
class KDNode
{
public:
	KDNode *leftlink;
	KDNode *rightlink;
	int k_x;
	int k_y;
	int value;
	int flag;
	KDNode() {
		leftlink =NULL;
		rightlink = NULL;
	}
};
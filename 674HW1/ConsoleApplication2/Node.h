#pragma once
#include<iostream>

//single node  class
class Node {
public:
	int data;       //Node's data  
	Node *next;     //point to next node 
	Node(int _data) {  //construct function, giving data and next point when creating a new node
		data = _data;
		next = NULL;
	}
};


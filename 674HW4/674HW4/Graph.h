#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <stdio.h>
#include<vector>
using namespace std;
class Node 
{
public:
	
	string color;
	string name;
	Node* next;
	Node* predecessor;
	int distance;

};

class Edge
{
public:
	string color;
	int weight;
	Node* origin;
	Node* dest;


};

class uGraph
{
public:
	vector<Node*> G;
	vector<Edge> Edges;

	uGraph();
	uGraph(string name);
	void addVzimu(string v);
	void show(string name);
	string preto_string();
	void addedge(Node *u,Node *i);
	void remove_e(Node *n, Node *m);
	void remove_v(Node *n);
	Node * find(string n);
	string preto_string2();
	void show2(string name);
};

class dGraph
{
public:
	vector<Node*> G;
	vector<Edge> Edges;

	dGraph();
	dGraph(string name);
	dGraph(string name,int flag);
	void addVzimu(string v);
	void show(string name);
	string preto_string();
	string preto_string2();
	void show2(string name);
	void addedge(Node *u, Node *i);
	void remove_e(Node *n, Node *m);
	void remove_v(Node *n);
	Node * find(string n);
	void initSingleSource(string s);
	void relax(string u);
	void DIJSKSRA(string s);
};
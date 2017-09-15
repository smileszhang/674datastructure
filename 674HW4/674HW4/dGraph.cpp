#include<iostream>
#include"Graph.h"
#include <sstream>
#include <fstream>
#include <stdio.h>

using namespace std;

dGraph::dGraph()
{
	Node* newNode = new Node;
	newNode->color = "null";
	newNode->name = "null";
	newNode->next = 0;
	newNode->predecessor = 0;
	G.push_back(newNode);

}
dGraph::dGraph(std::string name)
{
	std::vector<std::vector<std::string>> nline;//hole matrix in vector of vector of string
	std::vector<std::string> line;//hole one line of matrix in string
	std::vector<std::vector<int>> matrix;
	std::vector<string> numLine;

	std::ifstream in(name);

	char buffer[256];
	while (!in.eof())
	{
		in.getline(buffer, 256, '\n');//store one line in buffer per time
		size_t p = 0;
		std::string num;
		while (true)//store the number in this line
		{
			if (buffer[p] != ',' && buffer[p] != '\0')
				num += buffer[p];
			else if (buffer[p] == ',' || buffer[p] == '\0')
			{
				line.push_back(num);
				num.clear();
			}
			if (buffer[p] == '\0')
				break;
			p++;
		}
		if (line.size()>1)
			nline.push_back(line);
		line.clear();//clean the tem line
	}


	//add a null to the list 0 position
	Node* newNode = new Node;
	newNode->color = "null";
	newNode->name = "null";
	newNode->next = 0;
	newNode->predecessor = 0;
	G.push_back(newNode);
	//add vertex to the list

	for (size_t i = 1; i < nline.size(); i++)
	{
		string a = nline[0][i];
		addVzimu(a);
	}

	//add edge to the list
	for (size_t i = 1; i < nline.size(); i++)
	{
		numLine = nline[i];
		for (size_t j = 1; j < nline.size(); j++)
		{
			stringstream ss;
			int k;
			ss << numLine[j];
			ss >> k;
			if (k > 0)
			{
				Edge e;
				e.origin = G[i];
				e.dest = G[j];
				e.weight = 0;
				Edges.push_back(e);

				//addE(i, j);
				//addEWeight(i, j, k);
				//addEWeight(j, i, k);
			}
		}
	}
}
//weighted graph
dGraph::dGraph(std::string name,int flag)
{
	std::vector<std::vector<std::string>> nline;//hole matrix in vector of vector of string
	std::vector<std::string> line;//hole one line of matrix in string
	std::vector<std::vector<int>> matrix;
	std::vector<string> numLine;

	std::ifstream in(name);

	char buffer[256];
	while (!in.eof())
	{
		in.getline(buffer, 256, '\n');//store one line in buffer per time
		size_t p = 0;
		std::string num;
		while (true)//store the number in this line
		{
			if (buffer[p] != ',' && buffer[p] != '\0')
				num += buffer[p];
			else if (buffer[p] == ',' || buffer[p] == '\0')
			{
				line.push_back(num);
				num.clear();
			}
			if (buffer[p] == '\0')
				break;
			p++;
		}
		if (line.size()>1)
			nline.push_back(line);
		line.clear();//clean the tem line
	}


	//add a null to the list 0 position
	Node* newNode = new Node;
	newNode->color = "null";
	newNode->name = "null";
	newNode->next = 0;
	newNode->predecessor = 0;
	G.push_back(newNode);
	//add vertex to the list

	for (size_t i = 1; i < nline.size(); i++)
	{
		string a = nline[0][i];
		addVzimu(a);
	}

	//add edge to the list
	for (size_t i = 1; i < nline.size(); i++)
	{
		numLine = nline[i];
		for (size_t j = 1; j < nline.size(); j++)
		{
			stringstream ss;
			int k;
			ss << numLine[j];
			ss >> k;
			if (k > 0)
			{
				Edge e;
				e.origin = G[i];
				e.dest = G[j];
				e.weight = k;
				Edges.push_back(e);

				//addE(i, j);
				//addEWeight(i, j, k);
				//addEWeight(j, i, k);
			}
		}
	}
}

void dGraph::addVzimu(string v)
{
	for (size_t i = 0; i < G.size(); i++)
	{
		if (G[i]->name == v)
			return;
	}
	Node* newNode = new Node;
	newNode->name = v;
	newNode->next = 0;
	G.push_back(newNode);
}
void dGraph::addedge(Node *u, Node *i)
{
	Edge e;
	e.origin = u;
	e.dest = i;

	
	Edges.push_back(e);
	

}

void dGraph::remove_e(Node *n, Node *m)
{

	for (int i = 0; i < Edges.size(); i++)
	{
		if (Edges[i].origin == n&&Edges[i].dest == m)
		{
			Edge tmp;
			tmp = Edges[i];
			Edges[i] = Edges[Edges.size() - 1];
			Edges[Edges.size() - 1] = tmp;
			break;
		}

	}

	Edges.pop_back();
}

void dGraph::remove_v(Node *n)
{
	Node *tmp;
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i] == n)
		{
			tmp = G[i];
			G[i] = G[G.size() - 1];
			G[G.size() - 1] = tmp;
			break;
		}
	}
	int i = 0, j = 0;
	for (i; i < Edges.size(); i++)
	{
		if (Edges[i].origin == n&&Edges[i].dest != NULL)
		{
			remove_e(G[G.size() - 1], Edges[i].dest);
			i = 0;
			continue;
		}
	}
	for (j; j < Edges.size(); j++)
	{
		if (Edges[j].dest == n&&Edges[j].origin != NULL)
		{
			remove_e(Edges[j].origin, G[G.size() - 1]);
			j = 0;
			continue;
		}

	}

	G.pop_back();
}

void dGraph::show(string name)
{
	ofstream outfile;
	outfile.open(name);
	if (outfile.is_open())
	{
		outfile << "digraph G {\n";
		outfile << preto_string();
		outfile << "}" << endl;
		outfile.close();
	}
}

void dGraph::show2(string name)
{
	ofstream outfile;
	outfile.open(name);
	if (outfile.is_open())
	{
		outfile << "digraph G {\n";
		outfile << preto_string2();
		outfile << "}" << endl;
		outfile.close();
	}
}

string dGraph::preto_string()
{
	string s = "";
	for (int i = 0; i < Edges.size(); i++)
	{
		Edge ed = Edges[i];
		Node* tem = ed.origin;
		Node* tem2 = ed.dest;
		s += tem->name + " -> " + tem2->name + "\n";
	}
	return s;
}

string dGraph::preto_string2()
{
	string s = "";
	for (int i = 0; i < Edges.size(); i++)
	{
		Edge ed = Edges[i];
		Node* tem = ed.origin;
		Node* tem2 = ed.dest;
		s += tem->name + " -> " + tem2->name + " [" + "label=" + "\""+to_string(ed.weight)+"\"" + "]" + "\n";

	}
	return s;
}

Node * dGraph::find(string n)
{
	for (size_t i = 0; i < G.size(); i++)
	{
		if (G[i]->name == n)
		{
			return G[i];
		}
	}

}




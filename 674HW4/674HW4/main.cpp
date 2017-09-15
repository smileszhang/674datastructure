#include "Graph.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stack> 
#include <sstream>
#include<string>
#include<fstream>

using namespace std;


int main()
{
//test case1
	uGraph G1("fig1.csv");
	G1.show("t1.dot");
//test case2
	dGraph G2("fig2.csv");
	G2.show("t2.dot");
//test case3
	dGraph G3_1("fig3.csv",1);
	G3_1.show("t3-1.dot");

	dGraph G3_2("fig3-w.csv",1);
	G3_2.show2("t3-2.dot");

//test case4
	Node *z=new Node;
	z->name = "z";
	G1.addVzimu(z->name);

	G1.addedge(z, G1.find("w"));
	G1.addedge(z, G1.find("x"));
	G1.addedge(z, G1.find("y"));

	G1.show("t4a.dot");
	G1.remove_v(G1.find("s"));
	G1.remove_v(G1.find("x"));
	G1.remove_e(G1.find("u"), G1.find("t"));
	G1.remove_e(G1.find("t"), G1.find("u"));
	G1.show("t4b.dot");

//test case 5
	uGraph Ue;
	Ue.addVzimu("6");
	Ue.addVzimu("7");
	Ue.addVzimu("8");
	Ue.addVzimu("9");
	Ue.addVzimu("10");
	Ue.addedge(Ue.find("6"), Ue.find("7"));
	Ue.addedge(Ue.find("7"), Ue.find("8"));
	Ue.addedge(Ue.find("8"), Ue.find("9"));
	Ue.addedge(Ue.find("9"), Ue.find("10"));
	Ue.addedge(Ue.find("10"), Ue.find("6"));
	Ue.addVzimu("1");
	Ue.addVzimu("2");
	Ue.addVzimu("3");
	Ue.addVzimu("4");
	Ue.addVzimu("5");
	Ue.addedge(Ue.find("1"), Ue.find("6"));
	Ue.addedge(Ue.find("2"), Ue.find("7"));
	Ue.addedge(Ue.find("3"), Ue.find("8"));
	Ue.addedge(Ue.find("4"), Ue.find("9"));
	Ue.addedge(Ue.find("5"), Ue.find("10"));
	Ue.show("t5a.dot");
	Ue.remove_v(Ue.find("8"));
	Ue.remove_v(Ue.find("6"));
	Ue.show("t5b.dot");

//test case6
	dGraph De;
	De.addVzimu("6");
	De.addVzimu("10");
	De.addVzimu("2");
	De.addVzimu("4");
	De.addVzimu("8");
	De.addedge(De.find("2"), De.find("4"));
	De.addedge(De.find("2"), De.find("6"));
	De.addedge(De.find("4"), De.find("6"));
	De.addedge(De.find("4"), De.find("8"));
	De.addedge(De.find("6"), De.find("8"));
	De.addedge(De.find("6"), De.find("10"));
	De.addedge(De.find("8"), De.find("10"));
	De.addedge(De.find("8"), De.find("2"));
	De.addVzimu("1");
	De.addVzimu("3");
	De.addVzimu("5");
	De.addVzimu("7");
	De.addVzimu("9");
	De.addedge(De.find("1"), De.find("2"));
	De.addedge(De.find("3"), De.find("4"));
	De.addedge(De.find("5"), De.find("6"));
	De.addedge(De.find("7"), De.find("8"));
	De.addedge(De.find("9"), De.find("10"));
	De.show("t6a.dot");
	De.remove_v(De.find("8"));
	De.remove_v(De.find("7"));
	De.show("t6b.dot");


//test case6
	uGraph G4;
	G4.Edges = G3_2.Edges;
	for (int i = 0; i < G3_2.Edges.size(); i++)
	{
		for (int j = 0; j < G3_2.Edges.size(); j++)
		{
			if (G3_2.Edges[i].origin == G3_2.Edges[j].dest&&G3_2.Edges[i].dest == G3_2.Edges[j].origin)
				if (G3_2.Edges[i].weight <= G3_2.Edges[j].weight)
					G4.Edges[i].weight = G3_2.Edges[i].weight;
				else
					G4.Edges[i].weight = G3_2.Edges[j].weight;
		}
	}

	G4.show2("t7.dot");

}




#include<iostream> 
#include<cstdlib>
#include <stdlib.h> 
#include <time.h>  
#include"Node.h"
#include"LinkList.h"
#include"List.h"
#include"ListNode.h"
using namespace std;


int main() {
	int input;
	while (1)

	{
		cout <<endl<< "This is Shiyang Zhang's Homework 1" << endl;
		cout << "Operation choosing:  " << "1.Test" << "     " << "2.Quit" << endl << endl;
		cin >> input;
		if (input == 1)
		{
			LinkList linkListS1; //sequential single linked list .   1,2,..100
			LinkList linkListS2; //a pseudo-random sequence of distinct numbers of length 100 of single linked list
			List L1;   //sequential double linked list .   1,2,..100
			List L2; // a pseudo - random sequence of distinct numbers of length 100 of double linked list


					 //data formation
			for (int i = 1; i <= 100; i++) {   //
				Node *node = new Node(i);      //use new to allocate new space for every node
				linkListS1.Insert(node, i - 1);     //use Insert() member function to evaluate each node
			}


			srand(time(NULL));     //S2 is a random data singlelinklist
			int a[100];
			for (int i = 0; i < 100; i++)
			{
				a[i] = rand()%1000;
				int j = a[i];
				Node *node = new Node(j);    //use new to allocate new space for every node
				linkListS2.Insert(node, i - 1);  //use Insert() member function to evaluate each node
			}


			//L1 is a sequential double linked list
			for (int i = 1; i <= 100; i++)
			{
				L1.PushBack(i);
			}


			//L2 is a random double linked list
			srand(time(NULL));
			int b[100];
			for (int i = 0; i < 100; i++)
			{
				b[i] = rand()%1000;
				int j = b[i];
				Node *node = new Node(j);
				L2.PushBack(j);
			}


			cout << "case 1: Singly linked list-----Team of four-----S1 " << endl;
			cout << "case 2: Doubly linked list-----Team of four-----S1 " << endl;
			cout << "case 3: Singly linked list-----Team of four-----S2 " << endl;
			cout << "case 4: Doubly linked list-----Team of four-----S2 " << endl;
			cout << "case 5: Singly linked list-----Reverse-----S1 " << endl;
			cout << "case 6: Doubly linked list-----Reverse-----S1 " << endl;
			cout << "case 7: Singly linked list-----Reverse-----S2 " << endl;
			cout << "case 8: Doubly linked list-----Reverse-----S2 " << endl;
			cout << "case 9: Singly linked list-----Shuffle-----S1 " << endl;
			cout << "case 10: Doubly linked list-----Shuffle-----S1 " << endl;
			cout << "case 11: Singly linked list-----Shuffle-----S2 " << endl;
			cout << "case 12: Doubly linked list-----Shuffle-----S2 " << endl;

			cout << endl;
			cout << "Please input case number:";

			//User choose case
			int w;
			cin >> w;
			cout << endl;

			switch (w)
			{
			case 1:
			{
				cout << "Singly linked list-----Team of four-----S1" << endl << endl;
				linkListS1.outputbyfour(linkListS1.head);
				cout <<endl<< "After Operation:" << endl << endl;
				linkListS1.teamoffour();
				linkListS1.outputbyfour(linkListS1.head);
				break;
			}
			case 2:
			{
				cout << "Doubly linked list-----Team of four-----S1 " << endl << endl;
				//L1.PrintList(L1._head);
				L1.outputbyfour(L1._head);
				cout << endl << "After Operation:" << endl << endl;
				L1.teamoffour();
				L1.outputbyfour(L1._head);
				break;
			}
			case 3:
			{
				cout << "Singly linked list-----Team of four-----S2 " << endl << endl;
				linkListS2.outputbyfour(linkListS2.head);
				cout << endl << "After Operation:" << endl << endl;
				linkListS2.teamoffour();
				linkListS2.outputbyfour(linkListS2.head);
				break;
			}
			case 4:
			{
				cout << "Doubly linked list-----Team of four-----S2 " << endl << endl;
				L2.outputbyfour(L2._head);
				cout << endl << "After Operation:" << endl << endl;
				L2.teamoffour();
				L2.outputbyfour(L2._head);
				break;
			}
			case 5:
			{
				cout << "Singly linked list-----Reverse-----S1 " << endl << endl;
				linkListS1.outputbyfour(linkListS1.head);
				cout << endl << "After Operation:" << endl << endl;
				linkListS1.Reverse_order();
				linkListS1.outputbyfour(linkListS1.head);
				break;
			}
			case 6:
			{
				cout << "Doubly linked list-----Reverse-----S1 " << endl << endl;
				L1.outputbyfour(L1._head);
				cout << endl << "After Operation:" << endl << endl;
				L1.Reverse();
				L1.outputbyfour(L1._head);
				break;
			}
			case 7:
			{
				cout << "Singly linked list-----Reverse-----S2 " << endl << endl;
				linkListS2.outputbyfour(linkListS2.head);
				cout << endl << "After Operation:" << endl << endl;
				linkListS2.Reverse_order();
				linkListS2.outputbyfour(linkListS2.head);
				break;
			}
			case 8:
			{
				cout << "Doubly linked list-----Reverse-----S2 " << endl << endl;
				L2.outputbyfour(L2._head);
				cout << endl << "After Operation:" << endl << endl;
				L2.Reverse();
				L2.outputbyfour(L2._head);
				break;
			}
			case 9:
			{
				cout << "Singly linked list-----Shuffle-----S1 " << endl << endl;
				linkListS1.outputbyfour2();
				cout << endl << "After Operation:" << endl << endl;
				linkListS1.shuffle();
				linkListS1.outputbyfour(linkListS1.head);
				break;
			}
			case 10:
			{
				cout << "Doubly linked list-----Shuffle-----S1 " << endl << endl;
				L1.outputbyfour2();
				cout << endl << "After Operation:" << endl << endl;
				L1.shuffle();
				L1.outputbyfour(L1._head);
				break;
			}
			case 11:
			{
				cout << "Singly linked list-----Shuffle-----S2 " << endl << endl;
				linkListS2.outputbyfour2();
				cout << endl << "After Operation:" << endl << endl;
				linkListS2.shuffle();
				linkListS2.outputbyfour(linkListS2.head);
				break;
			}
			case 12:
			{
				cout << "Doubly linked list-----Shuffle-----S2 " << endl << endl;
				L2.outputbyfour2();
				cout << endl << "After Operation:" << endl << endl;
				L2.shuffle();
				L2.outputbyfour(L2._head);
				break;
			}

		defult:
			cout << "MISTAKE!" << endl;
			break;

			}

		}

		else
			return 0;



	}

}



	


#include <iostream>
#include"Data.h"
#include"Heap.h"
#include<vector>
#include<time.h> 
using namespace std;


int main()
{
	/////////////////////////////////////////////
	/////////          case 1             ///////
	//////////////////////////////////////////////
	Heap p1;
	vector<Data> A1;
	int j1 = 1;   //value
	int k1 = 100; //key
	Data a1;
	a1.key = 0; //initialize A[0]
	a1.value = 0;
	A1.push_back(a1);
	for (int i = 1; i <= 100; i++)
	{
		p1.Insert(A1, k1, j1);
		j1 = j1 + 1;
		k1 = k1 - 1;
	}
	cout << "case 1:" << endl << endl;
	cout << endl << "Extract_all_min£º" << endl;
	p1.Extract_all_min(A1);
	p1.Insert(A1, 1, 0);
	cout << endl << "Extract_all_min£º" << endl;
	p1.Extract_all_min(A1);
	cout << endl;
	/////////////////////////////////////////////
	/////////          case 2             ///////
	//////////////////////////////////////////////
	Heap p2;
	vector<Data> A2;
	int j2 = 1;   //value
	int k2 = 1000; //key
	Data a2;
	a2.key = 0; //initialize A[0]
	a2.value = 0;
	A2.push_back(a2);
	for (int i = 1; i <= 1000; i++)
	{
		p1.Insert(A2, k2, j2);
		j2 = j2 + 1;
		k2 = k2 - 1;
	}
	cout << "case 2:" << endl << endl;
	p2.All_minimun(A2);
	
	for (int i = 1; i <= 30; i++)
	{
		p2.Insert(A2, 1, i);
	}
	cout << endl << "Extract_all_min£º" << endl;
	p2.Extract_all_min(A2);
	p2.All_minimun(A2);
	cout << endl;

	/////////////////////////////////////////////
	/////////          case 3             ///////
	//////////////////////////////////////////////

	Heap p3;
	vector<Data> A3;

	Data a3;
	a3.key = 0; 
	a3.value = 0;
	A3.push_back(a3);


	srand(time(NULL));
	for (int i = 1; i <= 500; i++)
	{
		p3.Insert(A3, rand() % (1000 - 10 + 1) + 10, rand() % (1000 - 10 + 1) + 10);
		//cout << endl << A3[i].key << ","<<A3[i].value << endl;
	}
	cout << "case 3:" << endl << endl;
	cout << endl << "Extract_all_min£º" << endl;
	p3.Extract_all_min(A3);
	cout << endl << "Extract_all_min£º" << endl;
	p3.Extract_all_min(A3);
	cout << endl << "Extract_all_min£º" << endl;
	p3.Extract_all_min(A3);
	cout << endl << "Extract_all_min£º" << endl;
	p3.Extract_all_min(A3);
	cout << endl << "Extract_all_min£º" << endl;
	p3.Extract_all_min(A3);

	p3.Decrease_key(A3, rand() % 500, 5);
	p3.All_minimun(A3);

	/////////////////////////////////////////////
	/////////          case 4             ///////
	/////////////////////////////////////////////
	Heap p4;
	vector<Data> A4;

	Data a4;
	a4.key = 0;
	a4.value = 0;
	A4.push_back(a4);

	cout << endl << "case 4:" << endl << endl;
	srand(time(NULL));
	for (int i = 1; i <= 500; i++)
	{
		p4.Insert(A4, rand() % (1000 - 10 + 1) + 10, rand() % (1000 - 10 + 1) + 10);
		//cout << endl << A3[i].key << ","<<A3[i].value << endl;
	}
	
	for (int i = 1; i <= 10; i++)
	{
		p4.Decrease_key(A4, rand() % (500-1+1)+1, rand() % (8-1+1)+1);
	}
	for (int i = 1; i <= 10; i++)
	{
		cout << endl << "Extract_all_min£º" << endl;
		p4.Extract_all_min(A4);
	}

	/////////////////////////////////////////////
	/////////          case 5             ///////
	/////////////////////////////////////////////

	Heap p5;
	vector<Data> A5;

	Data a5;
	a5.key = 0;
	a5.value = 0;
	A5.push_back(a5);

	cout << endl << "case 5:" << endl << endl;
	srand(time(NULL));
	
	int count = 0;
	for (int i = 1; i <= 100; i++)
	{
		int s = rand() % (4 - 1 + 1) + 1;
	
		switch(s)
		{
		case 1:
			cout <<endl<< "Insert:" << endl;
			p5.Insert(A5, rand() % (1000 - 10 + 1) + 10, rand() % (1000 - 10 + 1) + 10);
			break;
		case 2:
			if (A5.size() - 1 < 1)
			{
				cout<<endl << "Decrease_key:" << endl;
				cout << "heap underflow" << endl;
			}
			else
			{
				cout <<endl<< "Decrease_key:" << endl;
				p5.Decrease_key(A5, rand() % (A5.size() - 1 - 1 + 1) + 1, rand()%(p5.All_minimun(A5)-1+1)+1);
			}
			
			break;
		case 3:
			p5.All_minimun(A5);
			break;
		case 4:
			cout << endl << "Extract_all_min£º" << endl;
			p5.Extract_all_min(A5);
			break;
		}	
		count++;
		if (count == 20)
		{
			for (int j = 1; j <= A5.size() - 1; j++)
			{
				cout <<endl<< "[" << A5[j].key << "," << A5[j].value << "]";
			}
			count = 0;
			cout << endl;
		}
	}

	return 0;

}


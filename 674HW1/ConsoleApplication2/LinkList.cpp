#include<iostream> 
#include "LinkList.h"
#include"Node.h"

using namespace std;

//single linked list cpp
void LinkList::Insert(Node *node, int position) {     //position is a location  
	if (head == NULL)
	{                
		head = node;             
		return;                 
							

	}
	if (position == 0)			 //if the position=0, this node is new head,put head points to it
	{     
							  
		node->next = head;
		head = node;           
		return;

	}
	Node *current_node = head;     //From head  
	int i = 0;                    
	while (current_node->next != NULL && i < position - 1) 
	{
	
		current_node = current_node->next;              
		i++;
	}
	if (i == position - 1) {           //the node is the last one
		node->next = current_node->next;
		current_node->next = node;
	}
}

//output data
void LinkList::Output(Node* node) {
	if (head == NULL) {
		return;       //  
	}
	Node *current_node = node;     //From head node  
	while (current_node != NULL) {
		cout << current_node->data << " ";
		current_node = current_node->next;
	}
	cout << endl;
	//system("pause");
}

void LinkList::Reverse_order() {
	if (head == NULL) {
		return;       // linklist is a null linklist  
	}
	Node *current_node = head->next, *next_node;     //Travelling from the head  
	head->next = NULL;
	while (current_node != NULL) {
		next_node = current_node->next;    //record the location of next node of current node  
		current_node->next = head;		//reverse current node and previous node
		head = current_node;		
		current_node = next_node;
	}
}

//4 data will be output each line
void LinkList::outputbyfour(Node *node)
{
	Node *tmp = head;
	int n = 0;
	for (int i = 0; i < 400; i++)
	{
		if (i % 4 == 0)
		{
			cout << tmp->data << ",";
			tmp = tmp->next;
			n++;
		}
		if (n == 4)
		{
			cout << endl;
			n = 0;
		}
	}
	//system("pause");
}

// output data in two groups
void LinkList::outputbyfour2()
{
	Node *tmp = head;
	int n = 0;
	cout << "**first half**" << endl;
	for (int i = 0; i < 200; i++)
	{
		if (i % 4 == 0)
		{
			cout << tmp->data << ",";
			tmp = tmp->next;
			n++;
		}
		if (n == 4)
		{
			cout << endl;
			n = 0;
		}
	}

	cout << endl << "**second half**" << endl;
	for (int i = 0; i < 200; i++)
	{
		if (i % 4 == 0)
		{
			cout << tmp->data << ",";
			tmp = tmp->next;
			n++;
		}
		if (n == 4)
		{
			cout << endl;
			n = 0;
		}
	}
	//system("pause");
}


void LinkList::teamoffour()
{
	Node *p1 = head, *p2 = head, *next_node2 = p2->next,*next_node1=p1->next;     //From head node  
	Node* cur = head;
	Node *wait =head;
	
	//devide 100 node into 25 groups, sorting each group
	for (int j = 0; j < 25; j++)
	{

		// p2 points to the last node in a group
		for (int i = 0; i < 3; i++)
		{
			next_node2 = p2->next;
			p2 = next_node2;
		}
	
		next_node2 = p2->next;
		p2->next = NULL;    //if p2!=NULL, the rest node will be sorted as well
		
		p1 = insertionSortList(p1);
		if (j != 0)
		{
			wait->next = p1;		//previuos group's last data -> present group's first data
		}
		
		p2 = p1->next->next->next;	//p2 points to the last node after sorting
		
		p2->next = next_node2;		// 
		wait = p2;
	

		if (j == 0)
			head = p1;			//head alway points to the first node in the whole linklist

		p1 = next_node2;
		p2 = p1;
	}
	
}




void LinkList::shuffle()
{
	Node *current_node = head, *next_node2, *next_node3;     //From the head node  
	Node *head2, *head3;
		head2 = current_node;
		head3 = current_node;

		//put head3 at thev51th positioin
		for (int i = 0; i < 50; i++)
		{
			next_node3 = current_node->next;
			head3 = next_node3;
			current_node = next_node3;
		}
		
		
		//head2->head3->next-node2->next_node3
		for(int i=0;i<50;i++)
		{
			next_node2 = head2->next;
			next_node3 = head3->next;
			current_node = head2;
			current_node->next = head3;
			current_node = head3;
			current_node->next = next_node2;
			if (i == 49)
			{
				current_node->next = NULL;
				continue;
			}
			current_node = next_node2;
			head2 = next_node2;
			head3 = next_node3;
			
		}
		
}






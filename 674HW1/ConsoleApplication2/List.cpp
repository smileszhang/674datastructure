#include<iostream>
#include"List.h"
#include<assert.h>
using namespace std;

//output data
void List::PrintList(ListNode* node)
{
	ListNode* cur = node;
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->_next;
	}
	cout << "NULL" << endl;
	//system("pause");
}

void List::PushBack(DataType x)// Insert data in a new List
{
	if (NULL == _head)
	{
		_head = new ListNode(x);
		_tail = _head;
	}
	else
	{
		ListNode* tmp = new ListNode(x);
		_tail->_next = tmp;
		tmp->_prev = _tail;
		tmp->_next = NULL;
		_tail = tmp;
	}
}


//4 data will be output each line
void List::outputbyfour(ListNode *node)
{
	ListNode *tmp = _head;
	int n = 0;
	for (int i = 0; i < 400; i++)
	{
		if (i % 4 == 0)
		{
			cout << tmp->_data << ",";
			tmp = tmp->_next;
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
void List::outputbyfour2()
{
	ListNode *tmp = _head;
	int n = 0;
	cout << "**first half**" << endl;
	for (int i = 0; i < 200; i++)
	{
		if (i % 4 == 0)
		{
			cout << tmp->_data << ",";
			tmp = tmp->_next;
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
			cout << tmp->_data << ",";
			tmp = tmp->_next;
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


void List::Reverse()
{
	ListNode *temp = NULL;
	ListNode *current = _head;

	//exchange prev and next of each node  

	while (current != NULL)
	{
		temp = current->_prev; //record the previous node 
		current->_prev = current->_next;  //assign the next node to the previous node
		current->_next = temp;				// assign the previous node to next node
		current = current->_prev; // loop to next node  
	}

	// handle previous node first, these operation only aims at current node, 

	
	if (temp != NULL)
		_head = temp->_prev; //now _head points to null
	
}

void List::shuffle()
{
	ListNode *head2 = _head; 
	ListNode *head3 = _head;
	ListNode *next_node2, *next_node3, *tmp=_head;
	

	for (int i = 0; i < 50; i++)
	{	
		head3 = head2->_next;
		head3->_prev = head2;
		head2 = head3;
	}
	
	
	head2 = _head;
	
	
	while (head3 != NULL)
	{
		//save next node of head2 and head3
		//the sequence is head2->-<head3-><-next_node2-><-next_node3
		next_node2 = head2->_next;   
		next_node2->_prev = head2;
		next_node3 = head3->_next;
		if (next_node3 != NULL)
			next_node3->_prev = head3;
		else break;
		head2->_next = head3;
		head3->_prev = head2;
		head3->_next = next_node2;
		next_node2->_prev = head3;
		head2 = next_node2;
		head3 = next_node3;
	}
	head2->_next = head3;
	head3->_prev = head2;
	head3->_next = NULL;
		


}

void List::teamoffour()
{
	ListNode *p1 = _head, *p2 = _head, *next_node2 = p2->_next;     //From the head  
	next_node2->_prev = p2;
	ListNode *wait = _head;

	for (int j = 0; j < 25; j++)
	{

		// put the location between p2 and p1 equals to 4
		p2 = p1->_next->_next->_next;
		p2->_prev = p1->_next->_next;
		
		
		next_node2 = p2->_next;   //save next_node
		if (next_node2 != NULL)	  //if next_node2=NULL, do not need prev
		next_node2->_prev = p2;
		p2->_next = NULL;
		p1 = insertionSortList1(p1);  //sort 4 data
		if (j != 0)						//when the next sequence soring well, the previous points to the latter.
		{
			wait->_next = p1;
			p1->_prev = wait;
		}

		p2 = p1->_next->_next->_next;	//p1 points to the head, p2 points to the tail
		p2->_prev = p1->_next->_next;

		p2->_next = next_node2; 
		if (next_node2 != NULL)
		next_node2->_prev = p2;
		wait = p2;


		if (j == 0)
			_head = p1;


		p1 = next_node2;			//new sequence sorting,reassign new head pointer.
		p2 = p1;
	}

}
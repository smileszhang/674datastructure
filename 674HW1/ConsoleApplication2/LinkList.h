#pragma once
#include<iostream>
#include"Node.h"

//single linked list class
class LinkList {
public:
	LinkList() {
		head = NULL;    //This is a construct function,when LinkList is created, head=NULL
					 
	}
	void Insert(Node *node, int position);  
	void Output(Node *node);
	void Reverse_order();
	void outputbyfour(Node *node);
	void outputbyfour2();
	void teamoffour();
	void shuffle();

	Node *head;     
	Node *insertionSortList(Node *head) {		//insertion sorting method
		{
			// IMPORTANT: Please reset any member data you declared, as
			// the same Solution instance will be reused for each test case.
			if (head == NULL || head->next == NULL)return head;
			Node *p = head->next, *pstart = new Node(0), *pend = head;
			pstart->next = head; //pstart is in order to keep the head node.
			while (p != NULL)
			{
				Node *tmp = pstart->next, *pre = pstart;
				
				//if node's data is bigger than previous node's data,give it  right position
					while (tmp != p && p->data >= tmp->data) 
					{
						tmp = tmp->next;				
						pre = pre->next;
					}
					if (tmp == p)pend = p;
					else
					{
						pend->next = p->next;
						p->next = tmp;
						pre->next = p;
					}
					p = pend->next;
			}
			

			head = pstart->next;
			delete pstart;
			return head;
		}
	}
};

#pragma once
#include<iostream>
#include"ListNode.h"

//double linked likst class
class List
{
public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{}
	
	List(const List& s)
		:_head(NULL)
		, _tail(NULL)
	{
		ListNode* tmp = s._head;
		while (tmp)
		{
			this->PushBack(tmp->_data);
			tmp = tmp->_next;
		}
	}

public:

	void PrintList(ListNode* node);
	void PushBack(DataType x); // Insert node
	void Insert(ListNode* pos, DataType x);
	void outputbyfour(ListNode *node);
	void shuffle();
	void Reverse();
	void teamoffour();
	void outputbyfour2();

	ListNode *insertionSortList1(ListNode *head) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (head == NULL || head->_next == NULL)return head;
		ListNode *p = head->_next, *pstart = new ListNode(0), *pend = head, *p_next = p->_next;
		pstart->_next = head; //pstart is in order to keep the head node.
		while (p != NULL)
		{
			ListNode *tmp = pstart->_next, *pre = pstart;
			ListNode* pend_copy = pend;
			//if node's data is bigger than previous node's data,give it  right position
			while (tmp != p && p->_data >= tmp->_data)
			{
				tmp = tmp->_next; pre = pre->_next;
			}
			if (tmp == p)pend = p;
			else
			{	
				//insert the data into right location
				//pre->tmp->pend->p ,sometimes tmp=pend
				pend->_next = p->_next;
				p_next->_prev = pend;
				p->_next = tmp;
				tmp->_prev = p;
				pre->_next = p;
				p->_prev = pre;
			}
		
			
				p = pend->_next;
				if (p != NULL)
				{
					p->_prev = pend_copy;
				}
				
			
			
		}
		head = pstart->_next;
		head->_prev = pstart;
		delete pstart;
		return head;
	}

	ListNode* _head;
	ListNode* _tail;
};
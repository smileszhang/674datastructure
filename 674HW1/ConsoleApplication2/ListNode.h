#pragma once
typedef int DataType;

//double node class
class ListNode
{
	
public:
	ListNode(const DataType x)
		:_data(x)
		, _prev(NULL)
		, _next(NULL)
	{}

	DataType _data;
	ListNode* _prev;
	ListNode* _next;
};
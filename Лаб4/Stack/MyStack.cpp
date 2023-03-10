#include "MyStack.h"
#include <iostream>

template <class INF>
MyStack<INF>::MyStack(void)
{
	top=NULL;
}

template <class INF>
MyStack<INF>::~MyStack(void)
{
	delete[] top;
}

template <class INF>
bool MyStack<INF>::empty(void)
{
	if (top==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class INF>
bool MyStack<INF>::push(INF n)
{
	typedef class ListNode < INF, MyStack <INF> > Node;
	if (top==NULL)
	{
		this->top=new Node;
		top->d=n;
		top->next=NULL;
	}
	else
	{
		Node* p_unit=new Node;
		p_unit->d=n;
		p_unit->next=top;
		top=p_unit;
	}
	return true;
}

template <class INF>
bool MyStack<INF>::pop(void)
{
	typedef class ListNode < INF, MyStack <INF> > Node;
	Node* p_unit=top;
	top=top->next;
	delete p_unit;
	return true;
}

template <class INF>
INF* MyStack<INF>::top_inf(void)
{
	return &top->d;
}
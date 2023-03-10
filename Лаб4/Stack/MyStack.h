#ifndef MyStack_h						// ������ �� ��������� ����������
#define MyStack_h           			// ������ ���������
#include <iostream>						// ����� ��� NULL

//��������� ����� ListNode (���� ������������ ������)
template <class INF, class FRIEND>
class ListNode							// ���� ������
{			
private:
	INF d;             					// �������������� ����� ����
	ListNode* next;   					// ��������� �� ��������� ���� ������
	ListNode(void)						// �����������
	{
		next=NULL;					
	}
	friend FRIEND;
};

//��������� ����� MyStack �� ������ ������������ ������.
template <class INF>
class MyStack 
{
	typedef class ListNode < INF, MyStack <INF> > Node;
	Node* top;
public:	
	MyStack(void);						// �����������
	~MyStack(void);						// ���������� ������������ ������
	bool empty(void);					// ���� ������?
	bool push(INF);						// �������� ���� � ������� �����
	bool pop(void);						// ������� ���� �� ������� �����
	INF* top_inf(void);					// ������� ���������� �� ������� �����
};

#endif
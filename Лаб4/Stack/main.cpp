#include "MyStack.h"
#include "MyStack.cpp"
#include "proto.h"
#include <iostream>

using namespace std;

template <class INF>
void Multipliers(int n, MyStack<INF>& s)
{
	for (int i=2; i<=n; i++)
	{
		while (n%i==0) 
		{
			n/=i;
			s.push(i);
		}
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	MyStack<int> numbers;
	int n;
	cout << "¬ведите число: ";
	cin >> n;
	cout << n << " = ";
	Multipliers(n, numbers);
	int k=0;
	do
	{
		numbers.pop();
		k++;
	}
	while (numbers.empty()==0);
	int* arr=new int[k];
	int i=0;
	Multipliers(n, numbers);
	do
	{
		arr[i]=*numbers.top_inf();
		numbers.pop();
		i++;
	}
	while (numbers.empty()==0);
	for (int i=0; i<k; i++)
	{
		cout << arr[i];
		if (i!=k-1)
		{
			cout << " * ";
		}
	}
	cout << endl;
	cout << n << " = ";
	for (int i=k-1; i>=0; i--)
	{
		cout << arr[i];
		if (i!=0)
		{
			cout << " * ";
		}
	}
	cout << endl;
	system("pause");
}
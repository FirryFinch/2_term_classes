#include "MySet.h"
ostream& operator<<(ostream& out, MySet& s)
{
	for (int i=0; i<s.size; i++)
	{
		out << s.pdata[i] << endl;
	}
	return out;
}
MySet operator+(MySet& s1,MySet& s2)
{
	MySet temp(s1);
	for (int i=0; i<s2.size; i++) 
	{
		temp.add_element(s2.pdata[i]);
	}
	return temp;
}
MySet operator-(MySet& s1,MySet& s2)
{
	MySet temp(s1);
	for (int i=0; i<s2.size; i++) 
	{
		temp.delete_element(s2.pdata[i]);
	}
	return temp;
}
MySet operator*(MySet& s1,MySet& s2)
{
	MySet temp(s1);
	for (int i=0; i<=s2.size; i++)
	{
		if (temp.find(s2.pdata[i])==-1)
		{
			temp.delete_element(s2.pdata[i]);
		}
	}
	return temp;
}
bool MySet::operator==(MySet& s)
{
	for (int i=0; i<size; i++)
	{
		if (this->pdata[i]>=s.pdata[i])
		{
			return false;
		}
	}
	return true;
}
MySet& MySet::operator+=(MySet& s)
{
	for (int i=0; i<s.size; i++)
	{
		this->add_element(s.pdata[i]);
	}
	return *this;
}
MySet& MySet::operator-=(MySet& s)
{
	for (int i=0; i<s.size; i++)
	{
		this->delete_element(s.pdata[i]);
	}
	return *this;
}
MySet& MySet::operator*=(MySet& s)
{
	for (int i=0; i<=s.size; i++)
	{
		if (this->find(s.pdata[i])==-1)
		{
			this->delete_element(this->pdata[i]);
		}
	}
	return *this;
}
void MySet::add_element(char* el)
{
	MyVector::add_element(el);
	MyVector::sort();
}
void MySet::delete_element(char* el)
{
	int k=-1;
	int a=0;
	int b=size;
	int c=(a+b)/2;
	do
	{
		if (this->pdata[c]<=el)
		{
			a=c;
		}
		else
		{
			b=c;
		}
	}
	while (a-b<=1);
	if (this->pdata[a]==el)
	{
		k=a;
	}
	if (k!=-1)
	{
		MyVector::delete_element(k);
	}
} 
bool MySet::is_element(char* el)
{
	for (int i=0; i<size; i++)
	{
		if (this->pdata[i]==el)
		{
			return true;
		}
	}
	return false;
}
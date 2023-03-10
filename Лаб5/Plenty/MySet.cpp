#include "MySet.h"
ostream& operator<<(ostream& out, MySet& s)
{
	for (int i=0; i<s.size; i++)
		out << s.pdata[i] << endl;
	return out;
}
MySet operator+(MySet& s1, MySet& s2)
{
	MySet s_temp(s1);
	for (int i=0; i<s2.size; i++) 
	{
		if (s_temp.is_element(s2.pdata[i])==0)
			s_temp.add_element(s2.pdata[i]);
	}
	return s_temp;
}
MySet operator-(MySet& s1, MySet& s2)
{
	MySet s_temp(s1);
	for (int i=0; i<s2.size; i++) 
	{
		if (s_temp.is_element(s2.pdata[i])==1)
			s_temp.delete_element(s2.pdata[i]);
	}
	return s_temp;
}
MySet operator*(MySet& s1, MySet& s2)
{
	MySet s_temp(s1);
	for (int i=0; i<s2.size; i++)
	{
		if (s_temp.is_element(s2.pdata[i])==0)
			s_temp.delete_element(s2.pdata[i]);
	}
	return s_temp;
}
bool MySet::operator==(MySet& s)
{
	for (int i=0; i<size; i++)
	{
		if (pdata[i]>s.pdata[i])
			return false;
	}
	return true;
}
MySet& MySet::operator+=(MySet& s)
{
	for (int i=0; i<s.size; i++)
	{
		if (is_element(s.pdata[i])==0)
			add_element(s.pdata[i]);
	}
	return *this;
}
MySet& MySet::operator-=(MySet& s)
{
	for (int i=0; i<s.size; i++)
	{
		if (is_element(s.pdata[i])==1)
			delete_element(s.pdata[i]);
	}
	return *this;
}
MySet& MySet::operator*=(MySet& s)
{
	for (int i=0; i<s.size; i++)
	{
		if (is_element(s.pdata[i])==0)
			delete_element(pdata[i]);
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
	int c;
	while (a-b>1)
	{
		c=(a+b)/2;
		if (el>pdata[c])
			a=c;
		else
			b=c;
	}
	if (pdata[a]==el)
		k=a;
	if (k!=-1)
		MyVector::delete_element(k);
} 
bool MySet::is_element(char* el)
{
	for (int i=0; i<size; i++)
	{
		if (pdata[i]==el)
			return true;
	}
	return false;
}
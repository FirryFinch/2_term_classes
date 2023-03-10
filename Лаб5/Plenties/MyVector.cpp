#include "MyVector.h"

MyVector::MyVector(char* el, int maxsz)
{
	if (!el)
	{ 
		pdata=new char*[maxsize];
		pdata[0]=NULL;
		maxsize=MAX_SIZE;
		size=0;
	}
	else
	{
		maxsize=maxsz;
		pdata=new char*[maxsize];
		pdata[0]=el;
		size=1;
	}
}
MyVector::MyVector(MyVector& v)
{
	maxsize=v.maxsize;
	size=v.size;
	pdata=new char*[maxsize];
	for (int i=0; i<size; i++) 
	{
		pdata[i]=new char[sizeof(v.pdata[i])];
		pdata[i]=v.pdata[i];
	}
}
MyVector::~MyVector()
{
	delete[] pdata;
}
void MyVector::add_element(char* el)
{
	if (size>maxsize) 
	{
		maxsize*=1.5;
		resize();
	}
	pdata[size]=new char[sizeof(el)];
	for (int i=0; i<sizeof(el); i++)
	{
		pdata[size][i]=el[i];
	}
	size++;
}
bool MyVector::delete_element(int i)
{
	if (size<1) 
	{
		return false;
	}
	else
	{
		for (int k=i; k<maxsize; k++)
		{
			pdata[k]=pdata[k+1];
		}
		size--;
		if (size<maxsize/2)
		{
			maxsize/=1.5;
			resize();
		}
		return true;
	}
}
char* MyVector::operator[](int i)
{
	return pdata[i];
}
void MyVector::sort()
{
	for (int i=0; i<size-1; i++) 
		{
			for (int j=0; j<size-i-1; j++)
			{
				if (pdata[j]>pdata[j+1])
				{
					swap(pdata[j], pdata[j+1]);
				}
			}
		}
}
int MyVector::Size()
{
	return size;
}
int MyVector::Maxsize()
{
	return maxsize;
}
int MyVector::find(char* el)
{
	for (int i=0; i<size; i++) 
	{
		if (pdata[i]==el)
		{
			return i;
		}
	}
	return -1;
}
MyVector& MyVector::operator=(MyVector& v)
{
	maxsize=v.maxsize;
	size=v.size;
	pdata=new char*[maxsize];
	for (int i=0; i<size; i++)
	{
		pdata[i]=new char[sizeof(v.pdata[i])];
		pdata[i]=v.pdata[i];
	}
	return *this;
}
ostream& operator <<(ostream& out, MyVector& v)
{
	for (int i=0; i<v.size; i++)
	{
		out << v.pdata[i] << endl;
	}
	return out;
}
void MyVector::resize()
{
	char** arr=new char*[maxsize];
	for (int i=0; i<size; i++)
	{
		arr[i]=new char[sizeof(pdata[i])];
		arr[i]=pdata[i];
	}
	delete[] pdata;
	pdata=arr;
}
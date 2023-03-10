#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

using namespace std;

const int MAX_SIZE=5;

class MyVector
{
	public:
		MyVector(char *el=NULL, int maxsz=MAX_SIZE);
		MyVector(MyVector& v);
		~MyVector();

		void add_element(char* el);
		bool delete_element(int i);
		char* operator[](int i);

		void sort();

		int Size();
		int Maxsize();
		int find(char* el);
		MyVector& operator=(MyVector& v);
		friend ostream& operator<<(ostream& out, MyVector& v);
	protected:
		int maxsize;
		int size;
		char** pdata;
	private:
		void resize();
};

#endif
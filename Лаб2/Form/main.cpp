#include "unit.h"
#include "proto.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	unit cell[15];
	char* filename="base.txt";
	int how_many_lines=0;
	int longest_name=0;
	int longest_provider=0;
	int temp1=0;
	int temp2=0;
	cout << "���� ������, ��������� �� ������ �� ������ ��� ������ ��������� � �������� ����� �����, ������� �� ������� ������� �������� �� ��������� �������: " << endl;
	cout << "1) ��� ��������" << endl;
	cout << "2) ��� �������" << endl;
	cout << "3) ��� ���" << endl;
	cout << "4) �������� �����, ������� �� ����������" << endl;
	cout << "5) ��� ������ �������� ����� ��������� (������������� - 1, ������������� - 0)" << endl;
	cout << "6) ��� ������� �������� ��������� ����� (0 - �� ������, 1 - ������)" << endl;
	cout << "���� ������ �������� �������� 15 �����." << endl << endl;
	while (true) 
	{ 
		switch (menu()) 
		{
			case 1: read_from_file(filename, cell, &how_many_lines);
					for (int k=0; k<how_many_lines; k++)
					{
						temp1=strlen(cell[k].get_name());
						temp2=strlen(cell[k].get_provider());
						if (longest_name<temp1)
						{
							longest_name=temp1;
						}
						if (longest_provider<temp2)
						{
							longest_provider=temp2;
						}
					}
					break;
			case 2: if ((how_many_lines)!=0)
					{
						write_to_file(filename, cell, &how_many_lines);
					}
					else
					{
						cout << endl << "������: ��� ���� ������!" << endl << endl;
					}
					break;
			case 3: if ((how_many_lines)!=0)
					{
						sort_menu(cell, &how_many_lines);
						cout << endl << "���������� ���� ���������� �������." << endl;
						cout << endl;
					}
					else
					{
						cout << endl << "������: ��� ���� ������!" << endl << endl;
					}
					break;
			case 4: if ((how_many_lines)!=0)
					{
						edit_menu(cell, &how_many_lines);
					}
					else
					{
						cout << endl << "������: ��� ���� ������!" << endl << endl;
					}
					break; 
			case 5: if ((how_many_lines)!=0)
					{
						cout << endl;
						cout << "���" << setw(longest_name-3+10) << right << "�������" << setw(10) << right << "���" << setw(longest_provider+10) << right << "��������" << setw(10) << right << "������" << setw(20) << right << "������� ��������" << endl;
						for (int i=0; i<how_many_lines; i++)
						{
							cell[i].show(&longest_name, &longest_provider);
						}
						cout << "����� �����: " << how_many_lines << endl;
						cout << endl;
					}
					else
					{
						cout << endl << "������: ��� ���� ������!" << endl << endl;
					}
					break;
			case 6: return 0;
		}
	}
	return 0;
}
int menu() 
{
	int answ;
	cout << "����" << endl;
	cout << "l) ������� �� �����" << endl;
	cout << "2) ������ � ����" << endl;
	cout << "3) ����������" << endl;
	cout << "4) ��������������" << endl;
	cout << "5) ����� �� �����" << endl;
	cout << "6) �����" << endl;
	do
	{
		cout << "���������� �������� ������ ������� (�� 1 �� 6): ";
		cin >> answ;
	}
	while ((answ<1) && (answ>6));
	return answ;
}
void read_from_file(char* filename, unit* cell, int* how_many_lines)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "������: ����� �� ����������!" << endl << endl;
	}
	else
	{
		cout << endl << "���� \'base.txt\' ������� ������." << endl;
		int i=0;
		while (!fin.eof())
		{	
			if (i<15)
			{
				fin >> cell[i];
				i++;
			}
		}
		(*how_many_lines)=i-1;
		fin.close();
		cout << "������ �� ����� \'base.txt\' ������� ���������." << endl;
		cout << endl;
	}
}
void write_to_file(char *filename, unit* cell, int* how_many_lines) 
{
	ofstream fout;
	fout.open(filename);
	if (!fout.is_open())
	{
		cout << "������: ������ � ���� ����������!" << endl << endl;
	}
	else
	{
		for (int i=0; i<(*how_many_lines); i++)
		{
			fout << cell[i];
		}
		fout.close();
		cout << endl << "������ � ���� \'base.txt\' ������� ���������." << endl;
		cout << endl;
	}
}
void sort_menu(unit* cell, int* how_many_lines)
{
	int answ;
	cout << endl;
	cout << "���� ����������" << endl;
	cout << "�������, �� �������� ����� �������������:" << endl;
	cout << "1) ���" << endl;
	cout << "2) �������" << endl;
	cout << "3) ���" << endl;
	cout << "4) �������� �����" << endl;
	cout << "5) �������������/������������� ������ �������� �����" << endl;
	cout << "6) ������� �������� ��������� �����" << endl;
	do
	{
		cout << "���������� �������� ������ ������� (�� 1 �� 6): ";
		cin >> answ;
	}
	while ((answ<1) && (answ>6));
	sort_method(cell, how_many_lines, answ);
}
void sort_method(unit* cell, int* how_many_lines, int column)
{
	int answ;
	cout << "������, �� �������� ����� �������������:" << endl;
	cout << "1) �� �����������" << endl;
	cout << "2) �� ��������" << endl;
	do
	{
		cout << "���������� �������� ������ ������� (�� 1 �� 2): ";
		cin >> answ;
	}
	while ((answ<1) && (answ>2));
	sort(cell, how_many_lines, column, answ);
}
void sort(unit* cell, int* how_many_lines, int column, int method)
{
	for (int i=0; i<(*how_many_lines); i++)
	{
		cell[i].column=column;
	}
	if (method==1)
	{
		for (int i=0; i<(*how_many_lines)-1; i++) 
		{
			for (int j=0; j<(*how_many_lines)-i-1; j++)
			{
				if (cell[j]>cell[j+1]) 
				swap(cell[j], cell[j+1]);
			}
		}
	}
	else
	{
		if (method==2)
		{
			for (int i=0; i<(*how_many_lines)-1; i++) 
			{
				for (int j=0; j<(*how_many_lines)-i-1; j++)
				{
					if (cell[j]<cell[j+1]) 
					swap(cell[j], cell[j+1]);
				}
			}
		}
	}
}
void edit_menu(unit* cell, int* how_many_lines)
{
	int answ;
	cout << endl;
	cout << "���� ��������������" << endl;
	cout << "��������, �� ������� ����� ���������:" << endl;
	cout << "1) �������� ������" << endl;
	cout << "2) ������� ������" << endl;
	cout << "3) ������������� ������" << endl;
	do
	{
		cout << "���������� �������� ������ ������� (�� 1 �� 3): ";
		cin >> answ;
	}
	while ((answ<1) && (answ>3));
	edit(cell, how_many_lines, answ);
}
void edit(unit* cell, int* how_many_lines, int method)
{
	if (method==1)
	{
		if ((*how_many_lines)<15)
		{
			char* another_name=new char[20];
			int another_age;
			char another_gend;
			char* another_prov=new char[20];
			bool another_q;
			bool another_wc;
			cout << endl << "������� ��� ��������: ";
			cin >> another_name;
			cell[(*how_many_lines)].set_name(another_name);
			cout << "������� ������� ��������: ";
			cin >> another_age;
			cell[(*how_many_lines)].set_age(another_age);
			cout << "������� ��� ��������: ";
			cin >> another_gend;
			cell[(*how_many_lines)].set_gend(another_gend);
			cout << "������� �������� ��������� �����: ";
			cin >> another_prov;
			cell[(*how_many_lines)].set_provider(another_prov);
			cout << "������� ���������� ��� ������ �������� ����� (0 - �������������, 1 - �������������): ";
			cin >> another_q;
			cell[(*how_many_lines)].set_quality(another_q);
			cout << "������� ���������� ��� ������� �������� ��������� (0 - �������������, 1 - �������������): ";
			cin >> another_wc;
			cell[(*how_many_lines)].set_willchange(another_wc);
			(*how_many_lines)++;
			cout << endl << "���������� ������ � ���� ���� ����������� �������." << endl;
			cout << endl;
		}
		else
		{
			cout << endl << "������: ���������� �������� ������ - ����������� ���������� ����!";
		}
	}
	if (method==2)
	{
		if ((*how_many_lines)>0)
		{
			int answ;
			cout << endl << "������� ����� ������ ��� ��������: ";
			cin >> answ;
			for (int i=answ-1; i<=(*how_many_lines); i++)
			{
				cell[i]=cell[i+1];
			}
			(*how_many_lines)--;
			cout << endl << "�������� " << answ << " ������ ������� ���������.";
			cout << endl << endl;
		}
		else
		{
			cout << endl << "������: ���������� ������� ������!" << endl;
		}
	}
	if (method==3)
	{
		int num_line, num_what;
		cout << endl << "������� ����� ������ ��� ��������������: ";
		cin >> num_line;
		cout << endl << "��������, ��� �� ������ ���������������:" << endl;
		cout << "1) ���" << endl;
		cout << "2) �������" << endl;
		cout << "3) ���" << endl;
		cout << "4) �������� �����" << endl;
		cout << "5) ������ �������� �����" << endl;
		cout << "6) ������� �������� ���������" << endl;
		do
		{
			cout << "���������� �������� ������ ������� (�� 1 �� 6): ";
			cin >> num_what;
		}
		while ((num_what<1) && (num_what>6));
		switch (num_what)
		{
			case 1: char* another_name;
					another_name=new char[20];
					cout << endl << "������� ����� ���: ";
					cin >> another_name;
					cell[num_line-1].set_name(another_name);
					cout << endl << "��� �������� �������." << endl << endl;
					break;
			case 2: int another_age;
					cout << endl << "������� ����� �������: ";
					cin >> another_age;
					cell[num_line-1].set_age(another_age);
					cout << endl << "������� ������� �������." << endl << endl;
					break;
			case 3: char another_gend;
					cout << endl << "������� ����� ���: ";
					cin >> another_gend;
					cell[num_line-1].set_gend(another_gend);
					cout << endl << "��� ������� �������." << endl << endl;
					break;
			case 4: char* another_provider;
					another_provider=new char[20];
					cout << endl << "������� ����� �������� ���������: ";
					cin >> another_provider;
					cell[num_line-1].set_provider(another_provider);
					cout << endl << "�������� ��������� �������� �������." << endl << endl;
					break;
			case 5: bool another_quality;
					cout << endl << "������� ����� ������ �������� �����: ";
					cin >> another_quality;
					cell[num_line-1].set_quality(another_quality);
					cout << endl << "���������� �������� ����� ������� �������." << endl << endl;
					break;
			case 6: bool another_willchange;
					cout << endl << "������� ���������� ������� �������� ���������: ";
					cin >> another_willchange;
					cell[num_line-1].set_willchange(another_willchange);
					cout << endl << "���������� ������� �������� ��������� ������� �������." << endl << endl;
					break;
		}
	}
}
void swap(unit* u1, unit* u2)
{
	swap((*u1).name, (*u2).name);
	swap((*u1).age, (*u2).age);
	swap((*u1).gend, (*u2).gend);
	swap((*u1).provider, (*u2).provider);
	swap((*u1).quality, (*u2).quality);
	swap((*u1).willchange, (*u2).willchange);
}
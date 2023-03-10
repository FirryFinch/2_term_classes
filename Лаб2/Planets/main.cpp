#include "planet.h"
#include "proto.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	Planet solar_system_planets[15];
	char* filename="planets.txt";
	int how_many_lines=0;
	int longest_name=0;
	while (true) 
	{ 
		switch (menu()) 
		{
			case 1: read_from_file_2(filename, solar_system_planets, &how_many_lines);
					longest_name_finder(solar_system_planets, &how_many_lines, &longest_name);
					break;
			case 2: if ((how_many_lines)!=0)
					{
						write_to_file_2(filename, solar_system_planets, &how_many_lines, &longest_name);
					}
					else
					{
						cout << endl << "������: ��� ���� ������!" << endl << endl;
					}
					break;
			case 3: if ((how_many_lines)!=0)
					{
						sort_menu(solar_system_planets, &how_many_lines);
						cout << endl << "���������� ���� ���������� �������." << endl << endl;
					}
					else
					{
						cout << endl << "������: ��� ���� ������!" << endl << endl;
					}
					break;
			case 4: if ((how_many_lines)!=0)
					{
						edit_menu(solar_system_planets, &how_many_lines);
					}
					else
					{
						cout << endl << "������: ��� ���� ������!" << endl << endl;
					}
					break; 
			case 5: if ((how_many_lines)!=0)
					{
						cout << endl << "��������" << setw(6+longest_name) << right << "�������" << setw(10) << "�����" << setw(13) << "��������" << endl;
						for (int i=0; i<how_many_lines; i++)
						{
							solar_system_planets[i].show(&longest_name);
						}
						cout << endl;
					}
					else
					{
						cout << endl << "������: ��� ���� ������!" << endl << endl;
					}
					break;
			case 6: return 0;
			case 7: Planet test_planet("TEST",20,0,35);
					int num;
					num=4;
					test_planet.show(&num);
					cout << endl;
					break;
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
	cout << "7) ������������ ����������� �������� � �������� ������� � ������������" << endl;
	do
	{
		cout << "���������� �������� ������ ������� (�� 1 �� 7): ";
		cin >> answ;
	}
	while ((answ<1) && (answ>7));
	return answ;
}
void read_from_file(char* filename, Planet* solar_system_planets, int* how_many_lines)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "������: ����� �� ����������!" << endl << endl;
	}
	else
	{
		cout << endl << "���� \'planets.txt\' ������� ������." << endl;
		char* current_name[15];
		for (int j=0; j<15; j++)
		{
			current_name[j]=new char[20];
		}
		long int current_size;
		bool current_life;
		int current_sats;
		int i=0;
		while (!fin.eof())
		{	
			if (i<15)
			{
				fin >> current_name[i] >> current_size >> current_life >> current_sats;
				solar_system_planets[i].set_name(current_name[i]);
				solar_system_planets[i].set_size(current_size);
				solar_system_planets[i].set_life(current_life);
				solar_system_planets[i].set_amount_of_sats(current_sats);
				i++;
			}
		}
		(*how_many_lines)=i-1;
		fin.close();
		cout << "������ �� ����� \'planets.txt\' ������� ���������." << endl;
		cout << endl;
	}
}
void read_from_file_2(char* filename, Planet* solar_system_planets, int* how_many_lines)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "������: ����� �� ����������!" << endl << endl;
	}
	else
	{
		cout << endl << "���� \'planets.txt\' ������� ������." << endl;
		int i=0;
		while (!fin.eof())
		{	
			if (i<15)
			{
				fin >> solar_system_planets[i];
				i++;
			}
		}
		(*how_many_lines)=i-1;
		fin.close();
		cout << "������ �� ����� \'planets.txt\' ������� ���������." << endl;
		cout << endl;
	}
}
void write_to_file(char *filename, Planet* solar_system_planets, int* how_many_lines, int* longest_name) 
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
			fout << solar_system_planets[i].get_name() << setw(12+(*longest_name)-strlen(solar_system_planets[i].get_name())) << right << solar_system_planets[i].get_size() << setw(10) << solar_system_planets[i].get_life() << setw(10) << solar_system_planets[i].get_amount_of_sats() << endl;
		}
		fout.close();
		cout << endl << "������ � ���� \'planets.txt\' ������� ���������." << endl;
		cout << endl;
	}
}
void write_to_file_2(char *filename, Planet* solar_system_planets, int* how_many_lines, int* longest_name) 
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
			fout << solar_system_planets[i];
		}
		fout.close();
		cout << endl << "������ � ���� \'planets.txt\' ������� ���������." << endl;
		cout << endl;
	}
}
void sort_menu(Planet* solar_system_planets, int* how_many_lines)
{
	int answ;
	cout << endl;
	cout << "���� ����������" << endl;
	cout << "�������, �� �������� ����� �������������:" << endl;
	cout << "1) ��������" << endl;
	cout << "2) �������" << endl;
	cout << "3) ���������� ������� �����" << endl;
	cout << "4) ���������� ���������" << endl;
	do
	{
		cout << "���������� �������� ������ ������� (�� 1 �� 4): ";
		cin >> answ;
	}
	while ((answ<1) && (answ>4));
	sort_method(solar_system_planets, how_many_lines, answ);
}
void sort_method(Planet* solar_system_planets, int* how_many_lines, int column)
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
	sort_2(solar_system_planets, how_many_lines, column, answ);
}
void sort(Planet* solar_system_planets, int* how_many_lines, int column, int method)
{
	if (method==1)
	{
		switch(column)
		{
			case 1:
					for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_name()>solar_system_planets[j+1].get_name()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "���������� �� �������� �� �������� ���� ������� �����������." << endl << endl;
					break;
			case 2:	for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_size()>solar_system_planets[j+1].get_size()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "���������� �� �������� �� ����������� ���� ������� �����������." << endl << endl;
					break;
			case 3: for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_life()>solar_system_planets[j+1].get_life()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "���������� �� ���������� ������� ����� �� ����������� ���� ������� �����������." << endl << endl;
					break;
			case 4: for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_amount_of_sats()>solar_system_planets[j+1].get_amount_of_sats()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "���������� �� ���������� ��������� �� ����������� ���� ������� �����������." << endl << endl;
					break;
		}
	}
	else
	{
		switch(column)
		{
			case 1:
					for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_name()<solar_system_planets[j+1].get_name()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "���������� �� �������� �� �������� ���� ������� �����������." << endl << endl;
					break;
			case 2:	for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_size()<solar_system_planets[j+1].get_size()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "���������� �� �������� �� �������� ���� ������� �����������." << endl << endl;
					break;
			case 3: for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_life()<solar_system_planets[j+1].get_life()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "���������� �� ���������� ������� ����� �� �������� ���� ������� �����������." << endl << endl;
					break;
			case 4: for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_amount_of_sats()<solar_system_planets[j+1].get_amount_of_sats()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "���������� �� ���������� ��������� �� �������� ���� ������� �����������." << endl << endl;
					break;
		}
	}
}
void sort_2(Planet* solar_system_planets, int* how_many_lines, int column, int method)
{
	for (int i=0; i<(*how_many_lines); i++)
	{
		solar_system_planets[i].column=column;
	}
	if (method==1)
	{
		for (int i=0; i<(*how_many_lines)-1; i++) 
		{
			for (int j=0; j<(*how_many_lines)-i-1; j++)
			{
				if (solar_system_planets[j]>solar_system_planets[j+1]) 
				swap(solar_system_planets[j], solar_system_planets[j+1]);
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
					if (solar_system_planets[j]<solar_system_planets[j+1]) 
					swap(solar_system_planets[j], solar_system_planets[j+1]);
				}
			}
		}
	}
}
void edit_menu(Planet* solar_system_planets, int* how_many_lines)
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
	edit(solar_system_planets, how_many_lines, answ);
}
void edit(Planet* solar_system_planets, int* how_many_lines, int method)
{
	if (method==1)
	{
		if ((*how_many_lines)<15)
		{
			char* current_name;
			current_name=new char[20];
			long int current_size;
			bool current_life;
			int current_sats;
			cout << "������� ����� �������� �������: ";
			cin >> current_name;
			solar_system_planets[(*how_many_lines)].set_name(current_name);
			cout << "������� ������� �������: ";
			cin >> current_size;
			solar_system_planets[(*how_many_lines)].set_size(current_size);
			cout << "������� ���������� ������� ����� (����� 0, ���� ���, ��� 1, ���� ����������): ";
			cin >> current_life;
			solar_system_planets[(*how_many_lines)].set_life(current_life);
			cout << "������� ���������� ���������: ";
			cin >> current_sats;
			solar_system_planets[(*how_many_lines)].set_amount_of_sats(current_sats);
			(*how_many_lines)++;
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
				solar_system_planets[i]=solar_system_planets[i+1];
			}
			(*how_many_lines)--;
			cout << "�������� " << answ << " ������ ������� ���������.";
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
		cout << "1) ��������" << endl;
		cout << "2) �������" << endl;
		cout << "3) ���������� ������� �����" << endl;
		cout << "4) ���������� ���������" << endl;
		do
		{
			cout << "���������� �������� ������ ������� (�� 1 �� 4): ";
			cin >> num_what;
		}
		while ((num_what<1) && (num_what>4));
		switch (num_what)
		{
			case 1: char* current_name;
					current_name=new char[20];
					cout << endl << "������� �������� �������: ";
					cin >> current_name;
					solar_system_planets[num_line-1].set_name(current_name);
					cout << endl << "�������� ������� �������� �������." << endl << endl;
					break;
			case 2: long int current_size;
					cout << endl << "������� ������� �������: ";
					cin >> current_size;
					solar_system_planets[num_line-1].set_size(current_size);
					cout << endl << "������� ������� ������� �������." << endl << endl;
					break;
			case 3: bool current_life;
					cout << endl << "������� ���������� ������� ����� (����� 0, ���� ���, ��� 1, ���� ����������): ";
					cin >> current_life;
					solar_system_planets[num_line-1].set_life(current_life);
					cout << endl << "���������� ������� ����� ������� ������� �������." << endl << endl;
					break;
			case 4: int current_sats;
					cout << endl << "������� ���������� ���������: ";
					cin >> current_sats;
					solar_system_planets[num_line-1].set_amount_of_sats(current_sats);
					cout << endl << "���������� ��������� ������� �������� �������." << endl << endl;
					break;
		}
	}
}
void longest_name_finder(Planet* solar_system_planets, int* how_many_lines, int* longest_name)
{
	for (int k=0; k<(*how_many_lines); k++)
	{
		if ((*longest_name)<strlen(solar_system_planets[k].get_name()))
		{
			(*longest_name)=strlen(solar_system_planets[k].get_name());
		}
	}
}
void swap(Planet* p1, Planet* p2)
{
	swap((*p1).name, (*p2).name);
	swap((*p1).diameter, (*p2).diameter);
	swap((*p1).life, (*p2).life);
	swap((*p1).amount_of_sats, (*p2).amount_of_sats);
}
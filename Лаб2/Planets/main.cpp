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
						cout << endl << "Ошибка: нет базы данных!" << endl << endl;
					}
					break;
			case 3: if ((how_many_lines)!=0)
					{
						sort_menu(solar_system_planets, &how_many_lines);
						cout << endl << "Сортировка была поизведена успешно." << endl << endl;
					}
					else
					{
						cout << endl << "Ошибка: нет базы данных!" << endl << endl;
					}
					break;
			case 4: if ((how_many_lines)!=0)
					{
						edit_menu(solar_system_planets, &how_many_lines);
					}
					else
					{
						cout << endl << "Ошибка: нет базы данных!" << endl << endl;
					}
					break; 
			case 5: if ((how_many_lines)!=0)
					{
						cout << endl << "Название" << setw(6+longest_name) << right << "Диаметр" << setw(10) << "Жизнь" << setw(13) << "Спутники" << endl;
						for (int i=0; i<how_many_lines; i++)
						{
							solar_system_planets[i].show(&longest_name);
						}
						cout << endl;
					}
					else
					{
						cout << endl << "Ошибка: нет базы данных!" << endl << endl;
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
	cout << "МЕНЮ" << endl;
	cout << "l) Считать из файла" << endl;
	cout << "2) Запись в файл" << endl;
	cout << "3) Сортировка" << endl;
	cout << "4) Редактирование" << endl;
	cout << "5) Вывод на экран" << endl;
	cout << "6) Выход" << endl;
	cout << "7) Тестирование отображения сведений о создании объекта в конструкторе" << endl;
	do
	{
		cout << "Пожалуйста выберете нужный вариант (от 1 до 7): ";
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
		cout << "Ошибка: Файла не существует!" << endl << endl;
	}
	else
	{
		cout << endl << "Файл \'planets.txt\' успешно открыт." << endl;
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
		cout << "Чтение из файла \'planets.txt\' успешно завершено." << endl;
		cout << endl;
	}
}
void read_from_file_2(char* filename, Planet* solar_system_planets, int* how_many_lines)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Ошибка: Файла не существует!" << endl << endl;
	}
	else
	{
		cout << endl << "Файл \'planets.txt\' успешно открыт." << endl;
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
		cout << "Чтение из файла \'planets.txt\' успешно завершено." << endl;
		cout << endl;
	}
}
void write_to_file(char *filename, Planet* solar_system_planets, int* how_many_lines, int* longest_name) 
{
	ofstream fout;
	fout.open(filename);
	if (!fout.is_open())
	{
		cout << "Ошибка: Запись в файл невозможна!" << endl << endl;
	}
	else
	{
		for (int i=0; i<(*how_many_lines); i++)
		{
			fout << solar_system_planets[i].get_name() << setw(12+(*longest_name)-strlen(solar_system_planets[i].get_name())) << right << solar_system_planets[i].get_size() << setw(10) << solar_system_planets[i].get_life() << setw(10) << solar_system_planets[i].get_amount_of_sats() << endl;
		}
		fout.close();
		cout << endl << "Запись в файл \'planets.txt\' успешно завершена." << endl;
		cout << endl;
	}
}
void write_to_file_2(char *filename, Planet* solar_system_planets, int* how_many_lines, int* longest_name) 
{
	ofstream fout;
	fout.open(filename);
	if (!fout.is_open())
	{
		cout << "Ошибка: Запись в файл невозможна!" << endl << endl;
	}
	else
	{
		for (int i=0; i<(*how_many_lines); i++)
		{
			fout << solar_system_planets[i];
		}
		fout.close();
		cout << endl << "Запись в файл \'planets.txt\' успешно завершена." << endl;
		cout << endl;
	}
}
void sort_menu(Planet* solar_system_planets, int* how_many_lines)
{
	int answ;
	cout << endl;
	cout << "МЕНЮ СОРТИРОВКИ" << endl;
	cout << "Столбец, по которому нужно отсортировать:" << endl;
	cout << "1) Название" << endl;
	cout << "2) Диаметр" << endl;
	cout << "3) Показатель наличия жизни" << endl;
	cout << "4) Количество спутников" << endl;
	do
	{
		cout << "Пожалуйста выберете нужный вариант (от 1 до 4): ";
		cin >> answ;
	}
	while ((answ<1) && (answ>4));
	sort_method(solar_system_planets, how_many_lines, answ);
}
void sort_method(Planet* solar_system_planets, int* how_many_lines, int column)
{
	int answ;
	cout << "Способ, по которому нужно отсортировать:" << endl;
	cout << "1) По возрастанию" << endl;
	cout << "2) По убыванию" << endl;
	do
	{
		cout << "Пожалуйста выберете нужный вариант (от 1 до 2): ";
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
					cout << endl << "Сортировка по названию по убыванию была успешно произведена." << endl << endl;
					break;
			case 2:	for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_size()>solar_system_planets[j+1].get_size()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "Сортировка по диаметру по возрастанию была успешно произведена." << endl << endl;
					break;
			case 3: for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_life()>solar_system_planets[j+1].get_life()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "Сортировка по показателю наличия жизни по возрастанию была успешно произведена." << endl << endl;
					break;
			case 4: for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_amount_of_sats()>solar_system_planets[j+1].get_amount_of_sats()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "Сортировка по количеству спутников по возрастанию была успешно произведена." << endl << endl;
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
					cout << endl << "Сортировка по названию по убыванию была успешно произведена." << endl << endl;
					break;
			case 2:	for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_size()<solar_system_planets[j+1].get_size()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "Сортировка по диаметру по убыванию была успешно произведена." << endl << endl;
					break;
			case 3: for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_life()<solar_system_planets[j+1].get_life()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "Сортировка по показателю наличия жизни по убыванию была успешно произведена." << endl << endl;
					break;
			case 4: for (int i=0; i<(*how_many_lines)-1; i++) 
					{
						for (int j=0; j<(*how_many_lines)-i-1; j++)
						{
							if (solar_system_planets[j].get_amount_of_sats()<solar_system_planets[j+1].get_amount_of_sats()) 
							swap(solar_system_planets[j], solar_system_planets[j+1]);
						}
					}
					cout << endl << "Сортировка по количеству спутников по убыванию была успешно произведена." << endl << endl;
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
	cout << "МЕНЮ РЕДАКТИРОВАНИЯ" << endl;
	cout << "Действие, по которое нужно совершить:" << endl;
	cout << "1) Добавить строку" << endl;
	cout << "2) Удалить строку" << endl;
	cout << "3) Редактировать строку" << endl;
	do
	{
		cout << "Пожалуйста выберете нужный вариант (от 1 до 3): ";
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
			cout << "Введите новое название планеты: ";
			cin >> current_name;
			solar_system_planets[(*how_many_lines)].set_name(current_name);
			cout << "Введите диаметр планеты: ";
			cin >> current_size;
			solar_system_planets[(*how_many_lines)].set_size(current_size);
			cout << "Введите показатель наличия жизни (цифра 0, если нет, или 1, есть существует): ";
			cin >> current_life;
			solar_system_planets[(*how_many_lines)].set_life(current_life);
			cout << "Введите количество спутников: ";
			cin >> current_sats;
			solar_system_planets[(*how_many_lines)].set_amount_of_sats(current_sats);
			(*how_many_lines)++;
			cout << endl;
		}
		else
		{
			cout << endl << "Ошибка: невозможно добавить строку - переполнена допустимая база!";
		}
	}
	if (method==2)
	{
		if ((*how_many_lines)>0)
		{
			int answ;
			cout << endl << "Введите номер строки для удаления: ";
			cin >> answ;
			for (int i=answ-1; i<=(*how_many_lines); i++)
			{
				solar_system_planets[i]=solar_system_planets[i+1];
			}
			(*how_many_lines)--;
			cout << "Удаление " << answ << " строки успешно выполнено.";
			cout << endl << endl;
		}
		else
		{
			cout << endl << "Ошибка: невозможно удалить строку!" << endl;
		}
	}
	if (method==3)
	{
		int num_line, num_what;
		cout << endl << "Введите номер строки для редактирования: ";
		cin >> num_line;
		cout << endl << "Выберете, что Вы хотите отредактировать:" << endl;
		cout << "1) Название" << endl;
		cout << "2) Диаметр" << endl;
		cout << "3) Показатель наличия жизни" << endl;
		cout << "4) Количество спутников" << endl;
		do
		{
			cout << "Пожалуйста выберете нужный вариант (от 1 до 4): ";
			cin >> num_what;
		}
		while ((num_what<1) && (num_what>4));
		switch (num_what)
		{
			case 1: char* current_name;
					current_name=new char[20];
					cout << endl << "Введите название планеты: ";
					cin >> current_name;
					solar_system_planets[num_line-1].set_name(current_name);
					cout << endl << "Название планеты изменено успешно." << endl << endl;
					break;
			case 2: long int current_size;
					cout << endl << "Введите диаметр планеты: ";
					cin >> current_size;
					solar_system_planets[num_line-1].set_size(current_size);
					cout << endl << "Диаметр планеты изменен успешно." << endl << endl;
					break;
			case 3: bool current_life;
					cout << endl << "Введите показатель наличия жизни (цифра 0, если нет, или 1, есть существует): ";
					cin >> current_life;
					solar_system_planets[num_line-1].set_life(current_life);
					cout << endl << "Показатель наличия жизни планеты изменен успешно." << endl << endl;
					break;
			case 4: int current_sats;
					cout << endl << "Введите количество спутников: ";
					cin >> current_sats;
					solar_system_planets[num_line-1].set_amount_of_sats(current_sats);
					cout << endl << "Количество спутников планеты изменено успешно." << endl << endl;
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
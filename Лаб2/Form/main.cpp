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
	cout << "База данных, созданная из данных из анкеты для опроса населения о качестве услуг связи, состоит из ответов каждого человека на следующие вопросы: " << endl;
	cout << "1) Имя человека" << endl;
	cout << "2) Его возраст" << endl;
	cout << "3) Его пол" << endl;
	cout << "4) Оператор связи, которым он пользуется" << endl;
	cout << "5) Его оценка качества услуг оператора (положительная - 1, отрицательная - 0)" << endl;
	cout << "6) Его желание изменить оператора связи (0 - не желает, 1 - желает)" << endl;
	cout << "База данных содержит максимум 15 ячеек." << endl << endl;
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
						cout << endl << "Ошибка: нет базы данных!" << endl << endl;
					}
					break;
			case 3: if ((how_many_lines)!=0)
					{
						sort_menu(cell, &how_many_lines);
						cout << endl << "Сортировка была поизведена успешно." << endl;
						cout << endl;
					}
					else
					{
						cout << endl << "Ошибка: нет базы данных!" << endl << endl;
					}
					break;
			case 4: if ((how_many_lines)!=0)
					{
						edit_menu(cell, &how_many_lines);
					}
					else
					{
						cout << endl << "Ошибка: нет базы данных!" << endl << endl;
					}
					break; 
			case 5: if ((how_many_lines)!=0)
					{
						cout << endl;
						cout << "Имя" << setw(longest_name-3+10) << right << "Возраст" << setw(10) << right << "Пол" << setw(longest_provider+10) << right << "Оператор" << setw(10) << right << "Оценка" << setw(20) << right << "Желание изменить" << endl;
						for (int i=0; i<how_many_lines; i++)
						{
							cell[i].show(&longest_name, &longest_provider);
						}
						cout << "Всего строк: " << how_many_lines << endl;
						cout << endl;
					}
					else
					{
						cout << endl << "Ошибка: нет базы данных!" << endl << endl;
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
	cout << "МЕНЮ" << endl;
	cout << "l) Считать из файла" << endl;
	cout << "2) Запись в файл" << endl;
	cout << "3) Сортировка" << endl;
	cout << "4) Редактирование" << endl;
	cout << "5) Вывод на экран" << endl;
	cout << "6) Выход" << endl;
	do
	{
		cout << "Пожалуйста выберете нужный вариант (от 1 до 6): ";
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
		cout << "Ошибка: Файла не существует!" << endl << endl;
	}
	else
	{
		cout << endl << "Файл \'base.txt\' успешно открыт." << endl;
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
		cout << "Чтение из файла \'base.txt\' успешно завершено." << endl;
		cout << endl;
	}
}
void write_to_file(char *filename, unit* cell, int* how_many_lines) 
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
			fout << cell[i];
		}
		fout.close();
		cout << endl << "Запись в файл \'base.txt\' успешно завершена." << endl;
		cout << endl;
	}
}
void sort_menu(unit* cell, int* how_many_lines)
{
	int answ;
	cout << endl;
	cout << "МЕНЮ СОРТИРОВКИ" << endl;
	cout << "Столбец, по которому нужно отсортировать:" << endl;
	cout << "1) Имя" << endl;
	cout << "2) Возраст" << endl;
	cout << "3) Пол" << endl;
	cout << "4) Оператор связи" << endl;
	cout << "5) Положительная/отрицательная оценка качества услуг" << endl;
	cout << "6) Желание изменить оператора связи" << endl;
	do
	{
		cout << "Пожалуйста выберете нужный вариант (от 1 до 6): ";
		cin >> answ;
	}
	while ((answ<1) && (answ>6));
	sort_method(cell, how_many_lines, answ);
}
void sort_method(unit* cell, int* how_many_lines, int column)
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
			cout << endl << "Введите имя человека: ";
			cin >> another_name;
			cell[(*how_many_lines)].set_name(another_name);
			cout << "Введите возраст человека: ";
			cin >> another_age;
			cell[(*how_many_lines)].set_age(another_age);
			cout << "Введите пол человека: ";
			cin >> another_gend;
			cell[(*how_many_lines)].set_gend(another_gend);
			cout << "Введите название оператора связи: ";
			cin >> another_prov;
			cell[(*how_many_lines)].set_provider(another_prov);
			cout << "Введите показатель его оценки качества связи (0 - отрицательный, 1 - положительный): ";
			cin >> another_q;
			cell[(*how_many_lines)].set_quality(another_q);
			cout << "Введите показатель его желания изменить оператора (0 - отрицательный, 1 - положительный): ";
			cin >> another_wc;
			cell[(*how_many_lines)].set_willchange(another_wc);
			(*how_many_lines)++;
			cout << endl << "Добавление строки в базу было произведено успешно." << endl;
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
				cell[i]=cell[i+1];
			}
			(*how_many_lines)--;
			cout << endl << "Удаление " << answ << " строки успешно выполнено.";
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
		cout << "1) Имя" << endl;
		cout << "2) Возраст" << endl;
		cout << "3) Пол" << endl;
		cout << "4) Оператор связи" << endl;
		cout << "5) Оценка качества услуг" << endl;
		cout << "6) Желание изменить оператора" << endl;
		do
		{
			cout << "Пожалуйста выберете нужный вариант (от 1 до 6): ";
			cin >> num_what;
		}
		while ((num_what<1) && (num_what>6));
		switch (num_what)
		{
			case 1: char* another_name;
					another_name=new char[20];
					cout << endl << "Введите новое имя: ";
					cin >> another_name;
					cell[num_line-1].set_name(another_name);
					cout << endl << "Имя изменено успешно." << endl << endl;
					break;
			case 2: int another_age;
					cout << endl << "Введите новый возраст: ";
					cin >> another_age;
					cell[num_line-1].set_age(another_age);
					cout << endl << "Возраст изменен успешно." << endl << endl;
					break;
			case 3: char another_gend;
					cout << endl << "Введите новый пол: ";
					cin >> another_gend;
					cell[num_line-1].set_gend(another_gend);
					cout << endl << "Пол изменен успешно." << endl << endl;
					break;
			case 4: char* another_provider;
					another_provider=new char[20];
					cout << endl << "Введите новое название оператора: ";
					cin >> another_provider;
					cell[num_line-1].set_provider(another_provider);
					cout << endl << "Название оператора изменено успешно." << endl << endl;
					break;
			case 5: bool another_quality;
					cout << endl << "Введите новую оценку качества услуг: ";
					cin >> another_quality;
					cell[num_line-1].set_quality(another_quality);
					cout << endl << "Показатель качества услуг изменен успешно." << endl << endl;
					break;
			case 6: bool another_willchange;
					cout << endl << "Введите показатель желания изменить оператора: ";
					cin >> another_willchange;
					cell[num_line-1].set_willchange(another_willchange);
					cout << endl << "Показатель желания изменить оператора изменен успешно." << endl << endl;
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
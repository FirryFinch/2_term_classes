#include "unit.h"
#include "proto.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
unit::unit()
{

}
unit::~unit()
{

}

char* unit::get_name()
{
	return unit::name;
}
int unit::get_age()
{
	return unit::age;
}
char unit::get_gend()
{
	return unit::gend;
}
char* unit::get_provider()
{
	return unit::provider;
}
bool unit::get_quality()
{
	return unit::quality;
}
bool unit::get_willchange()
{
	return unit::willchange;
}

void unit::set_name(char* new_name)
{
	unit::name=new_name;
}
void unit::set_age(int new_age)
{
	unit::age=new_age;
}
void unit::set_gend(char new_gend)
{
	unit::gend=new_gend;
}
void unit::set_provider(char* new_prov)
{
	unit::provider=new_prov;
}
void unit::set_quality(bool new_q)
{
	unit::quality=new_q;
}
void unit::set_willchange(bool new_wc)
{
	unit::willchange=new_wc;
}

void unit::show(int* longest_name, int* longest_provider)
{
	cout << unit::name << setw(*longest_name-strlen(unit::get_name())+10) << right << unit::age << setw(10) << right << unit::gend << setw(*longest_provider+10) << right << unit::provider << setw(10) << right << unit::quality << setw(20) << right << unit::willchange << endl;
}

ifstream& operator>>(ifstream& fin, unit& cell)
{
	char* another_name=new char[20];
	int another_age;
	char another_gend;
	char* another_prov=new char[20];
	bool another_q;
	bool another_wc;
	fin >> another_name >> another_age >> another_gend >> another_prov >> another_q >> another_wc;
	cell.set_name(another_name);
	cell.set_age(another_age);
	cell.set_gend(another_gend);
	cell.set_provider(another_prov);
	cell.set_quality(another_q);
	cell.set_willchange(another_wc);
	return fin;
}
ofstream& operator<<(ofstream& fout, unit& cell)
{
	fout << cell.get_name() << " " << cell.get_age() << " " << cell.get_gend() << " " << cell.get_provider() << " " << cell.get_quality() << " " << cell.get_willchange() << endl;
	return fout;
}
bool unit::operator==(unit cell)
{
	if ((cell.name == this->name) && (cell.age == this->age) && (cell.gend == this->gend) && (cell.provider == this->provider) && (cell.quality == this->quality) && (cell.willchange == this->willchange))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool unit::operator<(unit cell)
{
	if ((this->column)==1)
	{
		if (this->name < cell.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if ((this->column)==2)
		{
			if (this->age < cell.age)
			{
				return true;
			}
			else
			{
			return false;
			}
		}
		else
		{
			if ((this->column)==3)
			{
				if (this->gend < cell.gend)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if ((this->column)==4)
				{
					if (this->provider < cell.provider)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					if ((this->column)==5)
					{
						if (this->quality < cell.quality)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						if ((this->column)==6)
						{
							if (this->willchange < cell.willchange)
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						else
						return false;
					}
				}
			}
		}
	}
}
bool unit::operator>(unit cell)
{
	if ((this->column)==1)
	{
		if (this->name > cell.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if ((this->column)==2)
		{
			if (this->age > cell.age)
			{
				return true;
			}
			else
			{
			return false;
			}
		}
		else
		{
			if ((this->column)==3)
			{
				if (this->gend > cell.gend)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if ((this->column)==4)
				{
					if (this->provider > cell.provider)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					if ((this->column)==5)
					{
						if (this->quality > cell.quality)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						if ((this->column)==6)
						{
							if (this->willchange > cell.willchange)
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						else
						return false;
					}
				}
			}
		}
	}
}
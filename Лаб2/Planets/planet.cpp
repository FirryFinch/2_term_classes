#include "planet.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
Planet::Planet()
{

}
Planet::Planet(char* another_name, long int another_diameter, bool another_life, int another_sats)
{
	name=another_name;
	diameter=another_diameter;
	amount_of_sats=another_sats;
	life=another_life;
	cout << endl << "Создание объекта имени " << name << endl;
	cout << "Создание объекта размера " << diameter << endl;
	cout << "Создание объекта показателя наличия жизни " << life << endl;
	cout << "Создание объекта количества спутников " << amount_of_sats << endl << endl;
}
Planet::~Planet()
{

}

char* Planet::get_name()
{
	return Planet::name;
}
long int Planet::get_size()
{
	return Planet::diameter;
}
int Planet::get_amount_of_sats()
{
	return Planet::amount_of_sats;
}
bool Planet::get_life()
{
	return Planet::life;
}
void Planet::set_name(char* new_name)
{
	Planet::name=new_name;
}
void Planet::set_size(long int new_size)
{
	Planet::diameter=new_size;
}
void Planet::set_amount_of_sats(int new_amount_of_sats)
{
	Planet::amount_of_sats=new_amount_of_sats;
}
void Planet::set_life(bool new_life)
{
	Planet::life=new_life;
}
void Planet::show(int* longest_name)
{
	cout << Planet::name << setw(12+(*longest_name)-strlen(Planet::name)) << right << Planet::diameter << setw(10) << Planet::life << setw(13) << Planet::amount_of_sats << endl;
}

Planet& Planet::operator=(Planet& solar_system_planets)
{
	name=solar_system_planets.name;
	diameter=solar_system_planets.diameter;
	life=solar_system_planets.life;
	amount_of_sats=solar_system_planets.amount_of_sats;
	return (*this);
}
ifstream& operator>>(ifstream& fin, Planet& solar_system_planets)
{
	char* another_name=new char[20];
	long int another_diameter;
	bool another_life;
	int another_sats;
	fin >> another_name >> another_diameter >> another_life >> another_sats;
	solar_system_planets.set_name(another_name);
	solar_system_planets.set_size(another_diameter);
	solar_system_planets.set_life(another_life);
	solar_system_planets.set_amount_of_sats(another_sats);
	return fin;
}
ofstream& operator<<(ofstream& fout, Planet& solar_system_planets)
{
	fout << solar_system_planets.get_name() << " " << solar_system_planets.get_size() << " " << solar_system_planets.get_life() << " " << solar_system_planets.get_amount_of_sats() << endl;
	return fout;
}
bool Planet::operator==(Planet solar_system_planets)
{
	if ((solar_system_planets.name == this->name) && (solar_system_planets.diameter == this->diameter) && (solar_system_planets.life == this->life) && (solar_system_planets.amount_of_sats == this->amount_of_sats))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Planet::operator<(Planet solar_system_planets)
{
	if ((this->column)==1)
	{
		if (this->name < solar_system_planets.name)
		{
			true;
		}
		else
		{
			return false;
		}
	}
	if ((this->column)==2)
	{
		if (this->diameter < solar_system_planets.diameter)
		{
			true;
		}
		else
		{
			return false;
		}
	}
	if ((this->column)==3)
	{
		if (this->life < solar_system_planets.life)
		{
			true;
		}
		else
		{
			return false;
		}
	}
	if ((this->column)==4)
	{
		if (this->amount_of_sats < solar_system_planets.amount_of_sats)
		{
			true;
		}
		else
		{
			return false;
		}
	}
}
bool Planet::operator>(Planet solar_system_planets)
{
	if ((this->column)==1)
	{
		if (this->name > solar_system_planets.name)
		{
			true;
		}
		else
		{
			return false;
		}
	}
	if ((this->column)==2)
	{
		if (this->diameter > solar_system_planets.diameter)
		{
			true;
		}
		else
		{
			return false;
		}
	}
	if ((this->column)==3)
	{
		if (this->life > solar_system_planets.life)
		{
			true;
		}
		else
		{
			return false;
		}
	}
	if ((this->column)==4)
	{
		if (this->amount_of_sats > solar_system_planets.amount_of_sats)
		{
			true;
		}
		else
		{
			return false;
		}
	}
}
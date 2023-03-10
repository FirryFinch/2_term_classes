#include <iostream>
using namespace std;
class Planet
{
	friend ifstream& operator>>(ifstream&, Planet&);
	friend ofstream& operator<<(ofstream&, Planet&);
	friend void swap(Planet*, Planet*);
	public:
		Planet();
		Planet(char*, long int, bool, int);
		~Planet();
		char* get_name();
		long int get_size();
		int get_amount_of_sats();
		bool get_life();
		void set_name(char*);
		void set_size(long int);
		void set_amount_of_sats(int);
		void set_life(bool);
		void show(int*);
		Planet& operator=(Planet&);
		bool operator==(Planet);
		int column;
		bool operator<(Planet);
		bool operator>(Planet);
	private:
		char* name;
		long int diameter;
		bool life;
		int amount_of_sats;
};
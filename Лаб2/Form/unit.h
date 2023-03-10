#include <iostream>
using namespace std;
class unit
{
	friend ifstream& operator>>(ifstream&, unit&);
	friend ofstream& operator<<(ofstream&, unit&);
	friend void swap(unit*, unit*);
	public:
		unit();
		~unit();
		char* get_name();
		int get_age();
		char get_gend();
		char* get_provider();
		bool get_quality();
		bool get_willchange();
		void set_name(char*);
		void set_age(int);
		void set_gend(char);
		void set_provider(char*);
		void set_quality(bool);
		void set_willchange(bool);
		void show(int*, int*);
		bool operator==(unit);
		int column;
		bool operator<(unit);
		bool operator>(unit);
	private:
		char* name;
		int age;
		char gend;
		char* provider;
		bool quality;
		bool willchange;
};
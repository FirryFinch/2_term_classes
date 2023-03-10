#include "MySet.h"

ostream& operator<<(ostream& out, MySet& s);
MySet operator+(MySet& s1, MySet& s2);
MySet operator-(MySet& s1, MySet& s2);
MySet operator*(MySet& s1, MySet& s2);
ostream& operator<<(ostream& out, MyVector& v);
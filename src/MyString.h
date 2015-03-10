#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class MyString
{
public:
	MyString(string);
	~MyString(void);
	MyString& operator=(const MyString&);
	char& operator[](int index);  //non-const
	const char& operator[](int index) const;  //const
	int WagnerFischer(MyString&);
	int WagnerFischer2(MyString&);
	const int length() const;
	friend ostream& operator<<(ostream &out, MyString& ms)
	{
		// Since operator<< is a friend of the MyString class, we can access
		// MyString's members directly.
		out << ms.str;
		return out;
	}
private:
	string str;
};

#include "StdAfx.h"
#include "MyString.h"

MyString::MyString(string s)
{
	str = _strdup(s.c_str());
}

MyString::~MyString(void)
{
}

MyString& MyString::operator=(const MyString& ms)
{
	if (this != &ms)
	{
		str = _strdup(ms.str.c_str());
	}
	return *this;
}

char& MyString::operator[](int index)
{ 
	return str[index]; 
}

const char& MyString::operator[](int index) const
{ 
	return str[index]; 
}

const int MyString::length() const
{
	return str.length();
}

int MyString::WagnerFischer(MyString& text)
{
	int i,j,x,y,z;
	int pattern_length = this->length(); // pattern is *this
	int text_length = text.length();
	x = pattern_length + 1; y = text_length + 1;
	map<int, map<int, int>> dist;
	for (i=0;i<=pattern_length;i++)
		dist[i][0] = i;
	for (j=1;j<=text_length;j++)
		dist[0][j]= j;
	for (i=1;i<=pattern_length;i++)
	{
		for (j=1;j<=text_length;j++)
		{
			x = dist[i-1][j]+1; // upper
			y = dist[i][j-1]+1; // left
			z = dist[i-1][j-1]; // diagonal
			if ((*this)[i-1]!=text[j-1]) // a mismatch increases the cost of editing
				z++;
			dist[i][j] = min(x,min(y,z));
		}
	}

	return dist[pattern_length][text_length]; 
}
int MyString::WagnerFischer2(MyString& text)
{
	/*cout << *this << ".length() = " << this->length() << endl;
	cout << text << ".length() = " << text.length() << endl;*/
	int i, j, x, y, z;
	int pattern_length = this->length(); // pattern is *this
	int text_length = text.length();
	x = pattern_length + 1; y = text_length + 1;
	map<int, map<int, int>> dist;
	for (i = 0; i <= pattern_length; i++)
		dist[i][0] = i;
	for (j = 1; j <= text_length; j++)
		dist[0][j] = j;
	for (i = 1; i <= pattern_length; i++)
	{
		for (j = 1; j <= text_length; j++)
		{
			x = dist[i - 1][j] + 1; // upper
			y = dist[i][j - 1] + 1; // left
			z = dist[i - 1][j - 1]; // diagonal
			if ((*this)[i - 1] != text[j - 1]) // a mismatch increases the cost of editing
				z += 2;
			dist[i][j] = min(x, min(y, z));
		}
	}

	return dist[pattern_length][text_length];
}
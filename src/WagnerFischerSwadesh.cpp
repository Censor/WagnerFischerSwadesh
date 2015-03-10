// WagnerFischerSwadesh.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyString.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char ch; 
	unsigned int i=0;
	int result;
	int total_distance_1 = 0;
	int total_distance_2 = 0;
	int sum_of_max = 0;
	int sum_of_all = 0;
	char fileName[50];
	char fileName2[50];
	cout << "Enter the first file name: ";
	cin.getline(fileName,50);
	ifstream fIn(fileName);
	if (fIn.fail())
	{
		cerr << "Cannot open " << fileName << endl;
		return -1;
	}
	cout << "Enter the second file name: ";
	cin.getline(fileName2,50);
	ifstream fIn2(fileName2);
	if (fIn2.fail())
	{
		cerr << "Cannot open " << fileName2 << endl;
		return -1;
	}
	string str1, str2; 
	while(getline(fIn,str1))
	{
		//cout << "The STL string is: " << str1 << endl;
		MyString *pattern = new MyString(str1);
		//cout << "Your String 1 is: " << *pattern << endl;
		getline(fIn2,str2);
		//cout << "The STL string is: " << str2 << endl;
		//cout << "Your String 1 is: " << *pattern << endl;
		MyString *text = new MyString(str2);
		//cout << "Your String 2 is: " << *text << endl;	
		result = pattern->WagnerFischer(*text);
		cout << "The Levenshtein distance I between " << *pattern << " and " << *text;
		cout << " is equal to " << result << endl;
		total_distance_1 += result;
		sum_of_max += max(str1.length(),str2.length());
		result = pattern->WagnerFischer2(*text);
		cout << "The Levenshtein distance II between " << *pattern << " and " << *text;
		cout << " is equal to " << result << endl;
		total_distance_2 += result;
		sum_of_all += pattern->length() + text->length();
		delete pattern;
		delete text;
	}
	cout << "The normalized Levenshtein I distance between " << fileName;
	cout << " and " << fileName2 << " is " << (double)total_distance_1/sum_of_max << endl;
	cout << "The normalized Levenshtein II distance between " << fileName;
	cout << " and " << fileName2 << " is " << (double)total_distance_2/sum_of_all << endl;
	cin >> ch;
	cout << ch;
	return 0;
}


// to convert a string to integer

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iostream>
#include<algorithm>
#include <sstream>
using namespace std;

int main()
{
	string s = "12345";
	int x = 0;
	
	stringstream convert(s); //object from the class stringstream
    convert>>x;
	
	cout << x + 5 << endl;
	return 0;
}

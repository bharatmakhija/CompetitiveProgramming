#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	char a;
	a='1'; // here character is a number so i want to print it
	cout << a << endl; // this will be printed as 1 
	cout << int(a) << endl; // here ascii of 1 will get printed which is 49 not 1 
	// so if a = 1 is a character then int(a) doesn't make it integer 1 but integer 49 
	
	// what if i want to use 1 as it is in multiplication
	// make an integer x;
	
	int x;
	x = 0 + a; // here 0 is integer x is integer and a is character
	cout << x<< endl; // lets check!!
	// here again it prints 49 ie. a = 1 will get converted in to 49 added to 0 and done
	
	x= 0 + int(a);
	cout << x << endl;
	// again 49
	 
	 
	 // can we add to characters and lets check;
	 
	 x = a - '0';
	 cout << x << endl; // yes it worked
	 //0 is character a is also character///
	 
	 
	 // can we add two numbers using this basic conversion technique..yes we can
	 
	 cout << "enter strinng of numbers" << endl;
	 string abc;
	 cin >> abc;
	 
	 int sum=0;
	 int k = abc.size();
	 for(int i=0;i< k;i++)
	 sum = sum + (abc[i]- '0');
	 
	 cout << "sum of digits is " << sum << endl;
	// so yeah we did it we can use this technique to take input as string and use it in mathematical manipulations 
	return 0;
}

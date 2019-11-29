/*Leet- ZigzagConversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

*/


#include<bits/stdc++.h>
using namespace std;

string inzigzagpattern(string s, int n)
{   //if string is null
    if(s == "" || n==0)
    return "";
	
	// if no of lines are 1
	if(n == 1)
	return s;
	
	// if no of lines are > size of string , then in each line only one char will be able to come so return s simply
	
	if(n >= s.size())
	return s;
	
  // overall we need n number of different strings (each string for one line) that we will concatenated in the end and return 
  
  vector<string> r(n); // it will create a string vector of size n, size isn't mandatory but we can use it 
  
  int currentrow = 0;
  int step = 1;	
  for(int i=0; i < s.size(); i++)
  {
	  if(currentrow == 0)
  	  step = 1;
  	  
  	  if(currentrow == n-1)
  	  step = -1;
  	  r[currentrow] += s[i];
  	  
  	  currentrow += step;
  }	
 	
	string result = "";
	
	for(int i=0; i < n; i++)
	result += r[i];
	
	return result;
}

string convert(string s, int numRows) {
    int length;
    length = s.length();
    if(length <= 2 || numRows == 1)
    return s;
    string op = "";
    
    int *x = new int[length];
    int index = 0;
    int flag=0;
    for(int i=0;i<length;i++)
    {
        x[i]= index;
        
        if(index==numRows-1)
        flag=1;
        
        if(index == 0)
        flag=0;
        
        if(flag)
        index--;
        else
        index++;
    }
    
    for(int i=0;i<numRows;i++)
    { // flaw of this is you need to revisit the array n number of time to finally create the ans string.
        for(int j=0; j< length;j++)
        {
            if(x[j]==i)
            op+=s[j];
            
        }
    }
    
    return op;
        
    }



int main()
{
	//print("enter string \n");
	cout << "enter string \n";
	string s;
	cin >> s;
	//print(" \n enter number of lines");
	cout << "enter num of lines \n";
	int lines;
	cin >> lines;
	//cout << convert(s,lines) << endl;
	cout << inzigzagpattern(s,lines) << endl; // this is more optimized version
	return 0;
}

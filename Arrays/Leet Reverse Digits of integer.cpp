/*Leetcode

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*/

#include<bits/stdc++.h>
using namespace std;

  int reverse(int x) {
        int  res = 0;
        while (x!=0){
            if (res > INT_MAX/10 || res < INT_MIN/10) // this is bounds check , why is this overflow condition like such, i tried removied /10 in this, gave error in 1 test case. 
			{
                return 0;
            }
            res = res*10+ x%10;
            x= x/10;
        }
        return res;
    }
    
    int main()
    {
    	cout << "enter num \n";
    	int x;
    	cin >> x;
    	cout << "ans is " << reverse(x) << endl;
    	return 0;
	}

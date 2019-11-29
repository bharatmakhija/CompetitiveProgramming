#include<bits/stdc++.h>
using namespace std;

int findsize(int x)
{int count = 0;
  
  while(x)
  {
  	x = x/10;
  	count++;
  }
  
  return count;
}
int findtidy(int x)
{
	int size = findsize(x);
	
	if(size == 1)
	return x;
	
	int i = 1;
	while(i < size)
	{
		int y = x % int(pow(10,i));
		int z = x % int(pow(10,i+1));
		
		if(z <= y && (z != 0 && y != 0))
		{
			i++;
		}
		else
		{
			int new_z = z-1;
			int new_y = 9;
			
			x = x + (new_z - z)*int(pow(10,i)) + (new_y - y)*int(pow(10,i-1));
		}
	}
	return x;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		cout << findtidy(x) << endl;
	}
	return 0;
}

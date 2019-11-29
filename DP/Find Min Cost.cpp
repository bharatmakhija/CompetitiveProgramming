/** we are given cost matrix cost[rows][columns] , write a function that returns min cost to reach to (m,n) from (0,0)**/
// it is solved using dynamic programming DP 

#include<cstdio>
#include<iostream>
using namespace std;

void printmate(int **maze,int rows, int cols)
{
	
	for(int i=0;i< rows; i++)
	{
		for(int j=0;j< cols;j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	
}

void setmat(int **maze,int rows, int cols)
{
	int x;
	cout << "Enter elements of maze continuously" << endl;
		for(int i=0;i< rows; i++)
	{
		for(int j=0;j< cols;j++)
		{
			cin >> x;
			maze[i][j]=x;
		}
	}
	
}

int min(int a,int b, int c)
{
	if(a<b)
	return (a<c)? a:c;
	else
	return (b<c)? b:c;
}


int MinCost(int **maze,int rows,int cols)
{
	int mincost=0;
	int p,q;
	cout << "Enter the position up to which min is to find" << endl;
	cin >> p >> q;
	cout << p << " " << q << endl;
	int tab[p][q];
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<q;j++)
		{
			tab[i][j]=0;
		}
	}
	
	if(p > rows || q > cols)
	return 0;
	
	tab[0][0]=maze[0][0];
	
	// for first row of tab
	
	for(int i=1;i<q;i++)
	{
		tab[0][i]=maze[0][i]+tab[0][i-1];
	}
	
	// for first column of tab
	
	for(int i=1;i<p;i++)
	{
		tab[i][0]=maze[i][0]+tab[i-1][0];
	}
	
	// now filling up the rest
	
	for(int i=1;i<p;i++)
	{
		for(int j=1;j<q;j++)
		{
			tab[i][j]= maze[i][j]+ min(tab[i-1][j],tab[i][j-1],tab[i-1][j-1]);
		}
	}
	
	cout << "Min cost matrix is " << endl;	
	for(int i=0;i< p; i++)
	{
		for(int j=0;j< q;j++)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
	
	mincost = tab[p-1][q-1];	
	return mincost;
}

int main()
{
	// first we want user to enter no. of rows and columns
	cout << " Enter No. of rows and columns" << endl;
	int rows,cols;
	cin >> rows >> cols;
	
	int **maze = new int*[rows];
	for(int i=0;i<cols;i++)
	{
		maze[i] = new int[cols];
	}
	setmat(maze,rows,cols);
//	printmate(maze,rows,cols);
// okeys up to here we have taken input successfully 
// lets find min cost now
int mincost;
mincost = MinCost(maze,rows,cols); /// answer
if(mincost==0)
cout << "Check your input" << endl;
else	
cout << "Minimum cost is " << mincost;
return 0;
}

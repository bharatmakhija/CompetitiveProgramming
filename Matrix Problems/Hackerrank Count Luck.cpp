#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

Ron and Hermione are deep in the Forbidden Forest collecting potion ingredients, and they've managed to lose their way. The path out of the forest is blocked, so they must make their way to a portkey that 
will transport them back to Hogwarts.

Consider the forest as an NXM  grid. Each cell is either empty (represented by .) or blocked by a tree (represented by X ). Ron and Hermione can move (together inside a single cell) LEFT, RIGHT, UP, and DOWN 
through empty cells, but they cannot travel through a tree cell. Their starting cell is marked with the character M , and the cell with the portkey is marked with a *. The upper-left corner is indexed as (0,0).

.X.X......X
.X*.X.XXX.X
.XX.X.XM...
......XXXX.
In example above, Ron and Hermione are located at index(2,7)  and the portkey is at (1,2) . Each cell is indexed according to Matrix Conventions.

Hermione decides it's time to find the portkey and leave. Each time they are able to move in more than one direction, she waves her wand and it points to the correct direction. 
Ron is betting that she will have to wave her wand exactly K times. Can you determine if Ron's guesses are correct?
if correct return true else false. 
Note: It is guaranteed that there is only one path from the starting location to the portkey.

direction arrays, issafe function, explore adj cells 


here what this program is doing is just tracing the path not actually counting how many times wand is moved!!  	
*/
struct point
{
    int i;
    int j;
};    

void print(int **a,int n,int m)
{
	//cout <<endl <<  "in print function address :" << a <<  " " << *a  << " " <<  **a;
    cout << "inprint" << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}
int issafe(char **forest,int x,int y,int n,int m)
{
    if(x>=0 && x< n && y>=0 && y < m && (forest[x][y]=='.'||forest[x][y]=='M'))
    {   forest[x][y]='C';
        return 1;
    }
    return 0;   
}    

int Tracepath(char ** forest,int x,int y,int n,int m,point end,int **solpath)
{
    //cout << "in tracepath \n";
     if(x== end.i && y == end.j)
    { cout << "reached";
        solpath[x][y]=1;
        print(solpath,n,m);
      // count no. of magic wands moved  
    }    
    else
    {
        if(issafe(forest,x,y,n,m))
        {
            solpath[x][y]=1;
            //print(solpath,n,m);
            Tracepath(forest,x-1,y,n,m,end,solpath); // up
            Tracepath(forest,x+1,y,n,m,end,solpath); // down
            Tracepath(forest,x,y-1,n,m,end,solpath); // left
            Tracepath(forest,x,y+1,n,m,end,solpath); // right
            solpath[x][y]=0;
        }    
    }
    return 0;
    
}    


void WandCount(char **forest,int n,int m,point start,point end)
{
   //print(a,n,m);
    
    //cout << "wandcount1" << endl;
    
   int ** solpath= new int*[n];
   for(int i=0;i<n;i++)
   {
       solpath[i]= new int[m];
   }
    //cout << "wandcount1.5" << endl;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    solpath[i][j]=0; // initially no solution exist
        
   //print(solpath,n,m);     
     int x,y;   
     x=start.i;
    y= start.j;
    solpath[x][y]=1;
    //cout << "wandcount2" << endl;
    Tracepath(forest,x,y,n,m,end,solpath);    
   // cout << "wandcount1.5" << endl;
    
}    


int main()
{
    int test; cin >> test;
    while(test)
    {
        int n,m; cin >> n >> m;
        char **forest = new char*[n];
        for(int i=0;i<n;i++)
        {forest[i] = new char[m];
        }
        
        point start,end;  // starting and ending points are saved beforehand
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
             {
                cin >> forest[i][j];
                if(forest[i][j] == 'M')
                {
                    start.i =i;
                    start.j=j;
                }
                
                if(forest[i][j] == '*')
                {
                    end.i =i;
                    end.j=j;
                }
                
            }   
        }
        int check;
        cin >> check;
        WandCount(forest,n,m,start,end);     
      test--;  
    }    
    
//_______________________________________________
return 0; // end of program    
}


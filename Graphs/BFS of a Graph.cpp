#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int PrintMat(int **mat,int nodes) // this will print the matrix 
{
    for(int i=0;i<nodes;i++)
    {   for(int j=0;j<nodes;j++)
        { 
            cout << mat[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}

void GetInput(int **mat,int edges) // this function takes number of edges, and keep asking for vertices (source and dest) and keep inserting in the matrix. here graph is undirected!!
{
    int x,y;
    for(int i=0;i<edges;i++)
    {
        cin >> x >> y;
        mat[x-1][y-1]=1;
        mat[y-1][x-1]=1;
    }  
}

void InitializeWith(int **mat,int nodes,int value)  // this function can initialize a matrix with any value you want
{
    for(int i=0;i<nodes;i++)
    for(int j=0;j<nodes;j++)
      mat[i][j]=value;  
}

void PrintSD(int **mat,int nodes,int source)
{ 
    int *dist;
    dist = new int[nodes];
    for(int i=0;i<nodes;i++)
    dist[i]=-1;   // why -1? because distance can be 0 as well !!
  
    int *v = new int[nodes];
    for(int i=0;i<nodes;i++)  // to keep track of vertices visited!!
    v[i]=0;                   
    
    cout << "reaches";
     v[source]=1; // source is marked visited!!
     dist[source]=0; // and its distance from itself is 0. 
     
     // this is the basic setting!! remember it!!
    
    for(int i=0;i<nodes;i++)
    {
        if(mat[source][i]==1) // if there is a path from source to this vertex
          { dist[i]=6;        // here each edge is of length 6    
            v[i]=1;           // mark it visited. 
          }
    }
     // so after this , all directly connected nodes distance is updated and there visited is marked. 
     // again run through 
     
    for(int i=0;i<nodes;i++)
    {
        if( v[i]==0) // if not visited 
        {
            for(int j=0;i<nodes;j++) // check if ith node is connected to any of the visited nodes
             {
                if(mat[i][j]==1) // if yes 
                {
                    if(dist[i]==-1) 
                     dist[i]= dist[j]+6;
                    else
                    {
                        if(dist[j]>0) 
                        if(dist[j]+6< dist[i]) // update only if new distance is smaller than prev distance
                         dist[i]=dist[j]+6;   
                    }    
                }
             }   
            v[i]=1;
        }    
    }
    
    // print the shortest distance!!
    for(int i=0;i< nodes;i++)
    {
        if(i!=source)
        cout << dist[i] << " ";    
    }
    cout << endl;
}    

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;cin>>t; // t is number of test cases
    while(t)
    {    
        int nodes,edges; 
        cin>> nodes >> edges;
        // this is how you create a 2D Matrix in C++
        int *mat[nodes];   
        for(int i=0;i<nodes;i++)
        mat[i]= new int[nodes];
        
        // here mat is nothing but a pointer to a pointer , mat[0] is a pointer , mat[0][0] is an element, so to pass it to a function we pass a pointer to a pointer to that function
        InitializeWith(mat,nodes,0);  
        
        GetInput(mat,edges);
        int source; cin >> source;
        PrintMat(mat,nodes);
        cout << "bla";
        // now matrix of a graph is made!! we need to find shortest distance from source 
        PrintSD(mat,nodes,source-1);
        t--;
    }
    
    return 0;
}


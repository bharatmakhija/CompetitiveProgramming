#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<list>
#define inf 99999

/*
Given a graph(undirected or directed) and a source vertex in graph, find shortest paths from source to all vertices in the given graph.
 
 ** -- it works both on directed and undirected as long as the weight of the edge is non negative number. 
 
 Algorithm
1) Create a set sptSet (shortest path tree set) that keeps track of vertices included in shortest path tree, i.e., whose minimum distance 
from source is calculated and finalized. Initially, this set is empty.
2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign distance value as 0 for
 the source vertex so that it is picked first.
3) While sptSet doesn’t include all vertices
….a) Pick a vertex u which is not there in sptSetand has minimum distance value.
….b) Include u to sptSet.
….c) Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices. 
     For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance
	 value of v, then update the distance value of v.

Remember : 

Dijkstras will work good with adj matrix representation than adj list if no of nodes are less. as it will take almost same time to access Adj list or matrix . However 
as no of nodes will increase , matrix size will increase 2 folds first of all, also we will be required to traverse full row to find adjacent nodes
consider a case of 10000 nodes where 0 points to 1 only however we still need to traverse the full row of matrix however in adj list it will finish v quickly. 
so if no. of nodes are more adj list is actually the best way. 
In real time scenario actually Adj list will suit up to the task.  
*/

using namespace std;
class graph{
    int vertices;
    list<int> *adj;
    bool *visited;
    int *shortpath;
    int source;
    public:
    
    graph(int v)
    {
        this->vertices = v;
        adj = new list<int>[vertices];
        visited = new bool[vertices];
        for(int i=0;i<vertices;i++)
        visited[i]=false;
        shortpath = new int[vertices];
        fill(shortpath,shortpath+vertices,inf);
    }
    
    void addedge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int min(int a, int b)
    {
        return (a>=b)? b:a;
    }
    
   void setsource(int s)
   {
   	this->source = s;
   	shortpath[s]=0;
   }
    
    int getmin()
    {
    	int min = inf;
    	int minindex;
    	for(int i=0; i< vertices ;i++)
    	if(visited[i]==false)
    	if(shortpath[i] < min)
    	{
    		min = shortpath[i];
    		minindex = i;
		}
		return minindex;
	}
    
	void dijkstras()
    { 
    
  	  
	  int count=0;
      while(count <= vertices){
        int u;
        u= getmin();
        visited[u]= true;
        count++;
        for(list<int>::iterator i=adj[u].begin();i!= adj[u].end();i++)
        {
        	int x = *i;
        	if(visited[x]==false && shortpath[u]!= inf && shortpath[u]+6 < shortpath[x])
        	shortpath[x]= shortpath[u]+6;
		}
	}
	printshortpath();
    }
    
    void printshortpath()
    {
       for(int i=0; i<vertices;i++)
       {
       		//cout << i << "  " << source << endl;
           if(i!= source)
           {
           		if(visited[i]==true)
           		{
           			cout << shortpath[i] << " ";
				}
				else
				cout << "-1 ";
		   }
		}
		cout << endl;    
	}
};    


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int tc; cin >> tc;
    while(tc--)
    {
        int nodes, edges;cin >> nodes >> edges;
        graph g(nodes);  // it will create graph and initialize the adj list to work
        while(edges--)
        {
            int x,y; cin >> x >> y;
            g.addedge(x-1,y-1);  // keep adding the edge
        }
        int source; cin >> source;
        g.setsource(source-1); // set the source. 
        g.dijkstras(); // run Dijkstras
    }
    
    return 0;
}

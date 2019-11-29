/*
 * C++ Program to Implement Adjacency List
 */
#include <iostream>
#include <cstdlib>
using namespace std;
 
/* Read this ........................................................

What i want to do is i want to create an adjacency list.
where it is used? 
In problems related to Graphs. Infact Adjacency list is a way to represent a graph ( another way is Adjacency Matrix). 

Adjacency list is bacically like you have a pointer pointing to a list(array of pointers ) which has length == num of vertices , 
 if 0 is connected  to 1 and 2 then list[0] will look like
 
 list[0] --> [1] --> [2]  // list of 0 is pointing to node 1 which is pointing to node 2, so all vertices to which 0 is connected to can be traversed easily with this data structure.   
 
 similary if graph is undirected then 0 will be added to list[1] and list[2] as well. 
 
 list[1]--> [0]
 list[2]--> [0]
 
 so i want to create a datastructure in which i declare it as a graph , and automatically its adjacency list will get created for me to work on!! Simple!
 
 so i need to create few structures first of all. 
 
 adjacencyNode, adjlist   
 
*/ 

/*
 * Adjacency List Node
 */ 
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;  // a pointer to point to next adjNode, this is how we declare a pointer inside a structure to another stucture 
};
 
/*
 * Adjacency List
 */  
struct AdjList
{
    struct AdjListNode *head;   // a pointer pointing to adjNode 
};
 
/*
 * Class Graph
 */ 
class Graph
{
    private:
        int V;        // to store number of vertices 
        struct AdjList* array; // here array is a pointer which will point to a list of pointers. this list wil be of size v.Every element of list will have pointer head that can point to a AdjlistNode. 
    public:
        Graph(int V)  // this is a constructor it runs automaticaly when a graph variable is declared 
        {
            this->V = V;
            array = new AdjList [V]; 
            for (int i = 0; i < V; ++i)
                array[i].head = NULL; // we made every head pointer of all elements of list to point to NULL.
        }
        
        // upto this point sets up automatically when a graph is declared with v, i.e a adjacency list sturcture gets set up!!
        
		/*
         * Creating New Adjacency List Node
         */  
        AdjListNode* newAdjListNode(int dest)
        {
            AdjListNode* newNode = new AdjListNode;
            newNode->dest = dest;
            newNode->next = NULL;
            return newNode;
        } // this function creates a adjlistnode for given vertex number and returns it
        
		
		
		/*
         * Adding Edge to Graph, its for undirected graph, to make it directed remove dest--> source pointing!!
         */ 
        void addEdge(int src, int dest)
        {
        	// we basically create a adjlistnode for dest and add it to adjlist[src] !! done 
        	
            AdjListNode* newNode = newAdjListNode(dest); 
            newNode->next = array[src].head; // head is pointing to null initially. if later next of newNode will hold what head was pointing to . // i.e. every new node being added will be added to front of list element. 
            array[src].head = newNode;
            newNode = newAdjListNode(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        }
        /*
         * Print the Adj List of graph
         */ 
        void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                AdjListNode* pCrawl = array[v].head;
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (pCrawl)
                {
                    cout<<"-> "<<pCrawl->dest;
                    pCrawl = pCrawl->next;
                }
                cout<<endl;
            }
        }
};
 
/*
 * Main
 */ 
int main()
{
    Graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);
 
    // print the adjacency list representation of the above graph
    gh.printGraph();
 
    return 0;
}

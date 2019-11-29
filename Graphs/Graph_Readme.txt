What is the Objective?
-----------------------------------
To understand Different Graph algorithms. 

<NOTE: Every code has hell lot of commented lines >
2 types of Graphs are there:
Directed
Undirected 

In terms of having cycle: (These are basically subcategories)
Cyclic 
Acyclic 

Representations of Graph is done in following 4 ways:
adjacency list 
adjacency matrix
incidence matrix 
edge list

What cpp files will Teach you : (What is COVERED Till Now)
-------------------------------------------------------------------------------------------------------------------------------------------------
1. Creating Adj List of graph: 2 slightly different approaches to create Adjacency List.
2. BFS of Graph --> Understand how bfs applied to a graph Adjacency Martrix.
3. Dijkstras Algorithm --> Normally without any extra Datastructure Implementation Dijkstras take O(V^2) time. 
	One imp thing to remember is while implementing Dijkstras if you use Min Heap (Which is a binary Heap) datastructure to find closest 
	node it will reduce Time complexity. However space complexity will be more. It depends what you want. See the problem. So we can say we are using Binary
	Heap as a priority queue here. Time Complexity for this is O((ElogV + VlogV) (where E > V ofcourse). Want to reduce complexity further..There is another 
	Heap called fabonacci heap, Fibonacci Heap takes O(1) time for decrease-key operation while Binary Heap takes O(logV) time.
	so using Fabonacci Heap instead Time complexity can be further reduced to O(E + VlogV) ==> O(VlogV).
	The code calculates shortest distance, but doesn’t calculate the path information. We can create a parent array, update the parent array when distance is
	updated (like prim’s implementation) and use it show the shortest path from source to different vertices.
	The code is for undirected graph, same dijekstra function can be used for directed graphs also.
	Dijkstra’s algorithm doesn’t work for graphs with negative weight edges. For graphs with negative weight edges, Bellman–Ford algorithm can be used.
	

	








To Cover:
-----------------------------------------------------------------------------------------------------------------------------------------------------
Depth First Search.
Strongly Connected Components.
Biconnected Components, Finding articulation points and bridges.
Prims Algorithm
Kruskal Algorithm
Floyd Warshall algorithm
Minimum Spanning Tree
Floodfill Algorithm
Topological sort
Bellman-Ford Algorithm.
Euler Tour/Path.
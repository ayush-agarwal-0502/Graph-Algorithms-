# Graph-Algorithms-
C++ implementation of Graph algorithms such as BFS (iterative and recursive) , DFS (iterative and recursive) , Grid Graph PathFinder algorithm )BFS Implementation ) , Dijkstra Algorithm , as well as classes for weighted and unweighted graphs all explained 

## Motivation - 

Started reading Graph Theory while reading DSA (Data Structures and Algorithms) and felt fascinated by what all could be achieved using graph theory . 
So decided to try out few basic algorithms myself buy hand in C++ .

## About the Code :

Classes and their methods :
* Unweighted_graph :
  * void addedge_directed(int a , int b );
  * void addedge_undirected(int a , int b );
  * void print_graph();
  * void BFS_iterative(int a);
  * void BFS_recursive(int a);
  * void BFS_recursive_util(int a, queue<int>& q, map<int,bool>& visited);
  * void DFS_iterative(int a);
  * void DFS_recursive(int a);
  * void DFS_recursive_util(int a, map<int,bool>& visited);
* Grid_graph : 
  * void pathfinder(int src_r,int src_c,int dest_r,int dest_c);
  * void neighbour_adder(int r,int c,queue<int>& R,queue<int>& C,vector<vector<bool>>& visited);
* Weighted_graph :
  * void addedge_undirected_weighted(int a, int b, int weight);
  * void addedge_directed_weighted(int a, int b, int weight);
  * void print_weighted_graph();
  * void dijkstra(int src);
 
 




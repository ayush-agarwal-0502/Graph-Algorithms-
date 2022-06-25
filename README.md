# Graph-Algorithms-
C++ implementation of Graph algorithms such as BFS (iterative and recursive) , DFS (iterative and recursive) , Grid Graph PathFinder algorithm )BFS Implementation ) , Dijkstra Algorithm , as well as classes for weighted and unweighted graphs all explained . 

Also included code for island problem , where a map (matrix) is given with 0 representing water and 1 representing land , and we are required to find islands (groups of 1s together ) , precisely speaking we are required to find number of islands , size of each island and the size of the biggest island on the given map(matrix) . Could be useful to make a blob counting algorithm for a binary image , or , I just realised I could apply K mean clustering on the colours present in a coloured image , and then they will be like 0 , 1 , 2 ... in the island problem , and then I can run island finder for each value of colour range (like changing if A[i][j]==2 then 1 then 0 etc ) , then we can find the number of objects of different colours , say we have different colour balls on the floor (assuming they are not touching each other in the picture )(say red blur yellow) the we apply k means with k=4 then discard the floor part and count the 1st cluster's islands , 2nd cluster's islands ... and then we would have number of balls of each colour in the image , maybe something like this can be used to make a blob counter , just guessing didnt read anywhere .

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
 
 Function :
 int islandfinder(vector<vector<int> > &A)
 




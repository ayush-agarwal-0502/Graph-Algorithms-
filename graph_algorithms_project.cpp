/*
Project - Graph Algorithms

DFS (Iterative and Recursive)
BFS (Iterative and Recursive)
Grid Graph Pathfinder algorithm 
Dijkstra Algorithm 
Along with codes for classes of weighted and unweighted graphs , adding edges to them ,
printing them 

Name - Ayush Agarwal 
College - IIT BHU Varansi 
Email - ayush.agarwal.ece20@itbhu.ac.in 
Github - https://github.com/ayush-agarwal-0502
LinkedIn - https://www.linkedin.com/in/ayush-agarwal-261041215/

*/

// Importing the libraries 
#include<iostream>
#include <bits/stdc++.h>
using namespace std ;

///////////////////////////////////////////////////////////////////////////////////////////
// I tend to include my thought process during long codes too in long comments like these 
// feel free to read 
/////////////////////////////////////////////////////////////////////////////////////

// There are many ways to implement graphs in c++ as I have found 
// array of vectors 
// vector of vectors 
// map to vectors 
// vector of lists 
// 4th option seemed bad to me since list can only hold one data type so will give problem in making weighted graphs 
// while others can be used for making weighted graphs by replacing the 2nd vector by a vector of pairs 
// vector is always better than arrays so 1st option also down 
// map to vectors seems best since I can keep node names also instead of using 1 2 3 4 like vector of vectors 
// hence I will use map to vectors and map to vector of pair for graphs 
//////////////////////////////////////////////////////////////////////////////////////////////////
class unweighted_graph{
    
    // class for unweighted graph 
    
    public:
    // need bits/std library for these containers 
    // there are 3 ways of storing graphs in computers - 
    // adjacency matrix , adjacency list and edge list 
    // adj matrix is good for dense graphs 
    // adj list is good for sparse graphs 
    // here I have used adjacency list 
    map<int,vector<int>> adjl ;
    int N_nodes = adjl.size();
    // here I have taken names of nodes as integers 
    
    // class methods
    void addedge_directed(int a , int b );
    void addedge_undirected(int a , int b );
    void print_graph();
    void BFS_iterative(int a);
    void BFS_recursive(int a);
    void BFS_recursive_util(int a, queue<int>& q, map<int,bool>& visited);
    void DFS_iterative(int a);
    void DFS_recursive(int a);
    void DFS_recursive_util(int a, map<int,bool>& visited);

};
//////////////////////////////////////////////////////////////////////////////////////////////////
void unweighted_graph::addedge_directed(int a, int b){
     
    //Adds a directed edge to the graph .
    
    adjl[a].push_back(b);
    adjl[b].push_back(a);
    adjl[b].pop_back();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void unweighted_graph::addedge_undirected(int a, int b){
    
    //Adds an undirected edge to the graph .
    
    adjl[a].push_back(b);
    adjl[b].push_back(a);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void unweighted_graph::print_graph(){
    
    //Prints all the nodes of the graph along with its neighbours .
    
    for(auto it:adjl){
        cout<<"for node : ";
        cout<<(it.first)<<endl;
        cout<<"we have its neighbours : ";
        for(auto y:it.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void unweighted_graph::BFS_iterative(int a){
    
    // code for BFS implemented iteratively 
    
    // queue 
    queue<int> q;
    // bool visited[N_nodes] = {false}; would have worked had we had array instead of map 
    // visited map (not array since we have used map from int to vector for graph )
    map<int,bool> visited;
    // adding all elements to array and making visited false 
    for(auto it:adjl){
        visited[it.first] = false;
    }
    // pushing first node in 
    q.push(a);
    // IMP , logic behind BFS used here 
    while(!q.empty()){
        int b = q.front();
        if(!visited[b]){
            cout<<b<<" ";
        }
        q.pop();
        if(!visited[b]){
            visited[b]=true;
            for(auto iter:adjl[b]){
                if(!visited[iter]){
                    q.push(iter);

                }
            }
        }
        visited[b]=true;
        
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void unweighted_graph::BFS_recursive(int a){

    // parent of the recursive bfs , which makes the recursion ke global variables 
    // like queue and visited array 
    queue<int> q;
    map<int,bool> visited;
    for(auto it:adjl){
        visited[it.first] = false;
    }
    q.push(a);
    BFS_recursive_util(a,q,visited);

}
//////////////////////////////////////////////////////////////////////////////////////////////////
void unweighted_graph::BFS_recursive_util(int a, queue<int>& q, map<int,bool>& visited){
    // function to help the recurive bfs function 
    // base case 
    if(q.empty()){
        return;
    }
    // recursion case 
    int b = q.front();
    cout<<b<<" ";
    q.pop();
    visited[b] = true;
    for(auto it:adjl[b]){
        if(!visited[it]){
            q.push(it);
        }
    }
    BFS_recursive_util(a,q,visited);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void unweighted_graph::DFS_iterative(int a){

    // Iterative Code for DFS 

    stack<int> s;
    map<int,bool> visited;
    for(auto it:adjl){
        visited[it.first] = false;
    }
    s.push(a);
    while(!s.empty()){
        int b = s.top();
        s.pop();
        if(!visited[b]){
            cout<<b<<" ";
            visited[b]=true;
            
        }
        for(auto iter:adjl[b]){
                if(!visited[iter]){
                    s.push(iter);
                }
            }
    }
    return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void unweighted_graph::DFS_recursive(int a){

    // recursive code for DFS 

    map<int,bool> visited;
    for(auto it:adjl){
        visited[it.first]=false;
    }
    DFS_recursive_util(a,visited);
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void unweighted_graph::DFS_recursive_util(int a, map<int,bool>& visited){
    visited[a]=true;
    cout<<a<<" ";
    for(auto it:adjl[a]){
        if(!visited[it]){
            DFS_recursive_util(it,visited);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////
// Few notes about common problems and their approaches , plz ignore 
///////////////////////////////////////////////////////////////////////////////////////////
/* Connected Component problem - finding number of connected components 
(nodes which can be reached to each other , like island probably ) 
we can perform DFS/BFS(video used DFS) from one node , and mark all the reached nodes as part of a group
(using an array) and then using for loop we can start next group by doing DFS/BFS from next 
unvisited node */
/////////////////////////////////////////////////
/*Shortest path in unweighted graph - solve using BFS
For that we need to make an array to store the parents of the first time visited nodes too */
/* IsPath problem can be solved using BFS too , need to return bool */
/////////////////////////////////////////////////
/* Grid Graph Search problem - Of course we could convert it to adjacency list (since it is 
sparse graph) . But that would be tedious , so we often tend to directly operate on graph . 
Some imp techniques - 
Direction vectors - r[+1,-1,0,0] c[0,0,+1,-1] and then using for loop r+=r[i] c+=c[i]
to access the neighbours instead of manually writing r-1 , c+1 ... 
Multi Queues - making pairs to represent each node can be bit tedious , so instead of making pairs 
and using 1 queue of pairs for BFS , we can use normal coordinates and 2 int queues */
// Name - Ayush Agarwal 
//////////////////////////////////////////////////
class grid_graph{
    
    // class for solving grid graph problems 
    
    public:
    // storing the grid in a vector of vectors felt the best way 
    vector<vector<int>> A;
    
    // grid_graph(vector<vector<int>> a){
    //     A = a;
    // }
    // int N_rows = A.size();
    // int N_cols = A[0].size();
    ///////////////////////////////////////////////small bit of code from Stackexchange
    // still bit unsure why I needed to make function for number of rows and columns 
    // instead of direct 
    grid_graph(vector<vector<int>> a): A( a ){}

    int colCount() const
    {
        return A[0].size();
    }
    int rowCount() const
    {
        return A.size();
    }
    ////////////////////////////////////////////////////////////
    void pathfinder(int src_r,int src_c,int dest_r,int dest_c);
    void neighbour_adder(int r,int c,queue<int>& R,queue<int>& C,vector<vector<bool>>& visited);//bool visited[][N_cols]
};
//////////////////////////////////////////////////////////////////////////////////////////
void grid_graph::pathfinder(int src_r,int src_c,int dest_r,int dest_c){
    
    // pathfinder algorithm using BFS for grid graph 
    // prints reached for each path it discovers 
    // can be modified to save the path , or count the number of paths too 
    
    queue<int> R;
    queue<int> C;
    R.push(src_r);
    C.push(src_c);
    // bool visited[N_rows][N_cols]{};
    // vector<vector<bool>> visited;
    // for(int i=0; i<N_rows; i++){
    //     for(int j=0; j<N_cols; j++){
    //         visited[i][j]=false;
    //     }
    // }
    int N_rows = rowCount();
    int N_cols = colCount();
    int goal_counter = 0 ;
    ///////////////////////////////////from stackexchange 
    vector<vector<bool> > visited(N_rows,vector<bool>(N_cols, false));
    /////////////////////////////////
    // visited[src_r][src_c] = true;
    while(!R.empty()){
        if(R.front()==dest_r && C.front()==dest_c){
            cout<<"reached"<<endl;
            goal_counter++;
        }
        visited[R.front()][C.front()]=true;
        neighbour_adder(R.front(),C.front(),R,C,visited);
        R.pop();
        C.pop();
    }
    cout<<"Found "<<goal_counter<<" paths from src to dest "<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
void grid_graph::neighbour_adder(int r,int c,queue<int>& R,queue<int>& C,vector<vector<bool>>& visited){//bool visited[][N_cols]
    // assuming only up down left right motion possible 
    // this is an intresting way , to make direction vectors and then try out directions 
    int d1[4] = {0,0,+1,-1};
    int d2[4] = {+1,-1,0,0};
    // number of rows and columns in the grid 
    int N_rows = rowCount();
    int N_cols = colCount();
    // exploring each direction 
    for(int i=0; i<4; i++){
        
        int r_next = r + d1[i];
        int c_next = c + d2[i];
        // if goes out of grid then reject it 
        if(r_next<0 || c_next<0 || r_next>=N_rows || c_next>=N_cols){
            continue;
        }
        // if obstacle or already visited then also reject it 
        // I have taken 1 as obstacle 0 as not obstacle 
        if(A[r_next][c_next]==1 || visited[r_next][c_next]==true){
            continue;
        }
        // if problem free then add to the queues 
        R.push(r_next);
        C.push(c_next);
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////
// few more notes , plz ignore 
//////////////////////////////////////////////////////////////////////////////
/* Dijkstra algorithm is a greedy algorithm used for shortest path in non negative weighted
 graphs . we have lazy , eager , d ary heap and fibonacci heap versions of it . 
*/
/////////////////////////////////////////////
/*Topological sort , topsort done using dfs over all unvisited nodes and putting them in reverse 
in an array (which is the topsort output ) , can only be done over directed acyclic graph  DAG*/
// Name - Ayush Agarwal 
///////////////////////////////////////////////////////////////////////////////////////////////
class weighted_graph{
    public:
    
    // class for weighted graphs 
    
    // we could use vector of vectors but I prefer map implementation more 
    // as map gives freedom for name of node 
    // vector<vector<pair<int,int>>> adjl ;
    // weighted graph best implement as map of vectors of pairs 
    map<int,vector<pair<int,int>>> adjl ;
    // number of nodes in the graph 
    int N_nodes = adjl.size();
    
    // class methods 
    void addedge_undirected_weighted(int a, int b, int weight);
    void addedge_directed_weighted(int a, int b, int weight);
    void print_weighted_graph();
    void dijkstra(int src);
    
};
///////////////////////////////////////////////////////////////////////////////////////////////
void weighted_graph::addedge_undirected_weighted(int a, int b, int weight){
    
    // function to add undirected edge in weighted graph 
    
    adjl[a].push_back(make_pair(b,weight));
    adjl[b].push_back(make_pair(a,weight));
}
///////////////////////////////////////////////////////////////////////////////////////////////
void weighted_graph::addedge_directed_weighted(int a, int b, int weight){
    
    // function to add directed edge in weighted graph
    
    adjl[a].push_back(make_pair(b,weight));
}
//////////////////////////////////////////////////////////////////////////////////////////////
void weighted_graph::print_weighted_graph(){
    
    // funtion to print the weighted graph 
    
    for(auto it:adjl){
        cout<<"for node : ";
        cout<<(it.first)<<endl;
        cout<<"we have its neighbours and weights : ";
        for(auto y:it.second){
            cout<<y.first<<" "<<y.second<<"  ";
        }
        cout<<endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
void weighted_graph::dijkstra(int src){
    
    // code for dijkstra algorithm 
    
    // dist vector declared 
    // not vector but a map is better here since node names can be anything now 
    map<int,int> dist;
    for(auto it:adjl){
        dist[it.first] = INT_MAX;
    }
    
    // making min heap using priority queue 
    // which by default sorts by first element so gotta put weight first 
    // which is opposite of way it is stired in adjl so gotta be careful 
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    // setting for source 
    pq.push(make_pair(0,src));
    dist[src] = 0;
    // continue to look forward from the least dist node (which would be the top element of 
    // min heap ) , thats why dijkstra is a greedy algorithm 
    
    while(!pq.empty()){
        // extract least dist node from top of min heap 
        int prev = pq.top().second ;
        pq.pop();
        // look for all its neighbours and update and push to heap 
        for(auto it:adjl[prev]){
            int nextnode = it.first;
            int nextnodedist = it.second;
            if(dist[nextnode] > (dist[prev] + nextnodedist)){
                dist[nextnode] = (dist[prev] + nextnodedist);
                // this is eager dijkstra and not lazy dijkstra 
                // since reentering value for a key deletes its previous value 
                // which is also an advantage I got from using priority queue as minheap 
                pq.push(make_pair(dist[nextnode],nextnode));
            }
        }
    }
    
    // now print the distances stored in the distance array (map actually )
    for(auto iter:dist){
        cout<<"dist of "<<(iter.first)<<" from src is "<<(iter.second)<<endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
// Name - Ayush Agarwal 
int main(){
    // cout<<"hello world"<<endl;
    unweighted_graph g1;
    /////////////////////////////////////
    // g1.addedge_undirected(1,2);
    // g1.addedge_directed(2,3);
    // g1.print_graph();
    // print graph , directed and undirected edges functions are working properly 
    ////////////////////////////////////

    ////////////////////////////////////
    // graph taken from https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
    // g1.addedge_directed(0, 1);
    // g1.addedge_directed(0, 2);
    // g1.addedge_directed(1, 2);
    // g1.addedge_directed(2, 0);
    // g1.addedge_directed(2, 3);
    // g1.addedge_directed(3, 3);
    // g1.BFS_iterative(2);
    // gave output 2 0 3 1 which is correct hence iterative BFS is working properly 
    // g1.BFS_recursive(2);
    // gave output 2 0 3 1 which is correct hence recursive BFS is working correctly 
    ////////////////////////////////////
    // g1.addedge_directed(0, 1);
    // g1.addedge_directed(0, 2);
    // g1.addedge_directed(1, 2);
    // g1.addedge_directed(2, 0);
    // g1.addedge_directed(2, 3);
    // g1.addedge_directed(3, 3);
    // g1.DFS_iterative(0);
    // gave output 2 3 0 1 for 2 , 3 for 3 , 0 2 3 1 for 0 hence it is working 
    // g1.DFS_recursive(0);
    // gave output 2 0 1 3 for 2 , 3 for 3 , 0 1 2 3 for 0 hence it is working 
    ////////////////////////////////////
    grid_graph g2( {{ 0, 0, 0 },
                    { 0, 1, 0 },
                    { 0, 0, 0 } });
    g2.pathfinder(0,0,2,2);
    /////////////////////////////////////////////////////////////
    // graph figure available at 
    //https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/
    weighted_graph g3;
    g3.addedge_undirected_weighted(0, 1, 4);
    g3.addedge_undirected_weighted(0, 7, 8);
    g3.addedge_undirected_weighted(1, 2, 8);
    g3.addedge_undirected_weighted(1, 7, 11);
    g3.addedge_undirected_weighted(2, 3, 7);
    g3.addedge_undirected_weighted(2, 8, 2);
    g3.addedge_undirected_weighted(2, 5, 4);
    g3.addedge_undirected_weighted(3, 4, 9);
    g3.addedge_undirected_weighted(3, 5, 14);
    g3.addedge_undirected_weighted(4, 5, 10);
    g3.addedge_undirected_weighted(5, 6, 2);
    g3.addedge_undirected_weighted(6, 7, 1);
    g3.addedge_undirected_weighted(6, 8, 6);
    g3.addedge_undirected_weighted(7, 8, 7);
    g3.print_weighted_graph();
    g3.dijkstra(0);
    ///////////////////////////////////////////////////////////////////////////////////////
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////



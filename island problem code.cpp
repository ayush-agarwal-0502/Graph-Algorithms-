// Mini Project - Island Finder problem code 
// Name - Ayush Agarwal 
// IIT BHU ECE 

// land is 1 and water is 0 
// diagonal is acceptable for island 

// including the libraries
#include<vector>
#include<queue>
#include <iostream>
using namespace std;
// A is the matrix representing the world here
int islandfinder(vector<vector<int> > &A) {
    // making a visited array to mark the visited islands 
    vector<vector<int>> visited (A.size(),vector<int> (A[0].size(),0));
    // i is vertical j is horizontal 
    // making the direction vectors 
    vector<int> d1 = {1,-1,0,0,1,-1,1,-1};
    vector<int> d2 = {0,0,1,-1,1,-1,-1,1};
    // making queues for x and y 
    queue<int> qx ;
    queue<int> qy ;
    int ans = 0 ;
    int numberislands = 0;
    cout<<"The sizes of the island on this map are : "<<endl;
    // checking the whole matrix 
    for(int i=0; i<A.size(); i++){ 
        for(int j=0; j<A[0].size(); j++){
            // if unvisited island found 
            if(visited[i][j]!=1 && A[i][j]==1){
                qx.push(j);
                qy.push(i);
                // area for that group of islands 
                int regionarea = 1;
                visited[i][j]=1;
                // bfs for that unvisited island 
                while(!qx.empty()){
                    // taking the front element of queue 
                    int x = qx.front();
                    int y = qy.front();
                    qx.pop();
                    qy.pop();
                    // checking in all directions 
                    for(int k=0; k<8; k++){
                        int px = x + d1[k];
                        int py = y + d2[k];
                        // checking for water , boundary conditions , visited land parts 
                        if(px>=A[0].size() || py>=A.size() || px<0 || py<0 || A[py][px]==0 || visited[py][px]==1){
                            continue ;
                        }
                        else{
                            qx.push(px);
                            qy.push(py);
                            regionarea++;
                            visited[py][px] = 1;
                        }
                    }
                }
                // printing the single big island area 
                cout<<regionarea<<" ";
                // increasing island counter by one 
                numberislands++;
                // updating the max value of island area found 
                if(ans<regionarea){
                    ans = regionarea ;
                }
                
            }
        }
    }
    cout<<endl;
    cout<<"There are "<<numberislands<<" big islands on this map "<<endl;
    // returning the size of the biggest island 
    return ans;
}

int main()
{
    vector<vector<int>> v1 {{1, 0, 1}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}};
    cout<<"The map looks like : "<<endl;
    for(int i=0; i<v1.size(); i++){
        for(int j=0; j<v1[0].size(); j++){
            cout<<v1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int ans = islandfinder(v1);
    cout<<"And the size of the biggest connected island is : ";
    cout<<ans ;

    return 0;
}

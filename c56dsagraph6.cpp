#include <bits/stdc++.h>
using namespace std;

/*The game of Snake and Ladder.
You are at square 1 and have to reach square 100. You have complete control over the die and can get any number from 1-6.
For given ladders and snakes, find the minimum steps to reach.
Input:
2
3 90
56 76
3
99 10
30 20
20 5

First the number of input box and output box
First ladders and snakes.

Idea:
1. BFS!
2. Push 1 into the queue,
    For all possiblities in the dice:
        Check if the next position is ladder, snake or empty.
        Mark the square as visited and push into queue.
3. Stop the traversal, when you reached 100.
*/

void snakesAndLadders(){
    int ladders, snakes;
    cin>>ladders;
    map<int,int> lad; //start,end
    map<int,int> snak; //start,end
    for(int i=0;i<ladders;i++){
        int u,v;cin>>u>>v;
        lad[u]=v;
    }
    cin>>snakes;
    for(int i=0;i<snakes;i++){
        int u,v;cin>>u>>v;
        snak[u]=v;
    }
    int moves=0; //track no of moves
    queue<int> q; //queue is taken to take into account of further steps moved on ladders or snakes
    q.push(1);
    bool found=false; //check whether path exists
    vector<int> vis(101,0);
    vis[1]=true;
    while(!q.empty() and !found){
        int sz=q.size();
        while(sz--){
            int t=q.front(); //t refers to current box
            q.pop();
            for(int die=1;die<=6;die++){
                if(t+die==100)found=true;
                //for ladder's box
                if(t+die<=100 and lad[t+die] and !vis[lad[t+die]]){
                    vis[lad[t+die]]=true;
                    if(lad[t+die]==100){
                        found=true;
                    }
                    q.push(lad[t+die]);
                }
                //for snake's box
                else if(t+die<=100 and snak[t+die] and !vis[snak[t+die]]){
                    vis[snak[t+die]]=true;
                    if(snak[t+die]==100){
                        found=true;
                    }
                    q.push(snak[t+die]);
                }
                //for normal box, as if in map data type is int, default is 0, so !0=1, checks whether it doesn't contain any snake or ladder's entry point on the step.
                else if(t+die<=100 and !vis[t+die] and !snak[t+die] and !lad[t+die]){
                    vis[t+die]=true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }
    if(found){
        cout<<moves;
    } else{
        cout<<-1;
    }
}

/*Problem:
Given a 2-D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into  'X's in that surrounded region.
4 4
X X X X
X O O X
X X O X
X O X X
Idea:
1. Traverse the 'O' components arounf the edges of the grid and change it to '*'.
2. The remaining 'O' components will be surrounded regions that can be captured.
3. Change the '*' back to 'O'.
*/

void change(vector<vector<char>> &A, int x,int y){
    A[x][y]='*';
    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};
    for(int i=0;i<4;i++){
        int cx=x+dx[i];
        int cy=y+dy[i];
        if(cx>=0 and cx<A.size() and cy>=0 and cy<A[0].size() and A[cx][cy]=='O'){
            change(A,cx,cy);
        }
    }
}

void surroundedRegions(){
    int n,m;cin>>n>>m;
    vector<vector<char>> A(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 or i==n-1 or j==0 or j==m-1){
                if(A[i][j]=='O')
                    change(A,i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='O'){
                A[i][j]='X';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='*'){
                A[i][j]='O';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<A[i][j]<<" ";
        }cout<<endl;
    }
}

int main(){
    snakesAndLadders();
    surroundedRegions();
return 0;}
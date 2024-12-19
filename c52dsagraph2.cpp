#include <bits/stdc++.h>
using namespace std;

const int N=1e5+2;
//visited array
bool vis[N];
//Adjacency list, array of vectors
vector<int> adj[N];

void dfs(int node){
    //preorder
    vis[node] = 1;
    //inorder
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(vis[*it]);
        else{
            dfs(*it);
        }
    }
    //postorder
    cout<<node<<" ";
}

int main(){
    //Breadth first search
    for(int i=0;i<N;i++){
        vis[i]=0;
    }
    int n,m;
    
    cin>>n>>m;
    //Here n represents number of nodes, and m represents number of wedges.
    //x and y are the connections
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

//Breadth first search is implemented by queue.
    queue<int> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<endl;

        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++) {
            if(!vis[*it]) {
                vis[*it]=1;
                q.push(*it);
            }
        }
    }

/* Input: Remember to give wedges in ordered manner.
        7 7
        1 2
        1 3
        2 4
        2 5
        2 6
        2 7
        7 3
    */

//Deep First Search:
cin>>n>>m;

for(int i=0;i<=n;i++){
    vis[i]=false;
}

for(int i=0;i<m;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
dfs(1);


return 0;}
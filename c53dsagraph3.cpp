#include <bits/stdc++.h>
using namespace std;

/*Topological Order:
Ordering of the nodes in a directed graph where for each directed edge from node A to node B, node A appears before node B in the ordering.
Topological ordering is not unique.
Not every graph has a topological sort.
Directed cyclic graph have a topological sort.
Only directed acyclic graph(DAG) have a valid topologial sort.
Indegree: The number of inward directed edges on vertex in a directed graph.
Use : Indegree 0 put in topological sort output array.
*/

void topologicalSort(){
    int n,m; cin>>n>>m;
    int cnt=0;
    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); //u->root, v->branch
        indeg[v]++;
    }
    queue<int> pq;
    //first put all elements having indegree 0 in queue, top most elements, in tree.
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        cnt++;
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";
        //x --> v
        for(auto it : adj[x]){
            //subtracting indeg, as their root is gone
            indeg[it]--;
            //now if their indegree is 0, then they should also be filled in queue.
            if(indeg[it]==0){
                pq.push(it);
            }
        }
    }
/*Input:
4 3
0 1
1 2
2 3
*/
}

/*Cycle Detection in Undirected Graphs:
Keep on traversing the graph.
If you found an edge pointed to an already visited node (except the parent node), a cycle is found. This edge to that visited node is termed as Back edge.
*/

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visited,int parent){
    visited[src]=true;
    for(auto i:adj[src]){
        if(i!=parent){
            if(visited[i]){
                return true;
            }
            //recursively check whether the same el is visited once again...
            if(!visited[i] and isCycle(i,adj,visited,src)){
                return true;
            }
        }
    }
    return false;
}

void cycleDetectionUndirectedGraph(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle=false;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        //don;'t write conditions in 'if' in opposite order, as visited[i] changes
        if(!visited[i] and isCycle(i,adj,visited,-1)){
            cycle = true;
        }
    }

    if(cycle){
        cout<<"Cycle is present"<<endl;
    } else{
        cout<<"Cycle is not present"<<endl;
    }
/*Input:
4 3
0 1
1 2
2 0
Cycle is present

4 3
0 1
1 2
2 3
Cycle is not present
*/
}

bool isDirectedCycle(int src,vector<vector<int>> &adj,vector<bool> &visited, vector<int> &stack){
    stack[src]=true;
    if(!visited[src]){
        visited[src]=true;
        for(auto i: adj[src]){
            if(!visited[i] and isDirectedCycle(i,adj,visited,stack)){
                return true;
            }
            if(stack[i]){
                return true;
            }
        }
    }
    //makes stack as it is so that we can judge for next stack
    stack[src]=false;
    return false;
}

void cycleDetectionDirectedGraph(){
    /*
    1. Mark the current node as visited and also mark the index in recursion stack.
    2. Find all vertices which are not visited and are adjacent to the current node.
    3. If the adjacent vertices are already marked in the recursion stack, then a cycle is found.
    */
   int n,m;cin>>n>>m;
   vector<vector<int>> adj(n);
   for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v); //u as root and v as leaf
   }
   bool cycle = false;
   vector<int> stack(n,0);
   vector<bool> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i] and isDirectedCycle(i,adj,visited,stack)){
            cycle=true;
        }
    }

    if(cycle){
        cout<<"Cycle is present"<<endl;
    } else{
        cout<<"Cycle is not present"<<endl;
    }
/*Input:
4 3
0 1
1 2
2 1
Cycle is present

4 2
0 1
2 3
Cycle is not present
*/
}

int getComp(int idx,vector<bool> &vis,vector<vector<int>> &adj){
    if(vis[idx]){
        return 0;
    }
    vis[idx]=true;
    int ans=1;
    for(auto i:adj[idx]){
        if(!vis[i]){
            ans+=getComp(i,vis,adj);
        }
        vis[i]=true;
    }
    return ans;
}

void connectedComponents(){
/*
Connected Component: A connected component is a subgraph in which any two vertices are connected to each other by paths, 
and which is connected to no additional vertices in the supergraph.
Idea:
1. Visit the nodes in a depth-first fashion.
2. If the node is not visited, visit that node and its neighbour recursively.
Each time a unvisited node is found, a new component will be found.
Now, find the sizes of all connected graph.
*/
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<bool> vis(n);
    vector<int> components;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            components.push_back(getComp(i,vis,adj));
        }
    }
    for(auto i: components){
        cout<<i<<" ";
    }
    //If to determine number of ways we can choose two nodes so that they are not of same connected graph.
    // int ans=0;
    // for(auto i: components){
    //     ans+=i*(n-i);
    // }
    // cout<<ans/2;
    cout<<endl;

    /*Input:
    5 3
    0 1
    2 3
    0 4
    */
}

void color(int u,int curr,vector<int> &col, bool &bipart,vector<bool> &vis,vector<vector<int>> &adj){
    if((col[u]!=-1) and (col[u]!=curr)){
        //neither the color is not colored, nor it is in color to be painted, so it is not bipartite graph
        bipart=false;
        return;
    }
    col[u]=curr;
    if(vis[u]){
        return;
    }
    //now put it in visited array
    vis[u]=true;
    for(auto i: adj[u]){
        color(i,curr xor 1,col,bipart,vis,adj);
        //xor 1^1=0 and 0^1=1, therfore opposite of what is given for 0 and 1.
    }
}

void bipartiteGraph(){
/*(Childhood's multiple 'Match the Column' with two columns)
Bipartite Graph:
If any of the statement is true, it is bipartite graph.
Its vertices can be divided into two disjoint and indepenedent sets U and V such that every edge connects a vertex in U to one in V.
The graph does not conatin any odd-length cycles.
The graph is 2 colorable.

Traverse the graph.
If the current node is of red color, paint its neighbours as blue.
If you are able to color the graph successfully, then the graph is colored.
*/
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<bool> vis(n,false);
    //col->color
    vector<int> col(n,-1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool bipart=1;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            color(i,0,col,bipart,vis,adj);
        }
    }
    if(bipart){
        cout<<"Graph is bipartite"<<endl;
    } else {
        cout<<"Graph is not bipartite"<<endl;
    }
/*Input:
3 3
0 1
1 2
2 0
Not bipartite

4 4
0 1
1 2
2 3
3 0
Graph is bipartite.
*/
}

int main(){
    cout<<"Let's find topological sort"<<endl;
    topologicalSort();
    cout<<endl<<"Now, detect cycle in undirected graph"<<endl;
    cycleDetectionUndirectedGraph();
    cout<<"Now, detect cycle in directed graph"<<endl;  
    cycleDetectionDirectedGraph();
    //Now, let's assume a graph in 1->2->3, 1<-4, now previous undirected algo will show cycle, but actually it doesn't contain cycle, so in directed graph we would see the cycle by stack not by visited array.
    cout<<"Let's find connected components"<<endl;
    connectedComponents();
    cout<<"Let's check for Bipartite Graph"<<endl;
    bipartiteGraph();
return 0;}
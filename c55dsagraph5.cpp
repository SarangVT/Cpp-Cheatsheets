#include <bits/stdc++.h>
using namespace std;

/*
Dijkstra Algorithm:
Problem:
Given a weighted graph. Find the single source shortest path from a vertex u to all the vertices in the graph. If the node is unreachable, then print -1.
Note: The weights of the edges must be positive.
Idea:
1. Assign a distance values to all vertices in the input graph.
Intialize all distance values as INFINITE. Assign distance values as 0 for the source vertex.
2. While set is not empty.
    A. Pick a vertex u from set s that has minimum distance value.
    B. Update distance value of all adjacent vertices of u.
*/

void dijkstraAlgo(){
    const int inf=1e7;
    int n,m;cin>>n>>m;
    vector<int> dist(n+1,inf);
    vector<vector<pair<int,int>>> graph(n+1);
    //making adjacency list of the graph...
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w}); //Conditional as if graph is directional don't write it, and rest unchanged and dijkstra for directed graph is ready.
    }
    int source;cin>>source;
    //destination not required as we are giving minimum distances of all other nodes from source
    dist[source]=0;
    set<pair<int,int>> s;
    s.insert({0,source});
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        //it-> {node_value,weight}
        //x->{weight,node_value}
        for(auto it:graph[x.second]){
            //if the distance, of that from current node+original distance from source node is less than previous registered distance, then we would replace distance.
            if(dist[it.first] > dist[x.second] + it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]<inf){
            cout<<dist[i]<<" ";
        }else{//for not reachable as stated output -1.
            cout<<-1<<" ";
        }
    }
/*Input:
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1
*/
}

/*Bellman Ford Algorithm:
Problem:
From a source vertex v, find the shortest distance to all other nodes in the graph.
Idea:
1. Intially d[v]=0 and for all other elements d[]=infinity
2. In each pass, relax all the edges.
    i.e. for edge (a,b) having weight w,
    d[b]=min(d[b],d[a]+w)
3. Assuming no negative edge cycle, since there are n vertices, shortest path can only contain 'n-1' edges. 
   Therefore, we will get our answer in at most 'n-1' passes.
   
Advantages:
It will work for negative edges and negative cycles.
It can detect negative cycles as well, as if after n-1 passes answer is updating and minimizing, so it contains negative cycle.
*/

void bellmanFordAlgo(){
    const int INF=1E9;
    int n,m;cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int src;cin>>src;
    vector<int> dist(n,INF);
    dist[src]=0;
    //they stated as to connect n nodes, not more than n-1 edges are compulsarily needed.
    for(int iter=0;iter<n-1;iter++){
        bool didValueChanged = false; //just for fun
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(dist[v]>w+dist[u]){
                didValueChanged=true;
            }
            dist[v]= min(dist[v],w+dist[u]);
        }
    }
    for(auto i:dist){
        cout<<i<<" ";
    }cout<<endl;
/*Input:
5 8
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
0 2 4
4 3 -3
0 1 -1
0
*/
}

/*
Floyd Warshall Algorithm:
To find all pair shortest path.
i.e. for every u,v in graph G, find the shortest path from u to v.
*/

void floydWarshallAlgo(){
    const int INF=1e9;
    vector<vector<int>> graph = {
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };
    int n = graph.size();
    vector<vector<int>> dist = graph;
    //the (i,j) values in dist, corresponds to adjacency list, so this is distance from node no u to node no v with direction i->v
    //consider any two nodes,  (i,j) in adjacency list, then if we take any random node, (k), if we checked that if the path indirectly through that node, is smaller and that for n times of (n*n) then, we would get smallest distance.
    //also here the listed value in adjacency list in (i,j) th place is the weight of directed edge from i to j'th node, not from j to i, so as it is directed, for undirected check if its symmetrical part exists, for eg if (i,j)'th value=(j,i)'th value
    //so, treat it as one way path or vector in 3-d geometry and therefore, it possess direction, therefore (i,k)i->k + (k,j)k->j is checked with (i,j)i->j, analogical with triangle law of vector addition.
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    //just printing the ready nearest order
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==INF){
                cout<<"INF"<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    dijkstraAlgo();
    bellmanFordAlgo();
    floydWarshallAlgo();
return 0;}
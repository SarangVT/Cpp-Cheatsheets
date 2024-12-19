#include <bits/stdc++.h>
using namespace std;

/*Disjoint Set Union(Union Find)
Leading Element/Parent:
Element which can be regarded as the leader element for that set.
Let say, S = {1,2,3}
And 2 is the leader element, then
Parent[1]=Parent[2]=Parent[3]=2.
Basic Implementation of DSU:
All elements are parents of their, if Union(1,2) then 1 is parent of 2. 1<-2
then union(3,4) then thereafter Union(2,4) means union of (leader in which 2 is member of, leader in which 4 is member of)

void make(int v){
    parent[v]=v;
}
int find_set(int v){
    if(v==parent[v]){return v;}
    return find_set(parent[v]);
}
void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        parent[b]=a;
    }
}
//O(N) Time Complexity

Path Compression:
Connect all nodes in the path diretly to leader
int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
//O(Log(N)) Time Complexity

In the naive implementation Union(a,b) b gets attached to a
long chains can be formed, which leads to O(N) complexity.

Union by Size/Rank:
Final time compexity: O(alpha(n))
alpha: inverse Akkermann Function
O(1)

Union by Size:
void make(int v){
    parent[v]=v;
    size[v]=1;
}

void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(size[a]<size[b]){
        swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
        //see we are always maintaining, the chain a bigger.
    }
}

Solve the problems of long chains.
1. MST
2. Connected components in a graph
3. Cycle detection and many more
*/
const int N=1e5+6;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v){
    parent[v]=v;
    sz[v]=1;
}

int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sz[a] < sz[b]){
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];

    }
}

void cycleDetectionInUndirectedGraph(){
    for(int i=0;i<N;i++){
    make_set(i);
    }
    int n,m;cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        edges.push_back({u,v});
    }
    bool cycle=false;
    //we build a dsu from the edges, one point comes, when two elements belong to same set, then there is a cycle, otherwise never comes a need to convert edge into dsu, for acyclic 
    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y){
            cycle=true;
        }
        else{
            union_sets(u,v);
        }
    }
    if(cycle){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
/*
Input:
4 4
0 1
1 2
2 3
3 0
Cycle is present

4 2
0 1 
2 3
Cycle is not present
*/
}

/*Spanning Tree: Given an undirected and connected graph G(V,E), a spanning tree of the graph G is a tree that spans G (that is, it includes every vertex of G) and is a subgraph of G(every edge in the tree belongs to G).
The cost of the spanning tree is the sum of the weights of all the edges in the tree.
There can be many spinning trees.
Minimum Spanning Trees: Cost is minimum among the spinning trees. It also need not be unique.
To find MST: Kruskal's Algorithm:
1. Sort the edges in increasing order of their weights.
2. Iterate in the sorted edges.,
    If inclusion of i'th edge leads to a cycle, then skip this edge.
    else, include the edge in the MST.
Time Complexity: O(ElogV)
Space complexity: O(E+V)
*/
void kruskalAlgoMST(){
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m; cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    int cost=0;
    for(auto i:edges){
        int w=i[0];
        int u=i[1];
        int v=i[2];
        if(find_set(u)==find_set(v)){
            continue;
        }
        else{
            cout<<u<<" "<<v<<endl;
            cost+=w;
            union_sets(u,v);
        }
    }
    cout<<cost;
    /*Input:
    8 9
    1 2 5
    2 3 6
    4 3 2
    1 4 9
    3 5 5
    5 6 10
    6 7 7
    7 8 1
    8 5 1
    */
}

/*Prims Algorithm: 
Idea:
Select an arbitrary vertex s to start the tree form.
while(there are still non-tree vertices)
select the edge of minimum weight between a tree and nontree vertex.
Add the selected edge and vertex to the tree.
*/
vector<vector<int>> g[N];
vector<bool> vis(N);
int cost=0;
vector<int> dist(N),parent1(N);
const int INF=1e9;

void primsMST(int source,int n,int &cost){
    //intialize distance with infinity
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    set<vector<int>> s;
    dist[source]=0;
    //{weight,node_value}
    s.insert({0,source});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);

        vis[x[1]]=true;
        int u=x[1];
        //in first case it is not defined, no worry as it is not used.
        int v=parent1[x[1]];
        int w=x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost+=w;
        for(auto it:g[x[1]]){
            if(vis[it[0]]){
                continue;
            }
            //If our new distance is less, then insert it, and delete the old element, also update the parent of new element as from what node distance is measuring.
            if(dist[it[0]] > it[1]){
                s.erase({dist[it[0]],it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]],it[0]});
                parent1[it[0]] =x[1];
            }
        }
    }
}

void primsAlgo(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});

    }
    primsMST(0,n,cost);
    cout<<cost;
    /*Input:
    4 5
    0 1 10
    1 2 15
    0 2 5
    3 1 2
    3 2 40
    */
}

int main(){
/*Cycle Detection in a Undirected Graph using DSU:
*/
cycleDetectionInUndirectedGraph();
kruskalAlgoMST();
primsAlgo();

return 0;}
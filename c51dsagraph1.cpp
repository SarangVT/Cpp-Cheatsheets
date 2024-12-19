#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 1e5 + 2, MOD = 1e9 + 7;

/*Nodes: These are the states or vertex. For example users in whatsapp.
Edges: Links between states in a graph. For instance, connections between users.
Undirected: Two- way edges
Directed: One - way edges

Representation:
Adjacency Matrix: 2-D array, where a[i][j] = 1, if there is an edge from i to j else a[i][j] = 0.
So, if its symmetric part corresponds to undirected edges while unsymmetric part corresponds to directed edges.
Adjacency List: Array of lists, where each a[i] is a list of nodes xi, that are reachable from i.

Depth First Search: Parts:-
Pre-Order: First time when call comes on the node.
Inorder: When the call works inside the subtree (in DFS Tree) of that node.
Post-Order: After working on the subtree, call comes back on the node. After this, call won't come on the same node.
Implemented using stacks

Breadth First Search:
Implemented using queues.
Different properties of components of Graph:
Weighted nodes: Values are associated with nodes.
Weighted edges: Values are associated with edges.
*/

/*Dynamic Programming:
Optimal Substructure: We can write a recurrence relation, then a problem is said to have optimal substructure.
E.g. Fibonacci: f(n)=f(n-1)+f(n-2)
Overlapping Subproblem: If our subproblems repeat, then a problem is said to have overlapping subproblem.
E.g. For fibonacci f(n-1) is required for both f(n) and f(n+1), repeating or overlapping problem, so we using power of memory can save time.
Ways to handle Overlapping Subproblem:
1. Memoization(Top-Down): A lookup table is maintained and checked before computation of any state and updated after it. Recursion is involved.
2. Tabulation(Bottom-Up): Solution is built from base. It is an iterative process.

//Memoization(Recursive):
int fib[20]={-1};
int computeFib(int n){
    if(n==0 || n==1){
        return n;
    }
    if(fib[n]!=-1){
        return fib[n];
    }
    int res=fib(n-1)+fib(n-2);
    Memoization part fib[n]=res;
    return res;
}

//Tabulation (Iterative)
int computeFib(int n){
    int arr[n];
    arr[0]=0, arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<computeFib(n);
}

Key Points: Minimization and maximization problems are generally solved with dp where we want exhaustive solution, using P&C no greedy approach is working. (Sometimes with binary search on answer).
"Find the number of ways" is also a very popular type of DP Problems.
Where we can form recurrence relation or given in question can be solved using DP. (Sometimes with matrix exponentiation).
*/

/*Graph Terminologies:
Directed Graph: A graph with directed edges.
Undirected Graph: A graph with undirected edges.
Adjacent Vertices: Two vertices with a direct edge connecting them.
Degree of a vertex:
Indegree: Number of incoming edges to a node. Exmaple: Indegree of a vertex (4) is 1.
Outdegree: Number of outgoing edges from a node. Example: Outdegree of vertex (1) is 2.
Path between two vertices: All vertices which comes in the path of two given vertices is called their path.
Connected Graphs: Each node has path from every other node.
Disconnected Graph: Each node does not have path from every other node.
Connected Component: Each connected graph in a disconnected graph is called a connected component.
Cycles in a graph: Path from a vertex to the same vertex in a graph is known as cycle.
Cyclic Graph: Graph that contains cycle is called cyclic graph.
Acyclic Graph: Graph that does not contain cycle is called acyclic graph.
Tree is connected acyclic graph.

Properties of a Tree with n nodes:
1. Number of edges = n-1.
2. There are no cycles present.
3. Each node has path from every other vertex.

Directed Acyclic Graph[DAG]:
As the name suggests, its properties are:
1. It has directed edges.
2. It is acyclic, i.e. no cycles are present.

Complete Graph:
A graph in which each vertex is connected to every other vertex by a direct edge.
Number of edges in a complete graph: nC2 = n*(n-1)/2

Weighted Graph: A graph with weighted edges is called weighted graph.
*/

// declaring an array globally
vi adj[N];

signed main()
{
    // Representation in Adjacency Matrix:
    int n, m;
    cin >> n >> m;

    // Building 2-D square array of n+1 size intialized with 0.
    vvi adjm(n + 1, vi(n + 1, 0));
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    /*
    Input:
        7 7
        1 2
        1 3
        2 4
        2 5
        2 6
        2 7
        7 3
    */
    cout << "Adjacency Matrix is given by: " << endl;
    rep(i, 1, n + 1)
    {
        rep(j, 1, n + 1)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }

    // if(adjm[x][y]==1){
    //     cout<<"There is an edge between x and y."<<endl;
    // }else{cout<<"No edge is present between x and y."<<endl;}

    cin >> n >> m;
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    /*Input:
    7 7
    1 2
    1 3
    2 4
    2 5
    2 6
    2 7
    7 3
    */
    cout << "Adjacency List of the above graph is given by:" << endl;
    rep(i, 1, n + 1)
    {
        cout << i << "->";
        vector<int> :: iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}
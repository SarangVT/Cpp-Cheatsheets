/*Need of Segment Tree: 
If we have a normal array, then we want to find sum of a[i...j] elements, then, Time Complexity is O(N), and for updating any element , Time Complexity is O(1).
If we have a array with cumulative data, then Time Complexity of query is O(1), just a[j]-a[i-1], but Time Complexity for update is O(N).
But, for Segment Trees both Time Complexity of Update and Query is O(log(N)).
Here we make a tree, root has sum of all elements, then its left child has sum of its left half array and its right node has sum of its right half array., and so on, till there is just one element. So, total levels are log2(N).
For update we have to change one element in each level, log2(N).
As, we divide it and then fills it from bottom , that's why it is Divide and Conquer Method.

Actually this is a type of segment trees, just as this is based on sum, we can make on max and min, and other parameters also in the array's subarray.
*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>
const int N=1e5+2;
int tree[4*N];
int a[8]={5,3,2,4,1,8,6,10};
void build(int node, int st, int en){
    //node tracks the position in array where it is to be kept, if left order traversal of segment tree is done.
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    //2*(current pos=node) is the index of left child
    build(2*node,st,mid);
    //2*(current pos=node)+1 is the index of right child
    build(2*node+1, mid+1, en);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int st, int en, int l, int r){
    //Actually, the st and en are carrying info, sum of which values of original array, the segment tree's node is carrying.
    //Completely non-overlapping segment
    if(st> r || en < l){
        return 0;
    }
    //If it is a complete segment, means all values of that segments are required.
    //( l...st...en...r), then that particular node contains sum of all that range, just return it.
    if(l<=st && en<=r){
        return tree[node];
    }
    int mid=(st+en)/2;
    //In it by 2*node and 2*node+1, we are passing query to left and child right child along with the sum of original array's nodes, they are containing.
    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node+1, mid+1, en, l, r);
    return q1+q2;
}

int main(){
    int n=8;
    build(1,0,n-1);
    fl(i,1,15){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    int l, r;
    // cin>>l>>r;
    l=1, r=5;
    cout<<query(1,0,n-1,l,r);
return 0;}
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

#define vi vector<int>
#define pli pair<int,int>
#define vli vector<pli>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

void heapify(vi &a,int n,int i){
    int maxIdx=i;
    //if idx of parent is i in array(0-indexed), then idx of left child is 2*i+1, in array, if we are traversing it from left to right in binary tree, and 2*i+2 for right child
    int l=2*i+1;
    int r=2*i+2;
    //if left child is greater make it index comprimising max
    if(l<n && a[l]>a[maxIdx]){
        maxIdx=l;
    }
    //if right child is greater  than root or even left child, make it index comprimising max.
    if(r<n && a[r]>a[maxIdx]){
        maxIdx=r;
    }
    //swap the elements
    if(maxIdx!=i){
        swap(a[i],a[maxIdx]);
        //it will call it recursively, and heapify the affected subtree.
        heapify(a,n,maxIdx);
    }
}

void heapsort(vi &a){
    int n = a.size();
    //i=n/2-1 is the position of last non-leaf node in array from downside.
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    //move current root to end, and as we progress the largest numbers start accumulating at last.
    for(int i=n-1;i>=0;i--){
        //swap and store largest number at largest, thereafter don't touch it.
        swap(a[0],a[i]);
        //call heapify on affected rest heap, to get the next largest number.
        heapify(a,i,0);
    }
}

signed main(){
/*Heaps: Binary Tree based data structure
Not necessarily BST
MinHeap, MaxHeap
if this following properties are true for all nodes of binary tree
MaxHeap: Root>restof the elements present in its subtree
MinHeap: Root<restof the elements present in its subtree

To convert an array into a MaxHeap:
Insert elements and if, it is not suitable, swap them.
For popping elements, pop the root, and then make the leaf node, at any branch root, then just go on swapping to the one with max value in 2 childs.
*/
int n=6;
vi a(n);
rep(i,0,n){
cin>>a[i];
}
heapsort(a);
rep(i,0,n){
    cout<<a[i]<<" ";
}
return 0;}
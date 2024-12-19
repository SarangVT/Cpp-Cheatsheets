#include<bits/stdc++.h>
// #include <iostream>
// #include<vector>
// #include<map>
// #include<unordered_map>
// #include<climits>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define ff first
#define ss second
/*Print Vertical Order of a Binary Tree
Parent=i,Left son=2*i+1,right son=2*i+2
Computing horizontal distance from root
Starting from root
Recursively, call left and right with (HD-1) and (HD+1) as arguments.
Base Case: When current node=Null(return)
Push the value into vector corresponding to the horizontal distance (HD).
Output the map.
*/

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* node(int key){
        Node* node=new Node;
        node->key=key;
        node->left=node->right=NULL;
        return node;
    }

void getVerticalOrder(Node* root,int hdis,map<int,vector<int>> &m){
    if(root==NULL){
        return;
    }
    m[hdis].push_back(root->key);
    getVerticalOrder(root->left,hdis-1,m);
    getVerticalOrder(root->right,hdis+1,m);
}

//.........................................
int main(){

Node* root=node(10);
root->left=node(7);
root->right=node(4);
root->left->left=node(3);
root->left->right=node(11);
root->right->left=node(14);
root->right->right=node(6);

map<int,vector<int>> m;
int hdis=0;

getVerticalOrder(root,hdis,m);
map<int,vector<int>> :: iterator it;
for(it=m.begin();it!=m.end();it++){
    for(int i=0;i<(it->second).size();i++){
        cout<<(it->second)[i]<<" ";
    }
    cout<<endl;
}
/*
Calculate minimum sum of subarrays of length k in an array
Brute Force: Iterate from i=0 to i=n-k-1 in outer loop.
Starting from every j=i compute sum of k elements and then compare. T.C: O(N*k)
Optimal Solution(Sliding Window):
1. Compute sum of the first k elements(i=0 to k)
2. While increasing i, subtract a[i-1] and add a[i+k-1] in the previous sum, which will became current sum.
*/
int ars=8;
int wins=3;
int arr[]={-2,10,1,3,2,-1,4,5};
int sum=0;
int ans=INT_MAX;
for(int i=0;i<wins;i++){
    sum+=arr[i];
}
ans=min(sum,ans);
for(int i=0;i<ars;i++){
    sum-=arr[i];
    sum+=arr[i+wins];
    ans=min(sum,ans);
}
cout<<ans;

/*We have to output elements in decreasing frequency till we reach (k+1)th distinct elements.
1. Create a map.
2. While travelling, keep track of elements and when we find (k+1)th element, then break.
3. Output the element and frequency using map.
*/
int n,k;
cin>>n>>k;
vi a(n);
fl(i,0,n){
    cin>>a[i];
}

map<int,int> freq;
fl(i,0,n){
    int presentSize=freq.size();
    //if there is a new element and we have already got k distinct element, break, if its old number just add frequency.
    if(freq[a[i]]==0 && presentSize==k){
        break;
    }
    freq[a[i]]++;
}

vii ans1;
map<int,int> :: iterator ti;
for(ti=freq.begin();ti!=freq.end();ti++){
    if(ti->second!=0){
        pii p;
        p.ff=ti->ss;
        p.ss=ti->ff;
        ans1.push_back(p);
    }
}

sort(ans1.begin(),ans1.end(),greater<pii>());
vii :: iterator t;
for(t=ans1.begin();t!=ans1.end();t++){
    cout<<t->second<<" "<<t->first<<endl;
}

return 0;}
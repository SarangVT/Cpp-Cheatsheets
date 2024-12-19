#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>
//Kth One: Find the index of the Kth One in array.
//We descend the segment tree, we have the decision ability to either go to left child or right child.
const int N=1e5+2;
int a[N],tree [4*N] ;

void build(int node, int st, int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node]=tree[2*node]+tree[2*node+1];
}

void update(int node, int st, int en, int idx){
    if(st==en){
        if(a[st]==0){
            a[st]=1;
            tree[node]=1;
        }
        else{
            a[st]=0;
            tree[node]=0;
        }
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx);
    }
    else{
        update(2*node+1,mid+1,en,idx);
    }
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node,int st,int en,int k){
    if(st==en) return st;
    //If k is less than left child's sum, then Kth one is in left child, else in right child.
    //ones are numbered from 1, means first one is considered 0, that's why inequality. As, k<=tree[node]+1
    int mid=(st+en)/2;
    if(k<tree[2*node]){
        return query(2*node,st,mid,k);
    }
    else{
        return query(2*node+1,mid+1,en,k-tree[2*node]);
    }
}

int main(){
    int n, m;cin>>n>>m;
    fl(i,0,n){
        cin>>a[i];
    }
    build(1,0,n-1);
    fl(i,0,m){
        int type;cin>>type;
        if(type==1){
            int idx;cin>>idx;
            update(1,0,n-1,idx);
        }
        else{
            int k;cin>>k;
            int ans=query(1,0,n-1,k);
            cout<<ans<<endl;
        }
    }

return 0;}
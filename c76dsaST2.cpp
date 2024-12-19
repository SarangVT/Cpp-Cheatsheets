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

int tree[4*N], a[9]={6,8,-1,2,17,1,3,2,4};

void build(int node, int st, int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}

int query(int node,int st, int en, int l, int r){
    if(st>r || l>en){
        return INT_MIN;
    }
    if(l<=st && en<=r){
        return tree[node];
    }
    int mid=(st+en)/2;
    int q1=query(2*node,st,mid,l,r);
    int q2=query(2*node+1,mid+1,en,l,r);
    return max(q1,q2);
}

void update(int node, int st, int en, int idx, int val){
    if(st==en && st==idx){
        a[st]=val;
        tree[node]=val;
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }
    else{
        update(2*node+1,mid+1,en,idx,val);
    }
    tree[node]=max(tree[2*node],tree[2*node+1]);
    return;
}

int main(){
    int n=9;
    build(1,0,n-1);
    fl(i,1,18){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    int l, r;
    // cin>>l>>r;
    l=1, r=5;
    cout<<query(1,0,n-1,l,r)<<endl;

    //update an element
    int idx=5, val=18;
    update(1,0,n-1,idx,val);
    cout<<query(1,0,n-1,0,n-1);
return 0;}
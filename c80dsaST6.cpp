#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>

const int N=2e5+2;
int a[N], tree[4*N];

struct triplet{
    int l,r,idx;
};

bool compare(triplet t1, triplet t2){
    return t1.r < t2.r;
}

void build(int node, int st,int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    return;
}

int query(int node, int st, int en, int l,int r){
    if(st>r || l>en){
        return 0;
    }
    if(l<=st && en<=r){
        return tree[node];
    }
    int mid=(st+en)/2;
    return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);
}

void update(int node, int st, int en, int idx, int val){
    if(st==en){
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
    tree[node]=tree[2*node]+tree[2*node+1];
}

int main(){
    int n;cin>>n;
    triplet t1;
    t1.l = t1.r = -1;
    vector<triplet> t(n,t1);
    int x;
    fl(i,0,2*n){
        cin>>x;
        //storing the left and right occurence indices.
        if(t[x-1].l==-1){
            t[x-1].l=i;
        }
        else{
            t[x-1].r=i;
        }
        //Updating its value, or index in t vector.
        t[x-1].idx=x;
    }
    sort(t.begin(),t.end(),compare);
    vector<int> ans(n);
    //As, we have already sorted from right side, we have to just mark in the tree array the presence of the numbers in index of its left position, and by segment tree we would check which is inside, and now logic is for the nth interval, the next coming intervals in loop are already not possible(right side limitation), and for previous we are checking by segment tree for their l flags.
    //We want this type of arrangement a..b..c..d..d..c..b..a, we have arranged dcba what we are arranging and checking is abcd, how it is arranged.
    fl(i,0,n){
        ans[t[i].idx-1]=query(1,0,2*n-1,t[i].l,t[i].r);
        update(1,0,2*n-1,t[i].l,1);
    }
    fl(i,0,n){
        cout<<ans[i]<<" ";
    }
return 0;}
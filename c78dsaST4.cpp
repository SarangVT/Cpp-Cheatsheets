#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>

struct grp{
    long long pref, suff, sum, ans;
    grp(long long pref, long long suff, long long sum, long long ans){
        this->pref=pref;
        this->suff=suff;
        this->sum=sum;
        this->ans=ans;
    }
    grp(){

    }
};

const int N=1e5+2;
long long a[N];
grp tree[4*N];

void build(int node, int st, int en){
    if(st==en){
        if(a[st]<=0){
            tree[node]= grp(0,0,a[st],0);
        }
        else{
            tree[node]= grp(a[st],a[st],a[st],a[st]);
        }
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);

    long long sum= tree[2*node].sum+tree[2*node+1].sum;
    long long pref = max(tree[2*node].pref,  tree[2*node].sum+tree[2*node+1].pref);
    long long suff = max(tree[2*node+1].suff,tree[2*node+1].sum+tree[2*node].suff);
    long long ans = max(tree[2*node].suff+tree[2*node+1].pref, max(tree[2*node].ans,tree[2*node+1].ans));
    
    tree[node] = grp(pref,suff,sum,ans);
    return;
}

void update(int node, int st, int en, int idx, long long val){
    if(st==en){
        a[st]=val;
        if(a[st]<=0){
            tree[node]= grp(0,0,a[st],0);
        }
        else{
            tree[node]= grp(a[st],a[st],a[st],a[st]);
        }
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid) update(2*node, st, mid, idx, val);
    else update(2*node+1, mid+1, en, idx, val);    

    long long sum=tree[2*node].sum+tree[2*node+1].sum;
    long long pref = max(tree[2*node].pref,tree[2*node].sum+tree[2*node+1].pref);
    long long suff = max(tree[2*node+1].suff,tree[2*node+1].sum+tree[2*node].suff);
    long long ans = max(tree[2*node].suff+tree[2*node+1].pref,   max(tree[2*node].ans,tree[2*node+1].ans));
    tree[node] = grp(pref,suff,sum,ans);
}

int main(){
    int n, m;
    cin>>n>>m;
    fl(i,0,n){
        cin>>a[i];
    }
    build(1,0,n-1);
    cout<<tree[1].ans<<endl;
    fl(i,0,m){
        int idx, val;cin>>idx>>val;
        update(1,0,n-1,idx,val);
        cout<<tree[1].ans<<endl;
    }
return 0;}
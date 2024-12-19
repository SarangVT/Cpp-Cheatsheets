/*Problem:
Given an array a[] of size n.
Constraints: 1<=n<=10^5
You are given , queries of the form.
1 i v : change a[i] to v
2 x: Find the minimum index j such that a[j]>=x

After building the max segment tree, we can analyze our array to be sorted in increasing order.
Since our array is sorted, we can apply binary search.

Intilalize L0 = 0, Hi = n-1
Calculate mid = (0+4)/2=2
Query the segment tree ---> [lo, mid]

y<x:
We can surely say [lo, mid] is unfavourable.
Increase lo -> lo=mid+1
y>=x
We can surely say [mid+1,hi] is unfavourable.
decrease hi -> hi=mid-1
ans=min(ans,mid)


*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii vector<pair<int,int>>
const int N=1e5+2, MOD=1e9+7;

int a[N], tree[4*N];

void build(int node, int st, int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);

    tree[node]=max(tree[2*node], tree[2*node+1]);
    return;
}

int query(int node, int st, int en, int l, int r){
    if(st>r || en<l){
        return -MOD;
    }
    if(l<=st && en<=r){
        return tree[node];
    }
    int mid=(st+en)/2;
    return max(query(2*node, st , mid, l, r), query(2*node+1, mid+1, en, l, r));
}

void update(int node, int st, int en, int idx, int val){
    if(st==en){
        a[st]=val;
        tree[node]=val;
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node, st, mid, idx, val);
    }
    else{
        update(2*node+1, mid+1, en, idx, val);
    }
    tree[node]=max(tree[2*node],tree[2*node+1]);
    return;
}

int main(){
    int n, m;
    cin>>n>>m;
    fl(i,0,n){
        cin>>a[i];
    }
    build(1,0,n-1);
while(m--){
    int type;cin>>type;
    if(type==1){
        int idx, val;
        cin>>idx>>val;
        update(1,0,n-1,idx,val);
    }
    else if(type==2){
        int x;cin>>x;
        int lo=0, hi=n-1, ans=n;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            //The max element in left half is less than x.
            if(query(1,0,n-1,lo,mid)<x){
                lo=mid+1;
            }
            else{
                hi=mid-1;
                ans=min(ans,mid);
            }
        }
        if(ans==n){
            cout<<"-1"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}

return 0;}
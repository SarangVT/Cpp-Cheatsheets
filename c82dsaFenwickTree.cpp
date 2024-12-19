#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>

/*(Fenwick Tree) Binary Index Tree: 
Given an array, find the sum of array [L..R].

Updating the prefixArray  would need O(N) time.


Point Updates:
Point Updates are the opposite of this, we want to add the LSB to propagate the value up to the cells responsible for us.
Isolation of LSB:
Let a positive number be of the form: 'a 1 b' where 'a' contains random binary bits, and 'b' contains only 0s.
talking two complement of the number would be a'Ob+1, now b' would contain only 1s. So the number would be of the form a'1b.
Time Complexity of Query, Update O(Log(N))
*/
int n;
vi bit;
void update(int idx, int val){
    while(idx<=n){
        bit[idx]+=val;
        idx += idx&(-idx);
    }
    return;
}

int query(int idx){
    int ans=0;
    while(idx>0){
        ans+=bit[idx];
        idx-=idx&(-idx);
    }
    return ans;
}

int main(){
/*Given an array A and Q queries. There are two types of queries.
1. L R, print the sum of array[L...R]
2. idx val, Update A[idx] to val

For type 1 query, Sum[L..R]  = Query(R)-Query(L)
For type 2 query,
1. Push '-A[idx]' to all the nodes responsible for A[idx].
2. Push 'val' to all the values which are resposible for A[idx].

*/
cin>>n;
bit = vi(n+1);
vi a(n+1);
fl(i,1,n+1){
    cin>>a[i];
    update(i,a[i]);
}
int q;cin>>q;
while(q--){
    int c;cin>>c;
    if(c==1){
        int l, r;cin>>l>>r;
        int ans=query(r)-query(l-1);
        cout<<ans<<endl;
    }
    else if(c==2){
        int index, val;
        cin>>index>>val;
        update(index, -a[index]);
        a[index]=val;
        update(index,val);
    }
}
return 0;}
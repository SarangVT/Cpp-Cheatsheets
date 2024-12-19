#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii vector<pair<int,int>>

/*Range Updates:
You have an array containing n elements intially all 0. You need to do a number of queries on it.
First u queries L R val, means add 'val' to A[L],A[L+1],...A[R]
Next q queries are of the type, 
"Idx", Get the value stored at index idx

We update the segment Arr[L:] with 'val',
and the segment Arr[R+1:] with '-val' (negative val)\
The contribution of val, gets limited to Arr[L,R]

To get value stored at Arr[L]
Query(L): We take the sum from A[0], A[1], A[2],...A[L], i.e.query(L)
Explanation:
1. for i<j<L, update(i,j,val) net contribution in query(L) would be 0.
2. for i<L<j, update(i,j,val) net contribution in query(L) would be val.
3. for L<i<j, update(i,j,val) net contribution in query(L) would be 0.
*/
int query(int i, int bit[], int n){
    int ans=0;
    while(i>0){
        ans+=bit[i];
        i -= i&(-i);
    }
    return ans;
}

void update(int i, int inc, int bit[], int n){
    while(i<=n){
        bit[i]+=inc;
        i += i&(-i);
    }
}

int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    int bit[n+10] = {0};
    int u;cin>>u;
    while(u--){
        int l, r, inc;
        cin>>l>>r>>inc;
        l++;r++;
        update(l,inc,bit,n); //Updating by A[i]
        update(r+1,-inc,bit,n); //Updating by-A[i], which would cancel the effect.
    }
    int q;cin>>q;
    while(q--){
        int w;cin>>w;
        w++;
        cout<<query(w,bit,n)<<endl;
    }
}
/*
1
5 3
0 1 7
2 4 6
1 3 2
3
0   //7
3   //8
4   //6
*/

return 0;}
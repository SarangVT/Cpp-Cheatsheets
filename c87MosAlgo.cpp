/*General Structure:
Given an array of size n and q queries. Each query is a range query. In each query, we have to perform some operation and ouput answer of each query.

Generally it will take O(Q*N) time complexity,
Input all the queries simultaneously, Sort the queries in a particular fashion.
This step is known as offline processing of queries.


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
const int N=1e5+2;

struct Q{
    int idx, l, r;
};
Q q[N];

int rootN;
bool compare(Q q1, Q q2){
    if(q1.l/rootN == q2.l/rootN){
        return q1.r>q2.r;
    }
    return q1.l/rootN < q2.l/rootN;
}

int main(){
//We have to calculate sum of that range numbers.
//Time Complexity: O((n+Q)sqrt(n))
    int n;cin>>n;
    vi a(n);
    fl(i,0,n){
        cin>>a[i];
    }
    rootN=sqrtl(n);
    int queries;
    cin>>queries;
    fl(i,0,queries){
        int l, r;
        cin>>l>>r;
        q[i].l=l;
        q[i].r=r;
        q[i].idx=i;
    }
    sort(q,q+queries, compare);
    vi ans(queries);
    int curr_l(0), curr_r(-1), l, r;
    int curr_ans=0;
    fl(i,0,queries){
        l=q[i].l;
        r=q[i].r;
        l--;r--;
        while(curr_r<r){
            curr_r++;
            curr_ans+=a[curr_r];
        }
        while(curr_l > l){
            curr_l--;
            curr_ans+=a[curr_l];
        }
        while(curr_l<l){
            curr_ans-=a[curr_l];
            curr_l++;
        }
        while(curr_r>r){
            curr_ans-=a[curr_r];
            curr_r--;
        }
        ans[q[i].idx] = curr_ans;
    }

    fl(i,0,queries){
        cout<<ans[i]<<endl;
    }

return 0;}


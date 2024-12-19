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
int rootN;
struct Q{
    int idx, l, r;
};
Q q[N];

bool compare(Q q1, Q q2){
    if(q1.l/rootN == q2.l/rootN){
        return q1.r>q2.r;
    }
    return q1.l<q2.l;
}

int main(){
    int n;cin>>n;
    vi a(n);
    rootN=sqrtl(n);

    fl(i,0,n){
        cin>>a[i];
    }
    int quer;cin>>quer;
    fl(i,0,quer){
        int l, r;
        cin>>l>>r;
        q[i].l=l;
        q[i].r=r;
        q[i].idx=i;
    }
    
    sort(q,q+quer,compare);
    vi ans(quer);

    int curr_l=0, curr_r=-1, curr_ans=0;
    vi freq(10*N,0);

    fl(i,0,quer){
        int l=q[i].l, r=q[i].r;
        l--;r--;

        while(curr_r < r){
            curr_r++;
            freq[a[curr_r]]++;
            if(freq[a[curr_r]]==1) curr_ans++;
        }

        while(curr_l>l){
            curr_l--;
            freq[a[curr_l]]++;
            if(freq[a[curr_l]]==1) curr_ans++;
        }

        while(curr_l < l){
            if(freq[a[curr_l]]==1) curr_ans--;
            freq[a[curr_l]]--;
            curr_l++;
            if(freq[a[curr_l]]==0) curr_ans--;
        }

        while(curr_r > r){
            if(freq[a[curr_r]]==1) curr_ans--;
            freq[a[curr_r]]--;
            curr_r--;
            if(freq[a[curr_r]]==0) curr_ans--;
        }

        ans[q[i].idx]=curr_ans;
    }

    fl(i,0,quer){
        cout<<ans[i]<<endl;
    }

return 0;}
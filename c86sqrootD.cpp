#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii vector<pair<int,int>>

int main(){
    //Range Minimum Query: Shortest number in given query.
    int n;cin>>n;
    vi a(n);
    fl(i,0,n){
        cin>>a[i];        
    }
    int len=sqrt(len)+1;
    vi b(len);
    fl(i,0,len){
        b[i]=INT_MAX;
    }

    fl(i,0,n){
        b[i/len]=min(b[i/len],a[i]);
    }
    int q;cin>>q;
    while(q--){
        int ans=INT_MAX;
        int l, r;cin>>l>>r;
        l--;r--;
        for(int i=l;i<=r;){
            if(i%len==0 and i+len-1<=r){
                ans=min(ans,b[i/len]);
                i+=len;
            }
            else{
                ans=min(ans,a[i]);
                i++;
            }
        }
        cout<<ans<<endl;
    }

return 0;}
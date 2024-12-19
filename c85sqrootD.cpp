/*Queries of calculating sum in the range [l,r];
Brute Force: O(N)
Number of queries --> Q
Time taken by each query --> O(√N)
Time taken by Q queries ---> O(Q√N)
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
#define int long long

const int N = 1e5+2, MOD = 1e9+7;

signed main(){
    int n;  cin>>n;
    vi a(n);
    fl(i,0,n){
        cin>>a[i];
    }
    int len = sqrtl(n)+1;
    //1 more if number is not perfect square.
    vi b(len);
    //Calculation of square root length boxes sum.
    fl(i,0,n){
        //(i/len) for accessing its box.
        b[i/len] += a[i];
    }
    int q; cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        //we are going from 1-based indexing to 0-based indexing
        l--; r--;
        int sum=0;
        //*****see there is no increment in for loop*****
        for(int i=l;i<=r;){
            //we are traversing from l to r.
            //First, check if a box contains completely, as its 0-based indexing, we can directly check remainder==0, not 1 or other, and that r is inside range.
            if(i%len==0 && i+len-1 <= r){
                //(i/len) accesses box number.
                sum+=b[i/len];
                i+=len;
            }
            //calculating sum from partial boxes by trivial method.
            else{
                sum+=a[i];
                i++;
            }
        }
        cout<<sum<<endl;
    }
return 0;}
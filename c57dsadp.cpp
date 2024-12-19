#include <bits/stdc++.h>
using namespace std;
//Time Complexity(without DP): O(2^n)
//Time Complexity(witH DP): o(N)
//Memoization:
const int N=1e3+2;
int dp[N];

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]= fib(n-1)+fib(n-2);
    return dp[n];
}

int main(){
    for(int i=0;i<N;i++){
        dp[i]=-1;
    }
    int n=10;
    cout<<fib(n)<<endl;

    vector<int> d(n+1);
    d[0]=0;d[1]=0;d[2]=1;
    for(int i=3;i<=n;i++){
        d[i]=d[i-1]+d[i-2];
    }
    cout<<d[n]<<endl;
return 0;}
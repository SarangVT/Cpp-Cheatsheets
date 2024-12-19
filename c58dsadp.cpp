#include <bits/stdc++.h>
using namespace std;

const int N=1e3;
int minSqArr[N];


int minSquares(int n){
    if(n==0 || n==1 || n==2 || n==3){
        return n;
    }
    if(minSqArr[n]!=0) {return minSqArr[n];}
    int ans=INT_MAX;
    for(int i=1;i<=sqrt(n);i++){
        ans=min(ans,minSquares(n-pow(i,2))+1);
    }
    minSqArr[n]=ans;
    return ans;
}

int coinArr[N][N];

int coinWays(vector<int> &a,int n,int x){
    if(x==0) return 1;
    if(x<0)  return 0;
    if(n<=0) return 0;
    if(coinArr[n][x]!=-1) return coinArr[n][x];
    coinArr[n][x]=coinWays(a,n,x-a[n-1])+coinWays(a,n-1,x);
    return coinArr[n][x];
}

int main(){
    minSqArr[0]=0;minSqArr[1]=1;minSqArr[2]=2;minSqArr[3]=3;
    for(int i=4;i<N;i++){
        minSqArr[i]=0;
    }
/*Minimum number of squares whose sum equals to given number 'n'
    Example: 26=5^2+1^2, 4^2+3^2+1^2
    Recurrence relation: min(f(x-i*i)+1), so it follows optimal substructure
    Overlapping Subproblem is also followed,x requires x-1 and x-2, then, x-1 requires x-1-4 and x-4 also require x-4-1
*/
cout<<minSquares(11)<<endl;

    /*Problem: Given a set of coins and a value of 'V'. Find the number of ways, we can make change of 'V'.*/
    //Recursive Approach:
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            coinArr[i][j]=-1;
        }
    }
    int n=5;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        //cin>>a[i];
        a[i]=i+1;
    }
    cout<<coinWays(a,n,10)<<endl;

    /*Iterative Approach using denomination vector declared above*/
    int value=10;
    //Making the grid(Tabulation)...
    vector<vector<int>> coinWayArr(n+1,vector<int>(value+1,0));
    coinWayArr[0][0]=1;

    for(int i=1;i<n+1;i++){
        for(int j=0;j<value+1;j++){
            if(j-a[i-1]>=0){
                coinWayArr[i][j]+=coinWayArr[i][j-a[i-1]];
            }
            coinWayArr[i][j]+=coinWayArr[i-1][j];
        }
    }
    cout<<coinWayArr[n][value];
return 0;}
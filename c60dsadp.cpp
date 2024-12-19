#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define vii <vector<pair<int,int>>
const int N=1e5+2;
int dp[N];

const int N1=1e3+2;
int dp2 [N1][N1];

int lis(vi &a, int n){
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=1; //single element is also an lis
    //we are tracking for each number, how many numbers are smaller than the number
    fl(i,0,n){
        if(a[n]>a[i]){
            dp[n]=max(dp[n],1+lis(a,i));
        }
    }
    return dp[n];
}

int lcs(string &s1,string &s2,int n,int m){
    if(n==0 || m==0) return 0;
    if(dp2[n][m]!=-1){
        return dp2[n][m];
    }
    if(s1[n-1]==s2[m-1]) dp2[n][m]= 1+lcs(s1,s2,n-1,m-1);
    else dp2[n][m]= max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
    return dp2[n][m];
}

int main(){
/*You are given an array. Find the length of longest increasing subsequence.
Lis(i) depends on Lis(k), 0<k<i-1
Lis(i)=max(Lis(i),1+Lis(k))
Overlapping SubProblem Property

Approach-1:(Using Tabulation):

1. Make a dp array and intialize all the dp(i) ny 1.
Since, single element is also an Lis
2. For every i from left to right, iterate from j=0 to j=i-1
If(a[i]>a[j]) dp[i]=max(dp[i],1+dp[j])
After loop ends, Output [dp[n-1]]
Time Complexity: O(N^2)
*/
fl(i,0,N){
    dp[i]=-1;
}
int n=9;

vi a={10,22,9,33,21,50,52,60,80};
cout<<lis(a,n-1)<<endl;

/*Approach-2: Tabulation*/
vi dp1(n,1);
int ans=0;
fl(i,0,n){
    fl(j,0,i){
        if(a[i]>a[j])
            dp[i]=max(dp[i],1+dp[j]);
    }
    ans=max(ans,dp[i]);
}
cout<<ans<<endl;

/*Problem: Given two strings, S1 and S2. We need to output length of longest common subsequence.
Let, f(i,j) denotes the length of LCS of S1[0,1...,i-1] and S2 [0,1,...,j-1]
Two case arises:
1. S1[i-1] = S2[j-1]: f(i,j) = 1+f(i-1,j-1)
2. S1[i-1]!=S2[j-1] Further two possibilities
    a. Take S1[i-1] in LCS
    b. Take S2[j-1] in LCS
    f(i,j)=max(f(i-1,j),f(i,j-1));
    Even if we don't take both, by taking one further step back, we reach that condition
Optimal Substructure Property is followed.

*/
string s1="Sarang";
string s2="Thakare";

/*Approach-1:- Memoization: Recursive solution
Time Complexity: O(n*m)
*/
fl(i,0,N1){
    fl(j,0,N1){
        dp2[i][j]=-1;
    }
}
cout<<lcs(s1,s2,s1.size(),s2.size())<<endl;

/*Approach-2: Tabulation:*/
int m=s2.size();
n=s1.size();
vvi dp3(n+1,vi(m+1,-1));
fl(i,0,n+1){
    fl(j,0,m+1){
        if(i==0 || j==0){
            dp3[i][j]=0;
            continue;
        }
        //as here in grid, first character in row and column is null.
        if(s1[i-1]==s2[j-1]){
            dp3[i][j]=1+dp3[i-1][j-1];
        }
        else{
            dp3[i][j]=max(dp3[i-1][j],dp3[i][j-1]);
        }
    }
}

cout<<dp3[n][m]<<endl;

return 0;}
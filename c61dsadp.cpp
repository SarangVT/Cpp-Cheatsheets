#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define vii <vector<pair<int,int>>

const int N=1e2, MOD=1e9;
int a[N]={10,20,30,20,30};
int dp[N][N];

int mcm(int i,int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=MOD;
    fl(k,i,j){
       dp[i][j]=min(dp[i][j],mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j]); 
    }
    return dp[i][j];
}

int main(){
/*Matrix Chain Multiplication: We are given 'n' matrices, we have to multiply them in such a way that total number of operations are minimum.
Associative Property: A(BC)=(AB)C;
A: 1*2, B: 2*3, C: 3*4;
A(BC): 32 operations(2*3*4+2*4*1)
(AB)C: 18 operations(1*2*3+1*3*4)

Optimal Substructure: Recurrence Relation:
f(ABCD)=min(f(A|BCD),f(AB|CD),f(ABC|D))

Given an array, such that dimension of ith matrix is a[i-1]*a[i]
Dimension of matrix is multiplied from Mi to Mj, is a[i-1]*a[i].
f(M1,M2,...Mn)=min(f(M1,..Mk)+f(Mk+1..Mn)+a[0]*a[K]*a[N])
where 1<k<N-1
Overlapping Subproblem Property: Followed

Approach-1: Recursive solution and memoize it.
Approach-2: Tabulation(Bottom Up) For each gap=0 to gap=n-2, compute all submatrix multiplication and their results.
Build the answer using, for every k=i to k=j-1
dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j])
Time Complexity: O(N^3)
*/
//memset can be used to intialize values only by -1 or 0, and in ch array with any char.
memset(dp,-1,sizeof(dp));

int n=5;
cout<<mcm(1,n-1)<<endl;

/*Approach-2:*/
int dp1[N][N];
fl(i,1,n){
    dp[i][i]=0;
}
fl(l,2,n){
    fl(i,1,n-l+1){
        int j=i+l-1;
        dp1[i][j]=MOD;
        fl(k,i,j){
            dp1[i][j]=min(dp1[i][j],dp1[i][k]+dp1[k+1][j]+a[i-1]*a[k]*a[j]);
        }
    }
}
//see pointing 1 here means matrix with a[0]*a[1] size and n-1 as array has size n.
cout<<dp1[1][n-1]<<endl;
return 0;}
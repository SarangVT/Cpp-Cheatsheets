#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define vii <vector<pair<int,int>>

const int N=1e3+2, MOD=1e9+7;
int val[N]={60,100,150}, wt[N]={15,30,45};

int dp[N][N];

int knapsack(int n,int w){
    if(w<=0) return 0;
    if(n<=0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(wt[n-1]>w){ dp[n][w]=knapsack(n-1,w);}
    else{dp[n][w]=max(knapsack(n-1,w)  ,  knapsack(n-1,w-wt[n-1])+val[n-1]);}
    return dp[n][w];
}

int main(){
/*Given an array of items with their {weight,value and a knapsack with weight W}.
Find the maximum value of items that canbe stolen and put into knapsack.
Pick full or no item.
We cannot apply greedy as items are indivisible. 
Optimal Substructure Property: f(n,w)=max(f(n,w),f(n,w-weight[n])+value[n])
Overlapping Subproblem Property is also followed.

Appoach-1: Memoization:
1. Write the recursive solution.
2. Memoize it.

Approach-2: Tabulation
1. For every items, compute the answer for every weight from 0-W.
2. Use the recurrence of taking and not taking
dp[n][w]=max(dp[n-1][w],dp[n-1][w-wt[n]]+val[n])
Time Complexity: O(n*w)
*/

fl(i,0,N){
    fl(j,0,N){
        dp[i][j]=-1;
    }
}
//Number of items, weight of knapsack.
cout<<knapsack(3,50);
return 0;}
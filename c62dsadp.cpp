#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define vii <vector<pair<int,int>>
const int N=1e9;
/*Given an array of integers where each element represents the max number of steps that can be made forward from that element.
WAP to return the minimum number of jumps to reach the end of the array(starting from the first element). If an element is 0, they cannot move through that element.

DP States:
jumps [i] indicates the minimum number of jumps needed to reach arr[i] from arr[0]
we start from i=0, and we have to find jumps[n-1]
for calculating jumps[i], we run a nested loop 'j' from 0 to i-1
*/
int dp[100][100];
vi a={1,2,3,4};
int solve(int i,int j){
    if(i==j){
        return a[i];
    }
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    //Basic Idea: Two choices, a[i]+(as opponent would minimise your further score, after his play), maximise the total score.
    int l=a[i]+min(solve(i+2,j-1),solve(i+1,j-1));
    //If he chooses ith coin, remaining choices i+1,..j
    int r=a[j]+min(solve(i,j-2),solve(i+1,j-1));
    //If he chooses jth coin, remaining choices i,..j-1
    return dp[i][j]=max(l,r);
}

void countBinaryStringLengthN(int n){
    vector<int> fib(n);
    fib[0]=1;fib[1]=1;
    fl(i,2,n+2){
        fib[i]=fib[i-1]+fib[i-2];
    }
    cout<<fib[n+1];
}

int main(){
int n=11;
int arr[n]={1,3,5,8,9,2,6,7,6,8,9};
int jumps[n];
fl(i,1,n){jumps[i]=N;}
jumps[0]=0;
fl(i,1,n){
    fl(j,0,i){
        if(i<=(j+arr[j])){
            jumps[i]=min(jumps[i],jumps[j]+1);
        }
    }
}
cout<<jumps[n-1]<<endl;


/*Problem Description: Rahul and Neha are playing a coin game. They are given n coins with values x1, x2, …, xn (where ‘n’ is always even).
Players take alternate turns. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row.
The value of the coin is received by that player. Determine the maximum value that Rahul can win if he moves first. Both players play optimally(cleverly).
A[i....j]
1. We can choose A[i]
2. We can choose A[j]
In each case, our opponent will also have two choices. He will try to maximise his score and minimise ours.
Therefore, our subproblem, will reduce to
Choice 1 = a[i]+min(solve(i+2,j),solve(i+1,j-1))
Choice 2 = a[j]+min(solve(i,j-2),solve(i+1,j-1))
We would return maximum of this
*/
memset(dp,-1,sizeof(dp));
cout<<solve(0,3)<<endl;

/*Given a string consisting of lower case latin letters('a'-'z') and some '?'
Your task is to find number of subsequences 'abc' in all the strings '?' should be replaced by either of {'a','b','c'}
Declare 4 variables:
e-> Denoting count of all possible strings upto current element.
a-> denoting count of subsequences('a') in all the strings upto current element.
ab->denoting count of subsequence ('ab') in all the strings upto current element
abc-> denoting count of subsequences ('abc') in all the strings upto current element

*/
n=6;
string s="ac?b?c";

int e=1, a=0, ab=0, abc=0;

fl(i,0,n){
    if(s[i]=='a')a+=e;
    else if(s[i]=='b') ab+=a;
    else if(s[i]=='c') abc+=ab;
    else if(s[i]=='?'){
        abc=3*abc+ab;
        ab=3*ab+a;
        a=3*a+e;
    }
}

cout<<abc<<endl;

/*Count number of binary strings, without consecutive 1s.
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1's.
one[i]=zero[i-1]
zero[i]=one[i-1]+zero[i-1]
Therefore, zero[i]=zero[i-2]+zero[i-1]
one[i]+zero[i]=zero[i+1]
*/
countBinaryStringLengthN(5);
return 0;}
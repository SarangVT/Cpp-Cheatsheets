#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=b;i>a;i--)
#define vii <vector<pair<int,int>>

const int N=1e4;
int dp[N]={0};

int friendsPairingProblem(int n){
    if(dp[n]!=0){
        return dp[n];
    }
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    dp[n]=friendsPairingProblem(n-1)+(n-1)*friendsPairingProblem(n-2);
    return dp[n];
}

int dp1[205][205][205];

int LCS(string &s1, string &s2, string &s3, int i,int j, int k){
    
    if(i==0 or j==0 or k==0) return 0;
    if(dp1[i][j][k]!=-1) return dp1[i][j][k];
    if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]){
        return dp1[i][j][k] = 1+LCS(s1,s2,s3,i-1,j-1,k-1);
    }
    int l=LCS(s1,s2,s3,i-1,j,k);
    int r=LCS(s1,s2,s3,i,j-1,k);
    int p=LCS(s1,s2,s3,i,j,k-1);
    return dp1[i][j][k] = max({l,r,p});
}

int dp2[205][205];

int kLCS(string &s1, string &s2, int i, int j, int k){
    if(i==0 || j==0) return 0;
    if(dp2[i][j]!=-1) return dp2[i][j];
    int c1 = 0,c2=0,c3=0;
    if(s1[i-1]==s2[j-1]) c1= 1+kLCS(s1,s2,i-1,j-1,k);
    if(k>0) c2 = 1+kLCS(s1,s2,i-1,j-1,k-1);
    c3 = max(kLCS(s1,s2,i-1,j,k),kLCS(s1,s2,i,j-1,k));
    return dp2[i][j] = max({c1,c2,c3});
}

int main(){
    /*Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Let f(n) = ways n people can remain single or pair up.
For nth person there are two choices:
1. nth person remains single, f(n-1)
2. nth person pairs up, with any of the remaining n-1 persons. (n-1)*f(n-2)
f(n)=f(n-1)+(n-1)*f(n-2)
 */
cout<<friendsPairingProblem(3)<<endl;

/*Ugly Numbers: Numbers whose prime factors are 2,3 or 5.
The first 10 ugly members are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12.
By convention 1 is included.

Given n, find n'th ugly member.
Keep 3 pointers, think of it as merging 3 sorted lists.
Assume, you have Uk, the kth ugly number.
Then, U(k+1) must be Min(p1*2, p2*3, p3*5).
Where p1, p2, p3 will be already generated numbers.
*/
int n=10;
int c2(0),c3(0),c5(0);
vi d(n+1);
d[0]=1;
fl(i,1,n+1){
    d[i]=min({2*d[c2],3*d[c3],5*d[c5]});
    if(2*d[c2]==d[i]) c2++;
    if(3*d[c3]==d[i]) c3++;
    if(5*d[c5]==d[i]) c5++;
}

cout<<d[n-1]<<endl;

/*LCS: Longest Common Subsequence
Print the length of LCS of 3 strings.
|s|<200
Recurrence: 
*/
memset(dp1,-1,sizeof(dp1));
string s1= "Sarang";
string s2 = "Sarthi";
string s3 = "Samanya";
cout<<LCS(s1,s2,s3,s1.size(),s2.size(),s3.size())<<endl;

/*Problem:
Print the LCS of two sequences given that you are allowed to change atmost k elements in the first sequence to any value you wish to.
1<=N,M<=2000
1<=k<=5
1<=element in any subsequence = 10^9
*/
memset(dp2,-1,sizeof(dp2));
int k=3;
string s4="12345";
string s5="53142";
cout<<kLCS(s4,s5,5,5,1);

return 0;}
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>

/*Matrix Exponentiation is possible only for square matrix.
We have to calculate A^n.
Matrix Multiplication and Binary exponentiation.
Fibonacci Numbers:
Using recursion: O(2^n)
Using Dynamic Programming: O(n)
Using Matrix Exponentiation: O(log(n))
k^3*log(n), k is size of matrix, a constant.
See [[1,1],[1,0]]*[f(2),f(1)] = [f(3),f(2)]
Therefore, let A=[[1,1],[1,0]], then A^(n-2)*[f(2),f(1)]=[f(n),f(n-1)]
And, we can calcualate A^(n-2) in log(n-2)or log(n), as we can calculate power in log(n) times.
Then ,just simply multiply that matrix with [f(2),f(1)].
*/
vector<vi> multiply(vector<vi> &a,vector<vi> &b){
    int n=a.size();
    vector<vi> ans(n,vi(n,0));
    fl(i,0,n){
        fl(j,0,n){
            fl(k,0,n){
                ans[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}

vector<vi> matrixExponentiation(vector<vi> &a,int n){
    if(n==0){
        //If n==0, return Identity Matrix.
        int sz=a.size();
        vector<vi> ans(sz,vi(sz,0));
        fl(i,0,sz){
            ans[i][i]=1;
        }
        return ans;
    }
    if(n==1){
        return a;
    }
    vector<vi> temp = matrixExponentiation(a,n/2);
    vector<vi> ans=multiply(temp,temp);
    //If n is odd, then multiply additional a matrix.
    if(n&1){
        ans=multiply(ans,a);
        return ans;
    }
    return ans;
}

int fib(int n, int i, int j){
    vector<vi> a= {{1,1},{1,0}};
    vector<vi> b=matrixExponentiation(a,n-2);
    return b[0][0]*j+b[0][1]*i;
}

int main(){
    int n=47;
    cout<<fib(n,0,1);
    //Above 47 negative values come in output.
return 0;}
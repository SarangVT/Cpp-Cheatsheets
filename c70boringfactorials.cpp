#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>
/*Problem:
Neha gives you a prime number P and an integer N close to P, and asks you to find N! modulo P.
Constraints:
1<=P<=2*10^9
1<=N<=2*10^9
Abs(N-P)<=1000
N being very large, calculating N! is not possible.
If, n>=p, (n!)%p = 0, because (1..p..n)%p=0
If, n<p, Wilson's Theorem.
(p-1)!≡(-1)(mod p)
(p-1)!≡(p-1)(mod p)
But, now we have to remove (n+1)*(n+2)..*(p-1), as p>n
We will remove them by taking inverse modulo.
for(int i=n+1;i<p;i++){
    res=(res*modInverse(i,p))%p
}
We will use Fermat's Little Theorem to calculate the modulo inverse.
a^(p-2) ≡ a^(-1)(mod p)

Time Complexity:
Taking inverse of 'p-n' numbers in logarithmic time O((p-n)*Logn)

*/
int power(int x, int y, int p){
    int res=1;
    x=x%p;
    while(y>0){
        if(y&1){
            res=(res*x)%p;
        }
        y=y>>1;
        x=(x*x)%p;
    }
    return res;
}

int modInverse(int a,int p){
    return power(a,p-2,p);
}

int modFact(int n, int p){
    if(p<=n){
        return 0;
    }
    int res=(p-1);
    fl(i,n+1,p){
        res=(res*modInverse(i,p))%p;
    }
    return res;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n, p;cin>>n>>p;
        cout<<modFact(n,p)<<"\n";
    }

return 0;}












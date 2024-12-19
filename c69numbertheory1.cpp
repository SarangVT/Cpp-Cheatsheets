/*
Diophantine Equations: These are the polynomial equations for whivh integral solution exists.
E.g. : 3x+7y=1 or x^2 - y^2 = z^3
We generally deal with linear diophantine equations.
ax+by=c, a,b,c ∈ I
Solutions to these equations exist only if gcd(a,b) divides c.

Extended Euclid Algorithm:
Main Concept: Not to be forgotten ever.
*****GCD(a,b) has the property that ax+by = gcd(a,b)*****
 
Exended Euclid Algorithm:
ax+by=gcd(a,b)=gcd(b,a%b)
bx1+(a%b)y1 = gcd(b,a%b)
ax+by = bx1+(a-(a/b)*b)y1
ax+by = ay1+b(x1-(a/b)*y1)
Comparing the coefficients of a and b,
x = y1
y = x1 - (a/b)*y1
*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>

struct triplet{
    int x,y,gcd;
};

triplet extendedEuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet smallAns=extendedEuclid(b,a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x-(a/b)*smallAns.y;
    return ans;
}

triplet multiplicativeModuloInverse(int a, int m){
    if(m==0){
        //ax+0=a, x=1, gcd(a,0)=a
        triplet ans;
        ans.x=1;
        //Convenience y=0
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet smallAns=multiplicativeModuloInverse(m,a%m);
    triplet ans;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/m)*smallAns.y;
    ans.gcd=1;
    return ans;
}

/*Multiplicative Modulo Inverse:
(A*B)%m = 1
Here A and m are given and we have to find B, means what to be multiplied with A, when the remainder of that with m would come to be 1.
E.g. (12*B)%7=1, B=3

For Multiplicative Modulo Inverse to exist, A and m should be coprime, i.e. gcd(A,m)=1
(A*B)%m=1
(A*B-1)=-mQ
A*B+mQ=1   //apply extended euclid algo, ax+by=c, that's why A and m should be coprime
*/

/*Euler Totient Function:
Represented as Φ(n) ---> 1<=m<n such that, gcd(m,n)=1
in other words, number of numbers from 1 to n-1 which are coprime with n.

Φ(n) = n*(1-1/p1)*(1-1/p2)*(1-1/p3)*....(1-1/pk)
where p1, p2, p3, p4, ...pk are distinct prime factors of n.
Φ(A*B)=Φ(A)*Φ(B), if A and B are coprime.
We can write,
n = (p1^a) * (p2^b) * (p3^c) * ..(pk^∆)
Since,gcd((p1^a) , (p2^b)) = 1  //Prime Factors
Φ(n) = Φ((p1^a)) * Φ((p2^b)) * Φ((p3^c)) * ..Φ((pk^∆))

Analyze: Φ((p1^a))
Numbers divisible by p1 from 1 to p1^a
are p,2p,3p...
p^a=p+(x-1)*p
x = p^(a-1) //including 1 and excluding p^a
Therefore, Φ(p1^(a)) = p^a-p^(a-1) = p^a(1-1/p)
So, as n = (p1^a) * (p2^b) * (p3^c) * ..(pk^∆)
Thus proved that,
Φ(n) = n*(1-1/p1)*(1-1/p2)*(1-1/p3)*....(1-1/pk)

*/
int totient[100];

/*Binary Exponentiation:
(a+b)%m = (a%m) + (b%m)
(a*b)%m = (a%m) * (b%m)
(a-b)%m = (a%m) - (b%m) //Tricky as if it is negative, then add m, once only
(a/b)%m = (a%m) / (b^(-1))%m) //b-1m%m corresponds to multiplicative modulo inverse of b.
*/
const int MOD = 1e9+7;
int power(int a,int n){
    a%=MOD;
    int ans=1;
    while(n>0){
        if(n&1){
            ans = (ans*a)%MOD;
        }
        a=(a*a)%MOD;
        n = n>>1;
    }
    return ans;
}

int recPower(int a, int n){
    if(n==0){
        return 1;
    }
    int p = (recPower(a,n/2)%MOD);
    if(n&1){
        return (((p*p)%MOD)*a)%MOD;
    }
    else{
        return (p*p)%MOD;
    }
}

/*Fermat's Little Theorem: It states that if p is a prime number, then for any integer a, the number a^p-a is an integetr multiple of p.
a^p ≡ a(mod p)
This notation means if we take mod of a^p wrt to p, ultimately a will be remainder
Further if a is not divisible by p, a^(p-1) - 1 is an integral multiple of p.
a^(p-1) ≡ 1(mod p)
a^(p-2) ≡ a^(-1)(mod p)
Modulo inverse of a: a^(-1)
Evaluating (a/b)%m = ((a%m)*(b^(-1)%m))%m

nCr%p
I. If p>n,
    1. Pre-calculate factorials taking modulo p.
    2. nCr%p = (fac[n]*modInverse(fac[r])%p*modInverse(fac[n-r])%p)%p

Wilson's Theorem: A positive integer n>1 is a prime if and only if (n-1)!≡(-1)(mod n) or (n-1)!≡(n-1)(mod n)
In other words, (n-1)! is 1 less than a multiple of n.
100! = 101k-1, 100! = 101k+100, for some integer k.
Uses:
For e.g. We have to find (25!%29), we know 28!=29k-1
So, we need to find, [(-1)*inverse(28,29)*inverse(27,29)*inverse(26,29)]%29
*/

int main(){
    triplet ans = extendedEuclid(3,4);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
    triplet mMI = multiplicativeModuloInverse(17,3);
    cout<<mMI.x<<endl;
    //See here, -1 would come as output is correct, as a%m=(a+m)%m


//We would first intiate with a[i]=i, as in totient expression, n comes, then, if its prime, then a[i]-i, as except the value itself all values are coprime with n,
//then once found any prime iterate to all its multiples and multiply them by [1-1/p], as there is constraint of 1/p=0 in int, do it by first multiplying i-1, then divinding by i, as here i=prime number's value.
    int N=100;
    fl(i,0,N){
        totient[i]=i;
    }
    fl(i,2,N){
        if(totient[i]==i){
            for(int j=2*i;j<N;j+=i){
                totient[j]*=i-1;
                totient[j]/=i;
            }
            totient[i]=i-1;
        }
    }

    fl(i,2,11){
        cout<<totient[i]<<" ";
    }cout<<endl;

    cout<<power(1234567,5)<<endl;

    int a = 12345678;
    a%=MOD;
    cout<<recPower(a,10);

return 0;}
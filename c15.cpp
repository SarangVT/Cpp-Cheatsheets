#include <iostream>
using namespace std;

void primeSieve(int n){
    int prime[n]={0};

    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for(int j=2*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
//......................................................
void primeFactors(int n){
    //spf=simplest prime factor
    //just assigning its own value(for prime numbers permanently)
    int spf[5000]={0};
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }
    //Assigning prime factors
    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=2*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
//printing prime factors
    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
    cout<<endl;
}
//.............................................

int divisible(int n,int a,int b){
    int c1=n/a;//this gives number of multiples of a till n.
    int c2=n/b;
    int c3=n/(a+b);
    //set theory(union).
    return c1+c2-c3;
}

int gcd(int a,int b){
    //if we subtract two numbers their gcd doesn't change, as common factors common, and subtract remaining.
    //method-2 remainder
    //42,24: 42%24=18; 24%18=6; 18%6=0; therefore 6 is gcd.
    while(b!=0){
        int rem = a%b;
        a=b;
        b=rem;
    }
    return a;
}

int main(){
    primeSieve(50);
    primeFactors(4620);
    cout<<divisible(40,5,7)<<endl;
    cout<<gcd(45,55);
}
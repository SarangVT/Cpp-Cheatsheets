#include <iostream>
using namespace std;

int sumofn(int n){
    if(n==1){
        return 1;
    }
    int sum = n+sumofn(n-1);
    return sum;
}

int nrp(int n,int power){
    if(power==1){
        return n;
    }
    int product=n*nrp(n,power-1);
    return product;
}

int facto(int n){
    if(n==1 || n==0){
        return 1;
    }
    int fact = n*facto(n-1);
    return fact;
}

void fibo(int i,int j,int n){
    if(n==0){
        return;
    }
    cout<<i<<" ";
    int b=j;
    j=i+j;
    i=b;
    fibo(i,j,n-1);
}

int main(){
    cout<<sumofn(5)<<endl;
    cout<<nrp(5,4)<<endl;
    cout<<facto(7)<<endl;
    fibo(2,3,6);
    
return 0;}
#include <iostream>
using namespace std;
void ppnb(int a, int b){
    if(b>=a && a>=2){
        for(int i=a;i<=b;i++){
            for(int j=2;j<=i;j++){
                if(j==i){
                    cout<<i<<"  ";
                }
                if(i%j==0){
                    break;
                }
            }
        }
    }
    cout<<endl;
}

void fib(int n){
    for(int i=0,j=1,count=1;count<=n;count++){
        cout<<i<<" ";
        int a=i;
        i=j;
        j=a+j;
                            }
    cout<<endl;
            }

int facto(int n){
    int ans=1;
    if(n==0 || n==1){
        return 1;
    }
if(n>1){
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}
}       

int ncr(int n,int r){
    return (facto(n)/(facto(n-r)*facto(r)));
}

void pascal_triangle(int line){
    for(int i=0;i<line;i++){
        for(int j=0;j<=i;j++){
            cout<<ncr(i,j)<<" ";
        }
        cout<<endl;
    }
}

void invertp(int line){
    for(int i=1;i<=line;i++){
        for(int j=1;j<=1+line-i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void oaz(int line){
    for(int i=1;i<=line;i++){
        for(int j=1;j<=i;j++){
            if((i+j)%2==0){
                cout<<1;
            } else{
                cout<<0;
            }
        } cout<<endl;
    }
}

void rhombus(int line){
    for(int i=1;i<=line;i++){
        for(int j=1;j<=line-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=line;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void palindromicp(int line){
    for(int i=1;i<=line;i++){
        for(int j=1;j<=line-i;j++){
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        for(int j=2;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void star(int size){
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=(2*i-1);j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=size;i>=1;i--){
        for(int j=1;j<=size-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=(2*i-1);j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void zigzag(){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=9;j++){
            if((i+j)%4==0 || i==2 && j==4){
                cout<<"*";
            } else{cout<<" ";}
        } cout<<endl;
    }
}

int main(){
    ppnb(2,15);
    fib(8);
    cout<<facto(5)<<endl;
    pascal_triangle(6);
    invertp(7);
    oaz(5);
    rhombus(5);
    palindromicp(5);
    star(6);
    zigzag();
return 0;}
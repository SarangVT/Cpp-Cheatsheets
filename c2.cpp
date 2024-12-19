#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;

    if(a>b){
        if(a>c){
            cout<<"A is largest"<<endl;
        } else{
            cout<<"C is largest"<<endl;
        }
    } else if(b>c){
        cout<<"B is largest"<<endl;
    }else{
        cout<<"C is largest"<<endl;
    }


for(int i=0;i<30;i++){
    if(i%2==0){
        continue;
    }
    cout<<"Its an odd number"<<endl;
}
int n;
cin>>n;
int di;
for(di=2;di<n;di++){
    if(n%di==0){
        cout<<"Non-prime";
        break;
    }
}
if(di==n){
    cout<<"Prime";
}
int num;
cin>>num;
int m;
for(int i=2;i<n;i++){
    for(int m=2;m<=i;m++){
        if(i%m==0){
            continue;
        }
    }
if(m==i){
    cout<<i<<",";
}
}
int n1,n2;
char button;
cin>>button;
switch(button){
    case 'a':
    cout<<"Hello"<<endl;
    break;
    case 'b':
    cout<<"Namaste";
    break;
    case 'c':
    cout<<"Namaskar"<<endl;
    break;
    default:
    cout<<"Learning in progress"<<endl;

}

return 0;
}

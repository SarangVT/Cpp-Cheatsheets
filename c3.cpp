#include<iostream>
using namespace std;
int main(){

for(int i=0;i<5;i++){
for(int j=0;j<4;j++){
cout<<"*";
}
cout<<endl;
}

for(int i=0;i<5;i++){
for(int j=0;j<4;j++){
if(j==0 || j==3 || i==0 || i==4){
cout<<"*";}
else{cout<<" ";}
} cout<<endl;
}

for(int i=1;i<=5;i++){
for(int j=1;j<=6-i;j++){
cout<<"*";
}cout<<endl;
}

for(int i=1;i<=5;i++){
for(int j=1;j<=5-i;j++){
cout<<" ";
}
for(int j=6-i;j<=5;j++){
cout<<"*";
}
cout<<endl;
}
return 0;}
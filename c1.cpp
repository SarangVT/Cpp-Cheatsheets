#include<iostream>
using namespace std;
int main(){
    int a;
    a=12;
    cout<<"size of int "<<sizeof(a)<<endl;

    float b;
    cout<<"size of float "<<sizeof(b)<<endl;

    char c;
    cout<<"size of char "<<sizeof(c)<<endl;

    bool d;
    cout<<"size of boolean "<<sizeof(d)<<endl;

    short int si;
    long int li;

    cout<<"size of shortint "<<sizeof(si)<<endl;
    cout<<"size of longint "<<sizeof(li)<<endl;

    int amount1;
    cin>>amount1;
    int amount2;
    cin>>amount2;

    int sum = amount1+amount2;
    cout<<sum<<endl;

    int sav;
    cin>>sav;

    if(sav>100){
        if(sav>90){
        cout<<"Cadbury"<<endl;
        }else{
            cout<<"5Star"<<endl;
        }
    } else if(sav>50){
        cout<<"Perk"<<endl;
    } else{
        cout<<"Toffee"<<endl;
    }
    return 0;
}
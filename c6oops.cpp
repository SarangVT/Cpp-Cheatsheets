#include <iostream>
using namespace std;

class student{
//remember of semicolon after class
//by default data members are private,wherever you write public, data members thereafter becomes public.
//if you have to access private data members, then you may use a function.
    int marks;
    public:
    string name;
    int age;
    bool isPass;

    student(string s, int a,bool x){
        name = s;
        age = a;
        isPass = x;
    }//parametrized constructor
    student(){
        cout<<"Constructor is called"<<endl;
    }//default constructor, is made by default even if not made.

    //another copy constructor is also there by default
    //this & refers to the address of that object.
    student(student &a){
        cout<<"Copy Constructor is called"<<endl;
        name = a.name;
        age= a.age;
        isPass = a.isPass;
    }
//when default copy constructor is called, then it makes shallow copy, which copied data, but not the pointer address.
//when we make our manualised copy constructor, it maked deep copy and it copies both data and pointer address.

    ~student(){
        cout<<"Destructor is called"<<endl;
            }


    void printInfo(){
        cout<<"Name: ";
        cout<<name<<endl;
        cout<<"Age: ";
        cout<<age<<endl;
        cout<<"isPass: "<<isPass<<endl;
    }

    void accessprivateInfo(int m){
        marks = m;   
    }
    void printpInfo(){
        cout<<marks<<endl;
    }

//Operator overloading

    bool operator == (student &a){
        if(name==a.name && age==a.age && a.isPass==isPass){
            return true;
        } else{return false;}
    }
};

int main(){
    student a;
    a.name = "Sarang";
    a.age = 17;
    a.isPass = 1;
    a.accessprivateInfo(100);
    a.printpInfo();
    student arr[1];
    arr[1].name = "Alex";
    arr[1].age = 17;
    arr[1].isPass = 1;

    arr[1].printInfo();

    student b("Tyson",13,1);
    b.printInfo();

    student c = a;
    cout<<&a<<endl;
    cout<<&c<<endl;

    if(c==a){
        cout<<"Same"<<endl;
    } else{cout<<"Not Same"<<endl;}



    //see destructor is called number of times, the total number of datatypes.
return 0;}
#include <iostream>
using namespace std;

class A{
    int rooms;
    public:
    void hello(){
        cout<<"hello"<<endl;
    }
};
class B{public:
    void hi(){
        cout<<"hi"<<endl;
}
};

class C: public A, public B{
    public:
    
    };
class D: private A{
    public:
    int labs;
};
//here D would inherit all the public and protected data members and member functions of the class A, but it would go in private part of D, and would not be available for further classes to inherit.

int main(){
/*Inheritance: We can inherit attributes and methods from one class to another.
Derived Class(child): the class that inherits from another class
Base Class: the class being inherited from
Types of Inheritance:
Single, Multiple, Multi-level, Hybrid, Hierarchial
public,protected,private are attributes

Single: A->B
Multiple: A,B->C
Multi-level: A->B->C
Hybrid: Mix of above

*/
C c;
    c.hello();
    c.hi();


return 0;}
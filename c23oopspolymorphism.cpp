#include <iostream>
using namespace std;

/*Types of polymorphism(poly-many, morphism-form):
Compile Time: Function overloading(Many functions with same name but, diff attributes), Operator overloading(Eg add sign for complex number)
Run Time: Virtual functions
*/

class college{
//function overloading
public:
void fun(){
    cout<<"I am a function with no arguments"<<endl;
}
void fun(int x){
    cout<<"Arguments are int"<<endl;
}
void fun(double x){
    cout<<"Arguments are double."<<endl;
}
void fun(int x, int y){
    cout<<"Arguments are two integers."<<endl;
}
};

//Operator overloading.......................

class Complex{
    private:
    int real,img;
    public:
    Complex(int r=0, int i=0){
        real=r;
        img=i;  
    }
   
    Complex operator + (Complex const &obj){
        //syntax: (Class_name) (operator) ((Class_name const &object_name))
        //this function is always called when complex's class any object is operated by +.
        Complex res; //may also write res(real,img), or if you have not given default values to constructor then there is need to write default constructor.
        res.img = img + obj.img;
        res.real = real + obj.real;
        return res;
    }
    void display(){
        cout<<real<<"+"<<img<<"i"<<endl;
    }
};

class base{
    public:
    void print(){
        cout<<"Print"<<endl;
    }
    virtual void display(){
        cout<<"Display"<<endl;
    }
    virtual void safe(){
        cout<<"Safe"<<endl;
    }
};

class derived: public base{
    public:
    void print(){
        cout<<"Printing in derived"<<endl;
    }
    void display(){
        cout<<"Displaying in derived"<<endl;
    }
};

int main(){
    college x;
    x.fun();
    x.fun(4);

    Complex c1(12,7), c2(19,5), c3(1,100);
    Complex c4 = c1+c2+c3;
    c4.display();

    base *baseptr;
    derived d;
    baseptr = &d;

    baseptr -> print();
    // here it will show base class function until and unless, you use virtual keyword.
    baseptr -> display();
    //virtual doesn't means function doesn't mean to be executed, it means don't run if there is some same function in class deriving something from base.
    baseptr -> safe();
    //........................?
    //To do run-time polymorphism in 3 steps.
return 0;} 

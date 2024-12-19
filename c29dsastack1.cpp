#include <iostream>
using namespace std;
/*Stack: LIFO(Last In first Out)
Stores a list of items in which an item can be added to or removed from the list only at one end.
Operations: 
push(x): adds an element at the top
pop(): removes an element from the top
top(): returns the element at the top
empty(): tells whether our stack is empty or not.
*/
#define n 100

class stack{
    int *arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }

    void push(int x){
        if(top==n-1){
            cout<<"Stack overflowed"<<endl;
        }
        top++;
        arr[top]=x;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack is already empty"<<endl;
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"Stack is already empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        return top==-1;
    }
};

int main(){
    //implementation of stacks using arrays.
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    cout<<s.Top()<<endl;
    cout<<s.empty()<<endl;
return 0;}
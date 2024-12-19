#include <iostream>
#include <stack>
using namespace std;
//Implementation of queue using 2 stacks

class queue{
    //here to push, Time Complexity: O(1)
    //to pop, Time Complexity: O(N), in worst case
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval=s2.top();
        s2.pop();
        return topval;
    }

    bool empty(){
        if(s1.empty() and s2.empty()){
            return true;
        } return false;
    }
};

//Implementation of stacks using 1 stack and callstack
class que{
    public:
    stack<int> s;
    void push(int val){
        s.push(val);
    }

    int pop(){
        if(s.empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        int x=s.top();
        s.pop();
        if(s.empty()){
            return x;
        }
        int item=pop();
        s.push(x);
        return item;
    }

    bool empty(){
        if(s.empty()){
            return true;
        } return false;
    }

};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

    que w;
    w.push(1);
    w.push(2);
    w.push(3);
    cout<<w.pop()<<endl;
    cout<<w.pop();

return 0;}
#include<iostream>
#include<queue>
using namespace std;
/*Implementing stacks using queue
Method 1: Making push costly.
Method 2: Making pop costly.
*/

//Remember we are making LIFO using 2 FIFO's
class Stackpushcostly{
    public:
    int N;
    queue<int> q1;
    queue<int> q2;
    Stackpushcostly(){
        N=0;
    }
    void push(int val){
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }

    void pop(){
        q1.pop();
        N--;
    }

    int top(){
        return q1.front();
    }

    int size(){
        return N;
    }
};

class Stackpopcostly{
    public:
    int N;
    queue<int> q1;
    queue<int> q2;
    Stackpopcostly(){
        N=0;
    }

    void push(int val){
        q1.push(val);
        N++;
        return;
    }

    void pop(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        while(q1.size()!=1){
        q2.push(q1.front());
        q1.pop();
        }
        q1.pop();
        N--;
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }

    int top(){
        if(q1.empty()){
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q2.push(q1.front());
        q1.pop();
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        return ans;
    }

    int size(){
        return N;
    }
};

int main(){
Stackpushcostly s;
s.push(1);s.push(2);s.push(3);
cout<<s.top()<<endl;
s.pop();s.pop();
cout<<s.size()<<endl;

Stackpopcostly q;
q.push(1);q.push(2);q.push(3);
cout<<q.top()<<endl;
q.pop();q.pop();q.pop();
cout<<q.size();


return 0;}
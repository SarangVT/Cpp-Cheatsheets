#include <iostream>
using namespace std;
/*Queue: Stores a list of items in which an item can be inserted at one end and removed from the other end only 
Works on FIFO principle, First In and First Out.
Operations: enqueue(): to add an element
dequeue(): to delete an element
peek(): returns front element
empty(): tells whether queue is empty.

Array Implementation: 
two pointers, front and back intialised with -1. 
cons: we have fixed predetermined array size, either wastage of space or we may get insufficient storage, if array is filled.
*/
#define n 20

class queue{
    int* arr;
    int front;
    int back;

    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }

    void push(int x){
        if(back==n-1){
            cout<<"Stack is overflowed."<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(front==-1 || front>back){
            cout<<"No elements to pop"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            cout<<" No elements in queue"<<endl;
            return -1;
        } return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    q.push(1);q.push(2);q.push(3);

    cout<<q.peek()<<endl;
    q.pop();q.pop();q.pop();q.pop();
    cout<<q.empty();
return 0;}
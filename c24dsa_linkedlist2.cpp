#include <iostream>
using namespace std;
//detection and removal of cycle in ll, based on floyd's algorithm or hare and tortoise algorithm
class node{
    public:
    int data;
    node* next;
    node(int val){
    data=val;
    next=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n= new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return;
}

void makeCycle(node* head, int pos){
    node* temp=head;
    node* startNode;

    int count=1;
    while(temp->next!=NULL){
        //assigning startNode on pos to form node
       if(count==pos){
        startNode=temp;
        }
        temp=temp->next;
        count++;
    }

    //joining the cycle
    temp->next=startNode;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

bool detectCycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        //if it contains cycle, then definitely it will return true, else if it doesn't then as fast reaches the end, the loop should terminate.
        //fast->next!=NULL, as then it's fast->next->next is not defined.
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;
    //assuming ll provided contains cycle
    do{
        slow=slow->next;
        fast=fast->next->next;
    } while(slow!=fast);
    //first reaching to common place
    //then placing one pointer to head, here fast
    fast=head;

    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    //reaching the node where cycle starts
    //then breaking cycle by pointing slow, to NULL.
    slow->next=NULL;
return;}

int main(){
    node* ll=new node(1);
    insertAtTail(ll,2);
    insertAtTail(ll,3);
    insertAtTail(ll,4);
    insertAtTail(ll,5);
    cout<<detectCycle(ll)<<endl;
    makeCycle(ll,3);
    cout<<detectCycle(ll)<<endl;
    removeCycle(ll);
    cout<<detectCycle(ll)<<endl;
    display(ll);
return 0;}
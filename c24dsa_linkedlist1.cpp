#include "bits/stdc++.h"
using namespace std;
/*Difference and limitations in arrays:
Contiguous memory, fixed size, insertion costly.

Node: Data, Next(Points to linked node)
Head stores the data of its starting point of linked list, to traverse the ll.
Last node has null in its next pointer
*/

class node{
    public:
    int data;
    node* next;

//constructor
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);

//Corner case, when ll is empty: 
    if(head==NULL){
        head=n;
        return;
    }

    node* temp = head;
//here in pointer to show one property of a pointer -> is used instead of .
    while(temp->next!=NULL){
        //then making temp to be that node's next means the other node's address.
        temp = temp->next;
    }
    //making null to replace by new node's address
    temp->next=n;
    //here NULL in node is by default in property.
return;
}

void display(node* head){
    //we may not define temp and directly use head, as now we are taking it by value and not &head, by address.
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next; 
    }
    cout<<endl;
}

void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

bool search(node* head, int key){

    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* head){
    node* todelete = head;
    head=head->next;
    delete todelete;
}

void deletion(node* head, int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
return;}

//iterative method to reverse a linked list
node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }

    return prevptr;
}

//recursive way to reverse a linkedlist
node* reverserec(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead = reverserec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
//Time Complexity: O(N), as we are traversing it only one time.

//to reverse k nodes in a ll, at a time, eg 1 2 3 4-> 2 1 4 3
node* reversek(node* head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    //reversing first k nodes, in iterative manner..count=0,1 two times here.
    while(currptr!=NULL && count<k){
        //nextptr is intialised here, as else it may be not defined.
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    //recursive approach to reverse other nodes than the 2.
    if(nextptr!=NULL){
    //assigning original head, now the second member to reversed ll's head.
    head->next=reversek(nextptr,k);
    }
    //returns head of the reversed ll.
    return prevptr;
//Time Complexity: O(N)
}

int main(){
    node* head=NULL;
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtTail(head,3);
    insertAtTail(head,4);
    deletion(head,3);
    display(head);
    cout<<search(head,2)<<endl;
    cout<<search(head,6)<<endl;
    node* newhead = reverse(head);
    display(newhead);
    node* rv=reverserec(newhead);
    display(rv);
    int k=2;
    node* reverseknodes = reversek(rv,k);
    display(reverseknodes);
return 0;}
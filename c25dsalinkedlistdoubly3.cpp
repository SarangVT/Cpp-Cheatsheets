#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*prev;
    node*next=NULL;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
    head->prev=n;
    }
    head=n;
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n = new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    return;

}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }cout<<"NULL"<<endl;
    return;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}

void deletion(node* &head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    if(temp==NULL){
        return;
    }
    if(temp->next==NULL){
        temp->prev->next=temp->next;
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
return;
}

int main(){
    node* ll= NULL;
    insertAtTail(ll,1);
    insertAtTail(ll,2);
    insertAtTail(ll,3);
    insertAtTail(ll,4);
    insertAtTail(ll,5);
    insertAtHead(ll,100);
    display(ll);
    deletion(ll,2);
    deletion(ll,1);
    display(ll);
    deletion(ll,2);
    display(ll);
return 0;}
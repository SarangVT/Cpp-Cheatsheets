#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node*n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
    return;
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    return;
}

void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

bool search(node* &head,int val){
    node*temp=head;
    do{
        if(temp->data==val){
            return true;
        }
        temp=temp->next;
    }while(temp!=head);
    return false;
}

void deleteAtHead(node* &head){
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* todelete=head;
    temp->next=head->next;
    head=head->next;
    delete todelete;
}

void deletion(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node*temp=head;
    int count=1;
   while(count!=pos-1){
    temp=temp->next;
    count++;
   }
    node*todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

int main(){
node* ll = NULL;
//don't write new node(val) here as it would not form a circular ll, and the functions wouldn't work in desired manner.
insertAtTail(ll,1);
insertAtTail(ll,2);
insertAtTail(ll,3);
insertAtTail(ll,4);
insertAtTail(ll,5);
cout<<search(ll,4)<<endl;
cout<<search(ll,7)<<endl;
display(ll);
deletion(ll,1);
deletion(ll,3);
deletion(ll,3);
display(ll);
return 0;}
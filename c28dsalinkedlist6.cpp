#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
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

//Time Complexity=O(N).
void evenAfterOdd(node* &head){
    node* odd=head;
    node*even=head->next;
    node* evenStart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenStart;
    //just to point if odd is last, then even second last from odd to null.
    if(odd->next==NULL){
        even->next=NULL;
    }
}

int main(){
    node* head=new node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    evenAfterOdd(head);
    display(head);
return 0;}
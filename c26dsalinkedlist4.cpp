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

void insertAtTail(node* &head, int val){
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
    return;
}

int length(node* head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}

void appendknodes(node* &head, int k){
    node* newTail;
    node* newHead;
    node* oldTail;

    node* temp=head;
    for(int i=1;i<length(head)-k;i++){
        temp=temp->next;
    }
    newTail=temp;
    newHead=temp->next;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    oldTail=temp;
    newTail->next=NULL;
    oldTail->next=head;
    head=newHead;
    return;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }cout<<endl;
    return;
}

void intersect(node* &head1,node* &head2,int pos){
    //attaching ll 1's pos with head2's tail.
    node* temp1=head1;
    while(--pos){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int intersection(node* &head1,node* &head2){
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node*ptr1; //longer ll
    node*ptr2; //shorter ll
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while(d!=0){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

//merging 2 sorted ll in iterative manner
node* merge(node* &head1,node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node*p3=dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<=p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;  
    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
    }
    while(p2!=NULL){
    p3->next=p2;
    p2=p2->next;
    }
    node* head=dummyNode->next;
    delete dummyNode;
    return head;
}

//recursive way to merge 2 sorted linked list
node* mergeRecursive(node* &head1, node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    
    node* result;
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
}

int main(){
node* head=new node(1);
insertAtTail(head,2);
insertAtTail(head,3);
insertAtTail(head,4);
insertAtTail(head,5);
display(head); 
//appending k nodes from last to first of a ll
appendknodes(head,2);
display(head);

//finding intersection point's data at ll, if two linkded list are connected in a specific way(intersect function)
node* head1=new node(1);
insertAtTail(head1,2);
insertAtTail(head1,3);
insertAtTail(head1,4);
insertAtTail(head1,5);
node* head2=new node(1);
insertAtTail(head2,2);
intersect(head1,head2,3);
cout<<intersection(head1,head2)<<endl;
//Time Complexity: O(N), N is length of larger ll.

//Merging 2 sorted linked list
node* m1=new node(1);
insertAtTail(m1,3);
insertAtTail(m1,24);
insertAtTail(m1,30);

node* m2=new node(2);
insertAtTail(m2,3);
insertAtTail(m2,13);
insertAtTail(m2,23);
display(merge(m1,m2));

node* r1=new node(1);
insertAtTail(r1,3);
insertAtTail(r1,24);
insertAtTail(r1,30);

node* r2=new node(2);
insertAtTail(r2,3);
insertAtTail(r2,13);
insertAtTail(r2,23);
display(mergeRecursive(r1,r2));

return 0;}
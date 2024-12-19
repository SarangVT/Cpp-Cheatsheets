#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

/*T.C: O(N)
Zigzag traversal means if we traverse in one level, left to right, then traverse in next level, right to left.
*/
void zigzagtraversal(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*> curr;
    stack<Node*> next;

    bool leftToRight=true;
    curr.push(root);
    while(!curr.empty()){
        Node* temp=curr.top();
        curr.pop();

        if(temp){
            cout<<temp->data<<" ";
        
        if(leftToRight){
            if(temp->left){
                next.push(temp->left);
            }
            if(temp->right){
                next.push(temp->right);
            }
        }
        else{
            if(temp->right){
                next.push(temp->right);
            }
            if(temp->left){
                next.push(temp->left);
            }
        }
    }
        
        if(curr.empty()){
            leftToRight=!leftToRight;
            swap(curr,next);
        }
    }
}

/*Identical Binary Trees: Structurally identical and equal value for each nodes.
*/
bool isIdentical(Node* r1,Node* r2){
    if(r1==NULL && r2==NULL){
        return true;
    }
    else if(r1==NULL || r2==NULL){
        return false;
    }
    else{bool cond1=r1->data==r2->data;
        bool cond2 = isIdentical(r1->left,r2->left)&&isIdentical(r1->right,r2->right);
        return cond1&&cond2;
    } 
    return false;
}

struct Info{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};


/*Return the size of the largest BST in a binary tree.*/

Info largestBSTinBT(Node* root){
/*for each node store the following info:
1. min in subtree
2. max in subtree
3. subtree size
4. size of largest BST
5. isBST
*/
//Recursively, traverse in a bottom-up manner and find out the size of largest BST.
if(root==NULL){
    return {0,INT_MIN,INT_MAX,0,true};
}
if(root->left==NULL && root->right==NULL){
    return {1,root->data,root->data,1,true};
}
Info left=largestBSTinBT(root->left);
Info right = largestBSTinBT(root->right);
Info curr;
curr.size=(1+left.size+right.size);
if(left.isBST && right.isBST &&left.max<right.min && right.min>root->data){
    curr.min=min(left.min,min(right.min,root->data));
    curr.max=max(right.max,max(left.max,root->data));
    curr.ans=curr.size;
    curr.isBST =true;
    return curr;
}
curr.ans=max(left.ans,right.ans);
curr.isBST=false;
return curr;
}

void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void calcPointers(Node* root,Node** first,Node** mid,Node** last,Node** prev){
    if(root==NULL){
        return;
    }
    calcPointers(root->left,first,mid,last,prev);
    //property is violating
    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *first=*prev;
            *mid=root;
        } else{
            *last=root;
        }
    }
    *prev=root;
    calcPointers(root->right,first,mid,last,prev);
}

/*Restore BST: 2 nodes of a BST are swapped. Our task is to restore(correct) the BST.
Strategy: Inorder of a BST is sorted.
Case-I: Swapped elements are NOT adjacent to each other.
Case-II: Swapped elements are adjacent to each other.
Maintain 3 pointers- {1,8,3,4,5,6,7,2} here 8,3,2
first: previous node to where 1st number<prev number
mid: number where 1st number<prev
last: Case-I: 2nd node where number<prev
Case-II: NULL;
Case-I:swap(first,last)
Case-II: swap(first,mid)
*/
void restoreBST(Node* root){
    Node* first,*mid,*last,*prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;
    calcPointers(root,&first,&mid,&last,&prev);
    //Case-I:
    if(first && last){
        swap(&(first->data),&(last->data));
    }
    //Case-II:
    else if(first && mid){
        swap(&(first->data),&(mid->data));
    }
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
Node* n = new Node(1);
n->left=new Node(2);
n->right=new Node(3);
n->left->left=new Node(4);
n->left->right=new Node(5);

Node* root = new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
root->right->left=new Node(6);
zigzagtraversal(n);
cout<<endl;
cout<<isIdentical(n,root)<<endl;
cout<<largestBSTinBT(root).ans<<endl;
Node* w = new Node(6);
w->left = new Node(9);
w->left->left = new Node(1);
w->left->right = new Node(4);
w->right = new Node(3);
w->right->right = new Node(13);
inorder(w);
cout<<endl;
restoreBST(w);
inorder(w);
return 0;}
#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    Node* left;
    Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
/*Binary Search Trees:
In it all the nodes in left subtree is lesser than the root node, and all nodes in right subtree is greater than root, left subtree and right subtree must be a binary search tree, and there should be no duplicate nodes.
*/
//Building a Binary Search Tree using array.

Node* insertBST(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        //val>root->data
        root->right=insertBST(root->right,val);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
/*
Normal Binary Tree, time complexity is O(N), but in BST, O(log(N))
Ist level, let say n nodes,
IInd Level, n/2 nodes, then n/4, then n/8.
n/2^k=1, k number of levels we have to go, that much operation,k=logN, therefore O(logN) is time complexity.
*/

Node* searchinBST(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data > key){
        return searchinBST(root->left,key);
    }
    return searchinBST(root->right,key);
}

//Delete in a BST, but while deleting a node then binary search tree must preserve.
//Case-1: Node is a leaf, directly delete it.
//Case-2: Node has one child, then directly attach that node to the deleted one.
//Case-3: Node has two child, then the node next in inorder sequence(sorted), must be swapped with the node to delete, till todelete node becomes a leaf node, and then we would delete it.

Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

Node* deleteinBST(Node* root,int key){
    if(key<root->data){
        root->left=deleteinBST(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteinBST(root->right,key);
    }
    else if(key==root->data){
        //it is also valid for both left and right empty..
        //if one child is empty, then directly return another child..
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteinBST(root->right,temp->data);
    }
    return root;
}

//Building Binary Search Trees from Preorder
//Actually logic is same, as inorder is nothing but sorted sequence of BST.
//shows wrong output, please check it.
//Time Complexity: O(N)
Node* constructBST(int preorder[],int* preorderIdx,int key,int min,int max,int n){
    if(*preorderIdx>=n){
        return NULL;
    }
    Node* root=NULL;
    if((key>min) && (key<max)){
        root=new Node(key);
        *preorderIdx=*preorderIdx+1;
        if(*preorderIdx<n){
            root->left=constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n){
            root->right=constructBST(preorder,preorderIdx,preorderIdx[*preorderIdx],key,max,n);
        }
    }
    return root;
}

//Time Complexity: O(N)
bool isBST(Node* root,Node* min=NULL,Node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool left=isBST(root->left,min,root);
    bool right=isBST(root->right,root,max);
    return left && right;
}

//Sorted Array to balanced BST
Node* balBST(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root=new Node(arr[mid]);
    root->left=balBST(arr,start,mid-1);
    root->right=balBST(arr,mid+1,end);
    
    return root;
}

int main(){
    //Binary Search Trees, inorder is always in a sorted manner.
    Node* root=NULL;
    root=insertBST(root,5);
    insertBST(root,1); insertBST(root,3); insertBST(root,4); 
    insertBST(root,2); insertBST(root,6); insertBST(root,7);
    inorder(root);
    cout<<endl<<searchinBST(root,5)->data<<endl;
    if(searchinBST(root,8)==NULL){
        cout<<"Key doesn't exists."<<endl;
    }
    inorder(deleteinBST(root,5));
    cout<<endl;
    //it really deletes in main root BST, from memory.
    int preod[]={10,2,1,13,11};
    int n=5;
    int preorderIdx=0;
    Node* root1=constructBST(preod,&preorderIdx,preod[0],INT_MIN,INT_MAX,n);
    preorder(root1);
    cout<<endl<<isBST(root)<<endl;
    cout<<isBST(root1)<<endl;
    int arr[]={10,20,30,40,50};
    preorder(balBST(arr,0,4));
return 0;}
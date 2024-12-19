#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

/*
Binary Trees starts with root Level 0 , then goes on and ends with leaf.
Binary Trees has only two child, left and right child.
Properties of Binary Trees(No use):
1. Maximum nodes at Level L: 2^L
2. Maximum nodes in a tree of height H is 2^H-1.
3. For N nodes, minimum possible height or minimum number of levels are log(N+1)(base2).
4. A binary tree with N leaves has atleast log(N+1)(base2)+1 number of levels.
*/

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
//Preorder Traversal: Root then leftsubtree(complete), then right subtree(complete)
//Inorder Traversal: Left Subtree then root then right subtree
//Postorder Traversal: Left Subtree then right subtree then root
//Each time we visits root in between and in very first, but we are noting it out.

void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* buildtreefrompreandinorder(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    Node* node=new Node(curr);

//when there are further no branches
    if(start==end){
        return node;
    }

//searching el in inorder, left of it is left subtree, and right is right subtree.
//start and end is just for mapping required inorder.

//first left as in preorder, first there is left subtree then right subtree.
    int pos= search(inorder,start,end,curr);
    node->left=buildtreefrompreandinorder(preorder,inorder, start,pos-1);
    node->right=buildtreefrompreandinorder(preorder,inorder,pos+1,end);
    return node;
}

Node* buildTreefrompostorderandinorder(int inorder[],int postorder[],int start,int end){
    static int id=4;
    if(start>end){
        return NULL;
    }
    int curr= postorder[id];
    id--;
    Node* n=new Node(curr);
    if(start==end){
        return n;
    }
    int pos=search(inorder,start,end,curr);

    //first n->right as in postorder, we are traversing array opposite, so just before root, right subtree's nodes are there, complete it then move to left subtree.
    n->right=buildTreefrompostorderandinorder(inorder,postorder,pos+1,end);
    n->left=buildTreefrompostorderandinorder(inorder,postorder,start,pos-1);
    return n;
}

void printlevelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int sumofnodesatklevel(Node* root, int k){
    if(root==NULL){
        return -1;
    }
    static int level=0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    static int sum=0;

    while(!q.empty()){
        Node* node= q.front();
        q.pop();

        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            level++;
            q.push(NULL);
        }
    }
    return sum;
}

int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
}

int sumofallnodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return sumofallnodes(root->left)+sumofallnodes(root->right)+root->data;
}

//returns the total levels in a tree including root
int heightoftree(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(heightoftree(root->left),heightoftree(root->right));
}

//as we see the tree, the longest chain formed, in binary tree, it may or may not pass through root
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    //comparing between main, left and right side of the tree.
    int currdiameter=1+heightoftree(root->left)+heightoftree(root->right);
    int leftdia=diameter(root->left);
    int rightdia=diameter(root->right);
    return max(currdiameter,max(leftdia,rightdia));
}
//replace all node's value with sum of all subtree nodes and itself
/*Time Complexity: O(N)*/
int sumreplace(Node* root){
    if(root==NULL){
        return 0;
    }
    root->data=sumreplace(root->left)+sumreplace(root->right)+root->data;
    return root->data;
}
//A balanced tree means for each node, the difference between heights of the left subtree and right subtree<=1
/*Time Complexity: O(N^2)
As we are first traversing the tree, then we are each time calling height function O(N's time complexity.
*/
bool isbal(Node* root){
    if(root==NULL){
        return true;
    }
    if(isbal(root->left)==false){
        return false;
    }
    if(isbal(root->right)==false){
        return false;
    }
    int lh=heightoftree(root->left);
    int rh=heightoftree(root->right);

    if(abs(lh-rh)<=1){
        return true;
    } else{return false;}

}

/*Time Complexity: O(N), as we are using pointers.*/
bool isbalanced(Node* root, int* height){
    if(root==NULL){
        return true;
    }
    int lh=0, rh=0;
    if(isbalanced(root->left,&lh)==false){
        return false;
    }
    if(isbalanced(root->right, &rh)==false){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    } else{
        return false;
    }
}

void rightView(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();

            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
    cout<<endl;
}

void leftView(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
    int n=q.size();
    for(int i=1;i<=n;i++){
        Node* curr=q.front();
        q.pop();
        if(i==1){
            cout<<curr->data<<" ";
        }
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    }
    cout<<endl;
}

bool getPath(Node* root,int key,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }
    if(getPath(root->left,key,path) || getPath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}

//Lowest Common Ancestor: 1->(2,3)->((4,5),(6,7)), then (4,7) have LCA=1, if(4,5) then 2.
//we are calling path1 in getPath function by address, then wherever while coming from top, our path deviates that is the point where LCA is there.
//but this is bit inefficient as we are travelling our tree multiple times.
int LCAvalue(Node* root, int n1,int n2){
    vector<int>path1,path2;
    if(!getPath(root,n1,path1) || !getPath(root,n2,path2)){
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size() && path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];
}

//to find minimum distance between two nodes in a tree, that is the nodes that we traverse TO reach there.
//good logic must revise....
Node* LCA(Node* root, int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* left=LCA(root->left,n1,n2);
    Node* right=LCA(root->right,n1,n2);

    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left==NULL && right==NULL){
        return NULL;
    }
    if(left!=NULL){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}

int findDist(Node* root,int k,int dist){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return dist;
    }
    int left=findDist(root->left,k,dist+1);
    if(left!=-1){
        return left;
    }
    return findDist(root->right,k,dist+1);
}
//1st function
int dist(Node* root, int n1,int n2){
    Node* lca=LCA(root,n1,n2);
    int d1=findDist(lca,n1,0);
    int d2=findDist(lca,n2,0);
    return d1+d2;
}

//Given a binary tree, flatten it into linked list in-place. After flattening, left of each node should point to NULL,  and right should contain next node in preorder sequences.(It's not allowed to use other data structures.)
void flatten(Node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        Node* t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    flatten(root->right);
}

//Printing nodes below that target.
void printSubtreeNodes(Node* root, int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);

}

//case2:
int printNodesAtk(Node* root,Node* target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printSubtreeNodes(root,k);
        return 0;
    }
    int dl=printNodesAtk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        //Printing nodes in other right side..
        else{
            //-2 as for root and root->right.
            printSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }

    int dr=printNodesAtk(root->right,target,k);
    if(dr!=-1){
        
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->left,k-dl-2);
        }
        return 1+dr;
    }
    return -1;
}

int maxPathSumUtil(Node* root,int &ans){
    if(root==NULL){
        return 0;
    }
    int left=maxPathSumUtil(root->left,ans);
    int right=maxPathSumUtil(root->right,ans);

    int nodeMax=max(root->data+left+right,max(root->data+right,max(root->data,root->data+left)));
    ans=max(nodeMax,ans);
    return max(root->data+right,max(root->data,root->data+left));
}

//Maximum path sum, including starting and ending node's values.
int maxPathSum(Node* root){
    int ans=INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}

int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    int preorder1[]={1,2,4,3,5};
    int inorder2[]={4,2,1,5,3};

    Node* x=buildtreefrompreandinorder(preorder1,inorder2,0,4);
    preorder(x);
    cout<<endl;
    inorder(x);
    cout<<endl;

    int postorder2[]={4,2,5,3,1};
    int inorder1[]={4,2,1,5,3};
    Node* y=buildTreefrompostorderandinorder(inorder1,postorder2,0,4);
    postorder(y);
    cout<<endl;
    inorder(y);

    //Information would be insufficient for building tree from preorder and postorder,normal skewed tree, if it is a full binary tree, we can make it.
    cout<<endl;
    printlevelOrder(y);
    cout<<endl;
    cout<<sumofnodesatklevel(y,0)<<"\n";
    cout<<countNodes(y)<<"\n";
    cout<<sumofallnodes(y)<<"\n";
    cout<<heightoftree(y)<<"\n";
    cout<<diameter(root)<<"\n";
    preorder(root);
    cout<<"\n";
    sumreplace(root);
    preorder(root);
    cout<<"\n";

    if(isbal(root)){
        cout<<"Balanced\n";
    } else{ cout<<"Unbalanced\n";}
    int height=0;
    if(isbalanced(root,&height)){
        cout<<"Balanced\n";
    } else{
        cout<<"Unbalanced\n";
    }
    rightView(root);
    leftView(root);
    cout<<LCAvalue(root,15,4)<<endl;
    cout<<dist(root,15,4)<<endl;
    flatten(root);
    inorder(root);
    cout<<endl;
    printNodesAtk(root,root->right,1);
    cout<<endl<<maxPathSum(root)<<endl;
return 0;}
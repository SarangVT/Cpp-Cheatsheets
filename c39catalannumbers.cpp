#include "bits/stdc++.h"
using namespace std;
/*Time Complexity: O(N^2)*/
int catalan(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0;i<=n-1;i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}
/*
Application of catalan numbers:
1. Possible BSTs
2. Paranthesis/ bracket combinations
3. Possible forests
4. Ways of triangulations
5. Possible paths in matrix
6. Dividing a circle using N chords.
7. Dyck words of given length and much more.
*/

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

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

vector<Node*> constructTrees(int start,int end){
    vector<Node*>trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<Node*> leftSubtrees = constructTrees(start,i-1);
        vector<Node*> rightSubtrees = constructTrees(i+1,end);

        for(int j=0;j<leftSubtrees.size();j++){
            Node* left=leftSubtrees[j];
            for(int k=0;k<rightSubtrees.size();k++){
                Node* right=rightSubtrees[k];
                Node* node=new Node(i);
                node->left=left;
                node->right=right;
                trees.push_back(node);
            }
        }
    }
}

int main(){
for(int i=0;i<5;i++){
    cout<<catalan(i)<<" ";
}
cout<<endl;

vector<Node*> totalTrees=constructTrees(1,3);
for(int i=0;i<totalTrees.size();i++){
    cout<<(i+1)<<" : ";
    preorder(totalTrees[i]);
    cout<<endl;
}





return 0;}
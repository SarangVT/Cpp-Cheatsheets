#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* next[2];
    TrieNode(){
        next[0]=nullptr;
        next[1]=nullptr;
    }
};

TrieNode* buildtrie(vector<int> &a){
    TrieNode *root=new TrieNode();
    int n=a.size();
    for(int i=0;i<n;i++){
        int num=a[i];
        TrieNode *cur=root;
        for(int j=31;j>=0;j--){
            int bit=(num>>j) & 1;
            if(cur->next[bit] == nullptr){ cur->next[bit] = new TrieNode();}
            cur = cur->next[bit];
        }
    }
    return root;
}

//Feel: We have stored all numbersin that Trie, then we are considering each nmumber and then finding a perfect opposite bit of each number to it, 
//we don't have to xor every time by other numbers, even if the another number is long, and it can be bigger as 0^a=a, then the longer number would be definitely also come in loop, 
//and xor with same smaller number then it would be considered.

int helper(TrieNode* root, vector<int> &a){
    int res=0;
    for(int i=0;i<a.size();i++){
        int num = a[i];
        TrieNode* it=root;
        int cur_max=0;
        for(int j=31;j>=0;j--){
            //To go in opposite direction.
            int bit = ((num>>j) & 1) ? 0 : 1;
            if(it->next[bit]){
                cur_max<<=1; //it means left shift assignment operator, it left shifts the number by given number in right and then assigns it to current
                cur_max |= 1; //it is curr_max+1
                it = it->next[bit];
            }
            else{
                cur_max<<=1;
                it = it->next[bit xor 1];
            }
        }
        res=max(res,cur_max);
    }
    return res;
}

int main(){
    vector<int> a={3,10,5,15,2};
    TrieNode* root=buildtrie(a);
    int ans=helper(root,a);
    cout<<ans;
return 0;}
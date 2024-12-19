#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>b;i--)
#define vii <vector<pair<int,int>>
int int_size=32;

class node{
    public:
        node* next[2];
        node(){
            fl(i,0,2){
                next[i]=NULL;
            }
        }
};

    node* trie;

    void insert(int num){
        node* it=trie;
        flb(i,int_size-1,-1){
            int cur_bit=(num>>i) & 1;
            if(!it->next[cur_bit]){
                it->next[cur_bit] = new node();
            }
            it=it->next[cur_bit];
        }
    }

    int query(int num){
        node* it=trie;
        int ans=0;
        flb(i,int_size-1,-1){
            int cur_bit=(num>>i) & 1;
            int opposite = cur_bit xor 1;
            if(it->next[opposite]){
                it=it->next[opposite];
                ans |= 1<<i;  //this means ans=ans+(1<<i)
            }
            else{
                it=it->next[opposite xor 1];
            }
        }
        return ans;
    }

    int32_t main(){
    /*Problem: Given an array arr. You are supposed to find the maximum value of (arr[a]^arr[a+1]..^arr[b]) + (arr[c]^arr[c+1]^arr[c+2]...arr[d])
    where 0=a<=b < c(b+1)<=d=N-1, where N is the size of the array.
    ^ denotes XOR operation.

    Idea: We know how to calculate maximum XOR subarray at 'i', let us denote it as lmax[]
    If we do the same from right side, we can get maximum XOR Subarray at 'i', let us denote it as rmax[]
    Final ans would be the maximum of lmax[i]+rmax[i+1]
    */
    int n=4;
    vi a = {1,2,6,8};
    fl(i,0,4){
        cout<<a[i]<<" ";
    }
    trie = new node();
    insert(0);
    vi rmax(n+1,0);
    int R=0;
    flb(i,n-1,-1){
        R = R xor a[i];
        if(i!=n-1){
            rmax[i]=max(rmax[i+1],query(R));
            insert(R);
        }
        else{
            rmax[i]=query(R);
            insert(R);
        }
    }
    free(trie);
    trie=new node();
    insert(0);
    int ans=0;
    int L=0;

    //finally rmax() contains maximum of xor value from right, and query from left.
    fl(i,0,n){
        L = L xor a[i];
        ans=max(ans,rmax[i+1]+query(L));
        insert(L);
    }

    cout<<ans;

    return 0;}
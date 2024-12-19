#include "bits/stdc++.h"
// #include <deque>
using namespace std;
/*
Using Stacks:LIFO and queues:FIFO,
we can make double ended queue, deque,
It can:
1. Push and Pop from the end.
2. Insert and delete from the start.
Header File <deque>
*/
int32_t main(){
    deque<int> d;
    d.push_front(3);
    d.push_back(4);
    d.push_front(2);
    d.push_front(1);
    for(auto i: d){
        cout<<i<<" ";
    }cout<<"\n";
    d.pop_back();
    cout<<d.back()<<endl<<d.size();
    cout<<endl;
/*Sliding Window Maximum:
    arr[]={1,2,3,-5,3,7,8}
    if k=3, {3,3,3,7,8};
    eg: {1,2,3} greatest number=3;
    {2,3,-5} greatest number=3;*/
    //Time Complexity: O(nlogn)
    //Check this code whenever got chance...
    int n=8;//Array size
    int k=3;//Window size
    int p=9;
    vector<int> a(n); //Stores all elements
    for(auto &i: a){
        i=p;
        p--;
    }
    a.pop_back();
    a.push_back(100);

    //Method-1
    multiset<int,greater<int>> s;
    //by greater at top always greater element stays
    vector<int> ans;
    for(int i=0;i<k;i++){
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());
    for(int i=k;i<n;i++){
        s.erase(s.lower_bound(a[i-k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;


ans.clear();
//Method-2
    //Time Complexity: O(kN)
    int arr[]={1,2,3,-5,3,7,8,9};
    deque<int> q;
    int maximum=INT_MIN;
    for(int i=0;i<k;i++){
        maximum=max(maximum,arr[i]);
        q.push_back(arr[i]);
    }
    ans.push_back(maximum);
    for(int i=k;i<n;i++){
        q.pop_front();
        q.push_back(arr[i]);
        deque<int> temp=q;
        maximum=INT_MIN;
        for(int i=0;i<k;i++){
            maximum=max(maximum,q.front());
            q.pop_front();
        }
        ans.push_back(maximum);
        q=temp;
    }

for(auto el:ans){
    cout<<el<<" ";
}cout<<endl;
return 0;}
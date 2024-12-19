#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

int main(){
/*Set: Ordered Unordered
Ordered Set: Contains unique elements
Implemented using balanced BST, search O(logN)
Elements are in sorted order
Random access is not possible, i.e. you cannot get i'th element in O(1)/O(logN)
Present in <set>header file
*/
set<int> s;
s.insert(1);
s.insert(1);
//doesn't allow duplicates
s.insert(2);
s.insert(3);
for(auto i:s){
    cout<<i<<" ";
}
cout<<"\n";
for(auto i=s.begin();i!=s.end();i++){
    cout<<*i<<" ";
}
cout<<"\n";
for(auto i=s.rbegin();i!=s.rend();i++){
cout<<*i<<" ";
}
cout<<endl<<s.size()<<endl;

set<int,greater<int>> x;
//It makes the set to arrange elements in descending order.
set<int>q;
q.insert(1);
q.insert(3);
q.insert(5);
//it would work differently for <int,greater<int>>...
cout<<*q.lower_bound(2)<<"\n";
cout<<*q.lower_bound(3)<<"\n";
cout<<*q.upper_bound(3)<<"\n";
cout<<(q.upper_bound(5)==q.end())<<"\n";
//to erase elements from set,
q.erase(3);
q.erase(q.begin());
for(auto i:q){
    cout<<i<<" ";
}cout<<endl;

/*MultiSet:
Can contain duplicates
Implemented using balanced BST
Elements are in sorted order
Random access is not possible, i.e. you cannot get i'th element in O(1)/O(log(N))
Present in <set> header file
*/

multiset<int> m;
m.insert(1);
m.insert(3);
m.insert(2);
m.insert(3);
m.insert(3);
m.insert(5);
for(auto i:m){
    cout<<i<<" ";
}
cout<<endl;
m.erase(m.find(3));
//deletes all elements valued 3.
for(auto i:m){
    cout<<i<<" ";
}
cout<<endl;
m.erase(3);
//deletes all elements valued 3.
for(auto i:m){
    cout<<i<<" ";
}
// Time Complexities of set and multiset:
// Insertion, Deletion,Lower/Upper_Bound: O(LogN)
//To print any n elements is O(NlogN)
//as to search is LogN, and to print is N.


/*Unordered Set
Contains unique elements
Implemented using hashing
Elements are not in sorted order
Random access is not possible, i.e.you cannot get i'th element in O(1)
Present in <unordered_set> header file
*/

//Same commands, insert except lower and upper bound.
/*
Insertion: O(1) in avg case, O(N) in worst case
Deletion: O(1) in avg case, O(N) in worst case
Lower/Upper_Bound: NA
*/
cout<<endl;
unordered_set<int> u;
//it fills like stacks, implemented by hashing
u.insert(1);
u.insert(100);
u.insert(5);
u.insert(5);
for(auto i:u){
    cout<<i<<" ";
}

return 0;}
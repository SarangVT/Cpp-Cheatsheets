#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/*Policy Based Data Structure:
Ordered Set
Based on Red Black Trees
Included in
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/
template<class T> using sarangset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
/*
Ordered Set:
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
null_type: It is the mapped policy. It is null here to use it as a set. If we want to get map but not the set, as the second argument type must be used mapped type.
less: It is the basis for comparison of two functions. Use less_equal for ordered multiset.(duplicate elements allowed then)
rb_tree_tag: type of tree used.
tree_order_statistics_node__update: It is included in tree_policy.hpp and contains various operations for updating the node variants of a tree-based container, so we can keep track of metadata like the number of nodes in a subtree.

Normal Set Operations:
Random Access in O(Log N)
Find K'th largest element in the set.
Number of items less than K in O(LogN)

It has two key functions:
order_of_key(k): Number of items strictly smaller than k
find_by_order(k): K-th element in a set(countinf from zero)
Time Complexity: O(LogN)

Question:
Given q queries, of 3 types.
1. Insert a number X into the set.
2. Print the K'th element.
3. Print the number of elements less than K
1 a : means insert a
2 b: print number on bth index, in 0-based indexing
3 c: find the number of elements less than c
*/

int q;cin>>q;
sarangset <int> s;
//you can make the set of anything dynamically.
sarangset<pair<int,int>> temp1;
sarangset <vector<int>> temp2;
while(q--){
    int c;cin>>c;
    if(c==1){
        int t;cin>>t;;
        s.insert(t);
    }
    else if(c==2){
        int t;cin>>t;
        cout<<*s.find_by_order(t)<<endl;
    }
    else{
        int t;cin>>t;
        cout<<s.order_of_key(t)<<endl;
    }
}
return 0;}

#include <iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

/*count number of subarrays with sum zero
Brute Force Method: Go over all the subarray's and compute sum.
Optimized Solution:
1. Compute Prefix Sum
Map prefix sum to a map
For every key, choose 2 values from all the occurrences of particular prefsum(mC2).
Special Case: for prefsum 0, we have to also include them.
*/
int numofsubarrayswithsum0(vector<int> &a,int n){
    map<int,int> cnt;
    //prefSum of i means that the sum of elements starting from 0 to i'th position

    int prefSum=0;

    for(int i=0;i<n;i++){
        prefSum+=a[i];
        cnt[prefSum]++;
    }

    int ans=0;
    map<int,int> :: iterator it;
    for(it=cnt.begin();it!=cnt.end();it++){

    //if any prefSum attains same value at i and j (i<j) then definitely, sum of elements from i+1 to j is 0.
    //so such if there is x repeating m times, then if we chose any 2 of this we get an subarray with sum 0, therefore mC2.
        int c=it->second;
        ans+=(c*(c-1))/2;
        //if sum is only 0 directly add it.
        if(it->first==0){
            ans+=it->second;
        }
    }
    return ans;
}

int main(){
/*E.g.: Play with element's indices.
Two options:
1. Traverse the whole array.
2. Map elements and their indices.(Better, but require memory.)

Problem: Storing indices of such large elements of order 10^9 is not possible as, array's limit is 10^8(that too global)
Solution: Converting elements into smaller elements using some functions(hash functions).
Problem: After applying we get same keys.(Collision)
Solution: 
1. Separate Chaining: Make Linked List, for the elements. Worst Case:O(N)
n-no of values to be mapped, b-no of keys available for mapping-b
Load Factor: n/b, on each key

2. Open Addressing: Do Probing(Using a second argument, called probe number in the hash function)
Probe number depends on key, hence given by P(k).
Linear Probing: P(k): a*k+b,
Quadratic Probing: a*k^2+b*k+c
Double Hashing: k*h2(x),h2(x) is a secondary hash function.
*/

/*Standard Template Library:
1. Maps: 
Insertion: O(log(N))
Accessing: O(log(N))
Deletion: O(log(N))
Implemented using: Red-Black Trees

2. Unordered Maps:
Insertion: O(1) {on average }
Accessing: O(1)
Deletion: O(N)
Implemented using: Hash Tables (basically array of buckets)
Data-Type: key,value
map<int,int> mp;
unordered_map<int,int> ump;
*/
map<int,int>mp;
unordered_map<int,int> ump;
mp[8]=2;
ump[0]=1;
cout<<ump[0]<<endl;
cout<<mp[8]<<endl;

cout<<mp[7]<<endl<<ump[1]<<endl;
//By default values are assigned to 0.

//Count frequency of elements in a a given array.

vector<int> a;
a.push_back(2);a.push_back(2);a.push_back(1);a.push_back(1);a.push_back(3);a.push_back(2);a.push_back(3);

map<int,int> freq;
for(int i=0;i<7;i++){
    freq[a[i]]++;
}

map<int,int> :: iterator it;
for(it=freq.begin();it!=freq.end();it++){
    cout<<it->first<<" has a frequency of "<<it->second<<endl;
}

vector<int> b(4);
b[0]=b[2]=1;
b[1]=b[3]=-1;
for(int i=0;i<4;i++){
    cin>>b[i];
}
cout<<numofsubarrayswithsum0(b,4)<<endl;

return 0;}
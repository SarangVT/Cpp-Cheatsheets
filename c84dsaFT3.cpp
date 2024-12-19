#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii vector<pair<int,int>>

/*Problem Statement:
Count the inversiona in the given array.
Two elements a[i] and a[j] form an inversion, if a[i] > a[j] and i < j

BIT:
Traverse through the array and for every index, find the number of smaller elements on its right side of the array.
Sum up the counts for all indexes in the array and print the sum.

1. Convert the array into relative ordering:
For example, if the array is {-3,2,0} then the array gets converted to {1,3,2}.
To take negative and large values into account.
*/

vi bit;

int getSum(int idx){
    int sum=0;
    while(idx>0){
        sum+=bit[idx];
        idx-=idx&(-idx);
    }
    return sum;
}

void update(int n, int idx, int inc){
    while(idx<=n){
        bit[idx]+=inc;
        idx+=idx&(-idx);
    }
}

int main(){
int n; cin>>n;
vi a(n);
for(auto &i: a){
    cin>>i;
}
vi temp = a;
sort(temp.begin(),temp.end());
fl(i,0,n){
    //returns the element's iterator next to where a number can be fitted, some number if it is biggest number.
    a[i]=lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin() + 1;
    //without +1, there is its index in 0-based for 1-based we need +1.
}

bit = vi(n+1);
int inv=0;

//Traverse all elements from right.
flb(i,n-1,0){
    //Get count of elements smaller than arr[i].
    inv+=getSum(a[i]-1);
    //Add current element to BIT.
    update(n,a[i],1);
}

//See traversing from right is important, as it gives us only the idea of numbers smaller than the number in right, we are availing advantage of dynamic counting of fenwick tree.
//But, if we first made tree we would made count of all numbers smaller than each other.
//Actually here the value of tree nodes, contains count only, not complete in discrete manner, cumulative of how much lower they contain, and we are defining fenwick tree from right direction of 'a' vector.
cout<<inv;
return 0;}
#include <iostream>
using namespace std;

void countSort(int arr[],int n){
    int k = arr[0];

    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }

    int output[n];
    for(int i=n-1;i>=0;i--){
        //-- as n-1 is required.
        output[--count[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

int main(){
//Count Sort: Find the count of every distinct element in the array
//Calculate the position of each element in sorted array
int arr[]={1,3,4,3,4,1,6,4,3};
//in this eg entries in arrays are limited  to 10.
countSort(arr,9);
for(int i=0;i<9;i++){
    cout<<arr[i]<<" ";
}
/*Time Complexity:
1. First we create an array of appropritae range, Time O(max(Ai))
2. Filled the frequencies of each element. Time O(N)
3. Iterate the frequency array. Time: O(max(Ai))
Final T C = max(Ai,N)
*/


return 0;}

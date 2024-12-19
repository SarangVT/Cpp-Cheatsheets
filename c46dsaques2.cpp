#include "bits/stdc++.h"
using namespace std;

int searchInRotatedArray(int arr[],int key,int left,int right){
    if(left>right){
        return -1;
    }
    //finding mid
    int mid=(left+right)/2;
    //checking key found
    if(arr[mid]==key){
        return mid;
    }

//checking if mid is in rotated and frontened part only(6,7,1,2,3,4,5), here checking arr[mid] is 6,7
    if(arr[left]<=arr[mid]){
        if(key>=arr[left] && key<=arr[mid]){
            return searchInRotatedArray(arr,key,left,mid-1);
        }
        return searchInRotatedArray(arr,key,mid+1,right);
    }
//checking if mid is in other ascendingly sorted array, and right part like in 1,2,3,4,5
    if(key>=arr[mid] && key<=arr[right]){
        return searchInRotatedArray(arr,key,mid+1,right);
    }

//if not then search in bigger elements like left part
//no tension whether we are passing an rotated array here, as it again calling itself only.
    return searchInRotatedArray(arr,key,left,mid-1);
}

void findPeakElement(int arr[],int i,int j,int n){
    int mid=(i+j)/2;
    if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1])){
        cout<<mid<< " ";
    }
    if(mid>0 && arr[mid-1]>arr[mid]){
        findPeakElement(arr,i,mid-1,n);
    }
    if(arr[mid+1]>arr[mid]){
        findPeakElement(arr,mid+1,j,n);
    }
}

void maxSubArraySum(int arr[],int n,int k,int x){
    int ans=0, sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    if(sum<x){
        ans=sum;
    }
    for(int i=k;i<n;i++){
        sum+=arr[i];
        sum-=arr[i-k];
        //Checking if it doesn't exceed k, then find max between them.
        if(sum<x){
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}

int minSubArraySum(int arr[],int n,int x){
    int sum=0,minLength=n+1,start=0,end=0;
    int ans=INT_MAX;
    while(end<n){
        while(sum <= x && end < n){
            sum += arr[end++];
        }
        while(sum > x and start < n){
            if(end-start < minLength){
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
}

int main(){
//Search element in sorted and rotated array: We are given an ascending sorted array that has been rotated from a pivot point (unknown to us)
//and an element X. Search forX in the array with complexity less than that of linear search.
int arr[]={6,7,8,9,10,1,2,5};
int i=searchInRotatedArray(arr,8,0,7);
if(i==-1){
    cout<<"Key doesn't exist"<<endl;
}
else{
    cout<<"Key exists at idx: "<<i<<endl;
}

//For a given array, find the peak element in the array.Peak element is one which is greater than both, left and right neighbours of itself.
/*Corner cases: Ascending array: last element is peak
Descending array: first element is peak
For all same elements: each element is peak
*/

int arr1[]={10,20,15,2,23,90,67};
findPeakElement(arr1,0,6,7);
 

/*For a given array and integers K and X, find the maximum sum subarray of size K and having sum less than X.
Brute Force Method: Sum of all possible subarrays of size K, Time Complexity: O(N*K)
Sliding window approach: 
1. Calculate the sum of first k elements.
2. Intialize ans with sum.
3. Iterate over the rest of the array, keep adding one element in sum and removing one from start. Compare new sum with ans in each iteration.
Time Complexity: O(N)
*/
cout<<endl;
int arr2[]={7,5,4,6,8,9};
maxSubArraySum(arr2,6,3,20);

/*For a given array and an integer X, find the minimum subarray size for which sum>X
Brute Force Method: Compute sum of all subarrays and check the condition. Time Complexity: O(N^2)
Sliding Window:
1. Variables ans(subarray's min sum), sum(which keeps temp sum), start(ans subarray's starting index)
2. Iterate over array and start adding elements to sum.
3. If sum>X, remove elements from the start.
4. After check that if by removing sum is still greater, if yes, update ans, not then still remove it and update the front pointer and delete the last element still, as no use of keeping it,as we have found a solution lesser than that size, so find a better solution ahead. 
Time Complexity: O(N)
*/
int arr3[]={1,4,45,6,10,19};
cout<<minSubArraySum(arr3,6,51)<<endl;

return 0;}
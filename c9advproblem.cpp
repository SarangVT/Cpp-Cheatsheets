#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
    int currentSum = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        currentSum+=arr[i];
        if(currentSum<0){
            currentSum=0;
        }
        maxSum = max(maxSum,currentSum);
    }
    return maxSum;
}

bool pairsum(int d[],int n,int k){
//remember input sorted array.
int l = 0;
int h=n-1;

for(int i=0;i<n;i++){
    if(d[l]+d[h]<k){
        l++;
    } else if(d[l]+d[h]>k){
        h--;
    } else if(d[l]+d[h]==k){
        return 1;
    }
}
return 0;
}

int main(){
    int array[5] = {1,3,7,4,8};
    int maximum = INT_MIN;
    for(int i=0;i<5;i++){
        maximum = max(array[i],maximum);
    }
    cout<<maximum<<endl;

//subarrays of an array with size n is nC2 + n = (n*(n+1))/2;
//logic is chose any two elements(i,j) in array, then the array between them becomes a subarray, and if i=j, then n cases.

//subsequences is a sequence that can be derived from an array by selecting zero or more elements, without changing the order of the remaining elements.
//number of subsequences = 2^n, as sigma of nC0 to nCn, each time forming an subsequence of r size in nCr.
//inference, subarrays are the subsets of subsequences.
    //to print sum of, sum of all subarrays of an array.(sum of subarray refers to sum of all its elements)
    int arr[2] = {2,3};
    int n=2;
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
           for(int s=i;s<=j;s++){
            sum+=arr[s];
           } 
        }
    }
    cout<<sum<<endl;

 /*   Longest Arithmetic Array:(Kick Start)
An arithmetic array is an array that contains atleast two integers and the difference between consecutive integers are equal. For example, [9,10], [3,3,3], [9,7,5,3],
while[2,1,2] and[1,2,4] are not arithmetic arrays.
Gopal has an array of N non-negative integers. The i-th integer is Ai. He wants to choose a contiguous arithmetic subarrray from his array that has the maximum length.
Please help him to determine the length of the longest contiguous arithmetic subarray.

Input: The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line conataining the intger N. The second line contains N intgers.
The ith integer is Ai.
Output: For each test case, output one line containing Case #x:y, where x is the test case number(starting from 1) and y is the length of the longest contiguous arithmetic subarray.

Constraints:
Time limit: 20 seconds per test
Memory limit: 1GB
1<=T<=100
0<=Ai<=10^9

Test Set 1
2<=N<=2000

Test Set 2
2<=N<=2*10^5 for at most 10 test cases/
For the remaining cases, 2<=N<=2000

1 sec = 10^8 operations(approx).
*/ 

//to find index of repeated element with index of first occurence smallest:
//Constraints: 1<=N<=10^5
//0<-Ai<=10^5

int a[6] = {2,3,4,5,3,2};
int N = 1e5+2;
//N is kept like this as Ai ranges to 1e6.
int idx[N];
//Making an array with all elements -1 intially.
for(int i=0;i<N;i++){
    idx[i] = -1;
}

int minidx = INT_MAX;
    for(int i=0;i<6;i++){
        if(idx[a[i]] != -1){
            minidx = min(minidx, idx[a[i]]);
        } else{
            idx[a[i]] = i;
        }
    }
    if(minidx == INT_MAX){
        cout<<"-1"<<endl;
    } else{
        cout<<minidx<<endl;
    }

/*Problem: An unsorted array A of size N of non-negative integers, find a contiguous subarray which adds to a given number S.
Constraints: 1<=N<=10^5
            0<=Ai<=10^10
            */

//Brute Force Method: Compare the desired value with the sum of all subarrays.
//Time Complexity: O(n^2)
//Optimized: Time Complexity: O(n)
    n=9;
    int b[9] = {1,3,8,5,4,5,3,7,0};
    int s = 11;
    int i=0, j=0, st = -1, en = -1;
    sum = 0;
    while(j<n && sum+b[j] <=s){
        sum+=b[j];
        j++;
    }
    if(sum==s){
        cout<<i<<" "<<j-1<<endl;
    } 
    else{
        while(j<n){
            sum+=b[j];
        while(sum>s){
            sum -= b[i];
            i++;
        }
        if(sum==s){
            st = i;
            en = j;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en<<endl;
}

/*
Smallest Positive Missing Number:
Given an array of N integers including 0. The task is to find the smallest positive number from the array.
Constraints: 1<=N<=10^6
-10^6<=Ai<=10^6
For accessing negative indices, make an array of 2*10^6 size, and store -one in one half and full one in other.
*/
//using previous array
int X = 2e5+1;
bool check[X];
n=9;
for(int i=0;i<N;i++){
    check[i] =false;
}

for(int i=0;i<n;i++){
    check[b[i]+((N+1)/2)]=true;
}
for(int i=(N+3)/2;i<N;i++){
    if(check[i]==false){
        cout<<(i-(N+1)/2)<<endl;
        break;
    }
}
//Maximum Subarray Sum: Cumulative Sum Approach
//Brute Force Method: Find the sum of all subarrays, and then find max of it.
int finalans = INT_MIN;
for(int i=0;i<n;i++){
    int answ = 0;
    for(int j=i;j<n;j++){
        answ+=b[j];
    }
    finalans = max(finalans,answ);
}
cout<<finalans<<endl;

//Kadane's Algorithm:
int currentSum=0;
int maxSum=INT_MIN;

for(int i=0;i<n;i++){
    currentSum+=b[i];
    if(currentSum<0){
        currentSum=0;
    }
    maxSum = max(maxSum,currentSum);
}
cout<<maxSum<<endl;
//Time Complexity is O(n).

/*Maximum Circualar Subarray Sum
    Max Subarray sum = Total sum of array - Sum of non-contributing elements.
*/
int wrapsum;
int nonwrapsum;
int c[7] = {4,-4,6,-6,10,-11,12};
n=7;
nonwrapsum = kadane(c,n);
int totalsum=0;
for(int i=0;i<n;i++){
    totalsum+=c[i];
    c[i]=(-c[i]);
}
//in total sum, the elements with largest negative sum, is there now we add same positive of that, to make their contribution 0.
wrapsum = totalsum+kadane(c,n);
cout<<max(wrapsum,nonwrapsum)<<endl;

/*Pair Sum Problem:
Check if there exists two elements in an array such that their sum is equal to given k.
*/
int d[5] = {1,2,3,4,5};
int k =7;
n=5;
//Brute force method: O(n^2);
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(d[i]+d[j]==k){
            cout<<i<<" "<<j<<endl;
        }
    }
}

//Optimised Approach: Two pointers on sorted array, if their sum greater, high pointer backwards, and if low then low pointer frontwards.
//Time Complexity: One which is bigger of sorting or n.
cout<<pairsum(d,n,k)<<endl;

return 0;}
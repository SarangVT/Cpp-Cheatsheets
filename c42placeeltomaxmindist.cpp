#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
/*Given is an array with n elements that represents n positions along a straight line. 
Find K elements, such that the minimum distance between any 2 elements is the maximum possible.
*/

bool isFeasible(int mid,int arr[],int n,int k){
    int pos=arr[0],elements=1;
    for(int i=1;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            elements++;
            if(elements==k){
                return true;
            }
        }
    }
    return false;
}


int largestMinDistance(int arr[],int n,int k){
    sort(arr,arr+n);
    int result=-1;
    int left=1;
    int right=arr[n-1];
    while(left<right){
        int mid=(left+right)/2;
        if(isFeasible(mid,arr,n,k)){
            result=max(result,mid);
            left=mid+1;
        } else{
            right=mid;
        }
    }
    return result;

}

bool isPossible(int arr[],int n,int m,int min){
    int studentsRequired=1,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>min){
            return false;
        } if(sum+arr[i]>min){
            studentsRequired++;
            //now as it is going above than mid we would, now giving bookd to another student
            sum=arr[i];
            //while distributing if students go greater than m, it means it isn't viable
            if(studentsRequired>m){
                return false;
            }
        }
        else{
            sum+=arr[i];
        }  
    }
    //it will certainly increase studentrequired by 1 as min is basically mid
    //everything goes right return true
    return true;
}

int allocateMinimum(int arr[],int n,int m){
/*Apply binary search for minimum and maximum possible values of max pages. Check the feasibility of this chosen value.
Assign pages to each student in a sequential manner, while the current number of allocate pages don't exceed the value set by binary search.
If during allocation the number of students don't exceed the limit of 'm', then the solution is feasible. Else it isn't
*/
int sum=0;
if(n<m){
    return -1;
}
for(int i=0;i<n;i++){
    sum+=arr[i];
}

//start and end pointers are basically the value pointers aiming to reach the actual value.
int start=0, end=sum, ans=INT_MAX;
while(start<=end){
    int mid=(start+end)/2;
    if(isPossible(arr,n,m,mid)){
        //if there is a sol, give it
        ans=min(ans,mid);
        //but we would find for better sol, in left half
        end=mid-1;
    }
    else{
        //if not we would find in right half
        start=mid+1;
    }
}
return ans;
}

int findFeasible(int boards[],int n,int limit){
    int sum=0,painters=1;
    for(int i=0;i<n;i++){
        sum+=boards[i];
        if(sum>limit){
            sum=boards[i];
            painters++;
        }
    }
    return painters;
}

int paintersPartition(int boards[],int n,int m){
    int totalLength=0,k=0;
    for(int i=0;i<n;i++){
        k=max(k,boards[i]);
        totalLength+=boards[i];
    }
    //as min time, would be the painter which got longest board
    int low=k,high=totalLength;

    while(low<high){
        int mid=(low+high)/2;
        int painters=findFeasible(boards,n,mid);
        if(painters<=m){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main(){
/*Brute Force Method: FInd all possible subsets of size K and compare the minimum distance betweeen all of them.
Binary Search:
1.Sort the array for binary search technique.
2. Pick middle el as result and check for its feasiblity.
3. If feasible, search the right half of the array with larger minmum distance.
4. Else, search the left half of the array.
*/

int arr[]={1,2,8,4,9};
cout<<largestMinDistance(arr,5,3)<<endl;
/*
Allocate Minimum Pages: given an array of n dfferent books with ascending order according to pages, m- number of students.
All the books have to be divided among m students, consecutively, means in a order. Allocate the pages in such a way that maximum pages allocated to a student is minimum.
*/
int a[]={12,34,67,90};
cout<<allocateMinimum(a,4,2)<<endl;
//See your were able to give books in sorted order, but now the boards can't be given in any order, it must be in original order only
/*Painter's Partititon Problem:
n-length of n different boards
m-painters available
A painter paints 1 unit of board in 1 unit of time and each painter will paintc consecutive boards.
Find the minimum time that will be required to paint all the boards.
*/
int boards[]={10,20,30,40};
cout<<paintersPartition(boards,4,2);

return 0;}
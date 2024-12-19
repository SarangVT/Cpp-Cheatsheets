#include "bits/stdc++.h"
using namespace std;
//Count inversion means if arr[i]<arr[j] && i>j.
//Brute Force method:
int countinversion1(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
            count++;}
        }
    }
    return count;
}

long long merge(int arr[],int l,int mid,int r){
    long long inv =0;
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            i++;k++;
        } else{
            arr[k]=b[j];
            j++;k++;
            inv += n1-i;
            //as if a[i] is bigger than b[j], then a[i+1,i+2,...n1-1] would also be bigger.(n1-1)-(i)+1.
        }
    }

//now no further inversions are needed, as they are already covered.
    while(i<n1){
        arr[k]=a[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;k++;
    }

return inv;
}

//Optimised Approach:
long long mergeSort(int arr[],int l,int r){
    long long inv=0;
    if(l<r){
        int mid=l+r/2;
        inv += mergeSort(arr,l,mid);
        inv += mergeSort(arr,mid+1,r);
        inv +=merge(arr,l,mid,r);
    }
    return inv;
}

int main(){
int array[]={3,5,6,9,1,2,7,8};
cout<<countinversion1(array,8)<<endl;
//Time Complexity: O(n^2).
int array1[]={3,2,1};
cout<<mergeSort(array1,0,2)<<endl;

return 0;}
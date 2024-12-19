#include <iostream>
#include <climits>
using namespace std;

int linearSearch(int arr[], int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        } 
    }
    return -1;
}

int binary_Search(int arr[], int n,int key){
    int s=0;
    int e=n;
    while(s<=e){
    int mid = (s+e)/2;
    if(arr[mid]==key){
        return mid;
    } else if(arr[mid]>key){
        e=mid-1;
    } else if(arr[mid]<key){
        s = mid+1;
    }
    }
    return -1;
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

void selection_sort(int arr[],int n){
    //selection sort: find the minimum element in unsorted array and swap it with element at beginning.
    //here maximum swapping is necessary, whenever there is array, with complete opposite order of the desired order.

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printArray(arr,n);
}

void bubble_sort(int arr[],int n){
    //in bubble_sort repeatedly swap two adjacent elements, if they are in the wrong order.
    //in worst case the biggest number would be at the start while, arranging the array in ascending order.
    //in best case, it should be resolved and then only swap, should be required.
    for(int j=0;j<n;j++){
    for(int i=j;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    }
    printArray(arr,n);
}

void insertion_sort(int arr[],int n){
    //insert an element from unsorted array to its correct position in sorted array.
    //pseudo code:1. We would start from second number, considering first number as sorted array.
    //            2. We would then decide where to place second number in our sorted array, similarly for third nunber and so on..
    //            3. Observation: In the sorted array, the biggest number is one just before which we are now in the first for loop.
    //            4. Now, we would check if the number on i, is bigger than the biggest number in array, means j=i-1.
    //            5. If its not, then loop wouldn't go, if yes then as we have stored externally, the value of i's element value.
    //               we would keep the i-1 value on i or j on j+1, then so on, we would be comparing with the i value(careful not j value)
    //              , then where it stops, loop ends but due to j--(j+1), we have to replace the repeated value, present at j+1 by our original i value.
    //            6. See at last 3 values are involved, the value with which we compare just before closing the loop, the value to be changed, the value repeated now to be alone.
    //Success.

    for(int i=1;i<n;i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    printArray(arr,n);
}

int main(){
    //for declaring an array, write datatype name[size]; and then you may get elements, individually or directluy = {}.
    int array1[4];
    array1[0]=50;
    int array2[3] = {2,4,5}; //here you have to mention size.
    cout<<array2[1]<<endl;
    //For printing array,use for loop.
    //using <climits> INT_MAX is written for maximum number possible on C++. and similarly INT_MIN.
    //we can use max(a,b) for finding max numbers between a and b, and similarly min.

    //Linear Search:
    cout<<linearSearch(array2,3,5)<<endl;

    //BinarySearch
    cout<<binary_Search(array2,3,5)<<endl;
//assume k iterations,let's say in worst case, just one element left, then n/2^k = 1;means k=log2(n);
//therefore time complexity is O(log2n);
    int tosort[5]={2,6,8,3,7};
    //selection sort: find the minimum element in unsorted array and swap it with element at beginning.
    selection_sort(tosort,5);
    bubble_sort(tosort,5);
    insertion_sort(tosort,5);
return 0;} 
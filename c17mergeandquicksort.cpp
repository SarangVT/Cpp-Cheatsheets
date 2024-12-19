#include <iostream>
using namespace std;

void merge(int array[],int l,int mid,int r){
    //make 2 temp arrays
    int n1=mid-l+1;
    int n2=r-mid;

    int a[n1];
    int b[n2];

//inserted values in the temp arrays

    for(int i=0;i<n1;i++){
        a[i]=array[l+i];
    }

    for(int i=0;i<n2;i++){
        b[i]=array[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l;//for traversing length of array to be sorted.
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            array[k]=a[i];
            k++;i++;
        } else{
            array[k]=b[j];
            k++; j++;
        }
    }

    while(i<n1){
        array[k]=a[i];
        k++; i++;
    }

    while(j<n2){            
        array[k]=b[j];
        k++;j++;
    }
}

void mergeSort(int array[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(array,l,mid);
        mergeSort(array,mid+1,r);
//now merging two sorted arrays
//we are not making new arrays
        merge(array,l,mid,r);
    }
}

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
    return;
}

int main(){

//based on divide and conquer method: divides the task into so smaller parts,, thst it can be directly resolved.
//Merge Sort

    int array[]={5,4,3,2,1};
    mergeSort(array,0,4);
    for(int i=0;i<5;i++){
        cout<<array[i]<<" ";
    } cout<<endl;

/*Time Complexity: T(n) = 2T(n/2)+n //for arranging the arrays(2T(n/2)) and then sorting them completely(n) 
T(n/2)=2T(n/4)+n/2; -(i)
T(n/4)=2T(n/8)+n/4; -(ii)
.
.
.
T(1)=1
Levels: n/2^k=1
n=2^k
k=log n
Adding 1*(i)+2*(ii)+4*(iii)+...
Thus, time complexity is nlogn.
*/

//...............................................

//Quick Sort
int arr[]={1,4,2,6,3};
quickSort(arr,0,4);
for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}cout<<endl;
/*
Time Complexity: Depends on Pivot
1. Best Case: Pivot is median element.
2. In worst case, pivot would be end element.

Best Case:
T(n)=2T(n/2)+n;
T(n/2)=2T(n/4)+n/2;
.
.
T(1)=1
n/2^k=1
k=logn
Time Complexity: nlogn

Worst Case: 
T(n) = T(n-1) + n
T(n-1) = T(n-2) + n-1
.
.
T(2)=T(1)+2
Time Complexity: O(n^2).
*/

return 0;
}
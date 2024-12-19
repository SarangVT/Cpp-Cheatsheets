#include <iostream>
using namespace std;
//DNF means Dutch National Flag
//also c/s 0,1,2 sort

void swap(int arr[],int a, int b){
    int t = arr[a];
    arr[a]=arr[b];
    arr[b]=t;
}

void dnfsort(int ar[],int n){
    int low=0;
    int high=n-1;
    int mid=0;

    while(mid<=high){
        if(ar[mid]==0){
            swap(ar,low,mid);
            mid++;low++;
        } else if(ar[mid]==2){
            swap(ar,mid,high);
            high--;
        } else if(ar[mid]==1){
            mid++;
        }
    }
}
//.................................
//We are going to make a wave of local maxima and minima, such that it starts from maxima.
void waveSort(int arr[], int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr,i-1,i);
        }
        //corner cases that's why n-2,else i+1 not defined in i=n-1.
        if(arr[i+1]<arr[i] && i<=n-2){
            swap(arr,i,i+1);
        }
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
//we have 00low111mid???high22
int array[]={0,1,0,1,0,2,1,0,2,0,1};
dnfsort(array,11);
printArray(array,11);

//Time Complexity: O(N).

//.......................
int wavearray[]={3,4,5,6,6264,464,626,624,264};
waveSort(wavearray,9);
printArray(wavearray,9);

//Time Complexity: O(N).  
//(N/2 means N here).
return 0;}
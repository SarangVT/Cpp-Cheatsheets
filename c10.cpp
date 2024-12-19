#include <iostream>
using namespace std;

int main(){
// #ifndef ONLINE_JUDGE
//    freopen("input.txt","r", stdin);
//    freopen("output.txt","w",stdout);
// #endif

//2-D arrays:
//Taking input in 2-D arrays.
int n,m;
cin>>n>>m;
int arr[n][m];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
}

//Taking output of 2-D arrays.
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<arr[i][j]<<" ";
    } cout<<endl;
}

//You can search in 2-D array, using if, with time complexity O(n^2).

//Spiral Order Matrix Traversal
int row_start=0;
int row_end=n-1;
int column_start=0;
int column_end=m-1;
while(row_start<=row_end && column_start<=column_end){
    for(int col=column_start;col<=column_end;col++){
        cout<<arr[row_start][col]<<" ";
    }
    row_start++;
    for(int row=row_start;row<=row_end;row++){
        cout<<arr[row][column_end]<<" ";
    }
    column_end--;
    for(int col=column_end;col>=column_start;col--){
        cout<<arr[row_end][col]<<" ";
    }
    row_end--;
    for(int row=row_end;row>=row_start;row--){
        cout<<arr[row][column_start]<<" ";
    }
    column_start++;
}
n=3;
m=3;
int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//Transpose of a Matrix
for(int i=0;i<n;i++){
    for(int j=i;j<m;j++){
        int temp = a[i][j];
        a[i][j]=a[j][i];
        a[j][i] = temp;
    }
}

//Matrix Multiplication:
//declare n1,n2,n3
//input m1[n1][n2] and m2[n2][n3] two 2-D arrays.

// int x[n1][n3];
// for(int i=0;i<n1;i++){
//     for(int j=0;j<n3;j++){
//         x[i][j]=0;
//     }
// }

// for(int i=0;i<n1;i++){
//     for(int j=0;j<n3;j++){
//         for(int k=0;k<n2;k++){
//             x[i][j]+= m1[i][k]*m2[k][j];
//         }
//     }
// }

//Matrix Search...............................
//(If matrix is sorted in ascending manner.)
// int i=0;
// int j=m-1;
// bool found=false;
// while(i<n && j>=0){
//     if(mat[i][j]==q){
//         found = true;
//         break;
//     } else if(mat[i][j]>q){
//         j--;
//     } else if(mat[i][j]<q){
//         i++;
//     }
// }
// if(found==true){cout<<"found"<<endl;}
// else{cout<<"Not found"<<endl;}

return 0;}

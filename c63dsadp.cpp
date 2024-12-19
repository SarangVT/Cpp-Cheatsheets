#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define vii <vector<pair<int,int>>

int kadane(int arr[],int n){
    int curr=0, maxTillNow=0;
    fl(i,0,n){
        if(curr+arr[i]<0){
            curr=0;
        }else{
            curr+=arr[i];
            maxTillNow=max(maxTillNow,curr);
        }
    }
    return maxTillNow;
}

int main(){
/*Given an array of items with their weight and value. Find the maximum value of items that can be stolen using a knapsack of capacity W. Note: You can choose infinte items of each type.*/

int n=5, W=11;
vi wt={3,2,4,5,1};
vi val={4,3,5,6,1};
vi dp(W+1,0);

fl(j,0,W+1){
    fl(i,0,n){
        if(j-wt[i]>=0){
            dp[j]=max(dp[j],val[i]+dp[j-wt[i]]);
        }
    }
}
cout<<dp[W]<<endl;

int kadaneArr[]={-5,-1,5,-3,-1,2,3,-6};
cout<<kadane(kadaneArr,8)<<endl;

/*Problem: Given an array of n numbers. Find the maximum length of bitonic subsequence. A subsequence is bitonic if it is first strictly increasing and then strictly decreasing or entirely increasing or decreasing.*/
n=8;
vi a={1,11,2,10,4,5,2,1};
vi forward(n,1), backward(n,1);
fl(i,0,n){
    fl(j,0,i){
        if(a[i]>a[j]){
            forward[i]=max(forward[i],1+forward[j]);
        }
    }
}

for(int i=n-1;i>=0;i--){
    for(int j=n-1;j>i;j--){
        if(a[i]>a[j]){
            backward[i]=max(backward[i],1+backward[j]);
        }
    }
}

int ans=0;
fl(i,0,n){
    ans=max(ans,forward[i]+backward[i]-1);
}
cout<<ans<<endl;
return 0;}
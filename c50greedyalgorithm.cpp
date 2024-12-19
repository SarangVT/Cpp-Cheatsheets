#include "bits/stdc++.h"
using namespace std;

/*
Markov Process: Proccesses which depends only on previous state.
Generally, sorting is done first while applying greedy tehnique.
Sometimes, we do not realize that we are greedy because it comes from inside.
Indian Denomination Change Problem: You are given an array of denominations and a value X. You need to find the minimum number of coins required to make value X.
*/

int denominationRequired(vector<int> &d,int numRequired){
    sort(d.begin(),d.end(),greater<int>());
    int count=0;
    for(int i=0;i<d.size();i++){
        int toDeduct = (numRequired/d[i])*d[i];
        count+=(numRequired/d[i]);
        numRequired-=toDeduct;
    }
    return count;
    }

/*
Activity Selection Problem:
You are given n activities with their start and finish times. Select the maximum number of times that can be performed by a single person,
assuming that a person can only work on a single activity at a time.
*/

void maxActivities(vector<vector<int>> &v){
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){return a[1] < b[1];});
    int take = 1;
    int end = v[0][1];

    for(int i=1;i<v.size();i++){
        if(v[i][0] >= end){
            take++;
            end = v[i][1];
        }
    }
    cout<<take<<endl;
}

/*
Knapsack Problem: We are gien 'n' items with {weight,value} of each item and the capacity of knapsack(Sack) 'W'.
We need to put these items in knapsack such that final value of items in knapsack is maximum.
Think greedily, sort descending
*/

double knapsack(vector<pair<int,int>> v, int knapsackSize){
    sort(v.begin(),v.end(),[&](pair<int,int> &a,pair<int,int> &b){return (b.first/b.second) < (a.first/a.second);});
    int i=0;
    double price=0;
    while(knapsackSize>0 && v.size()>i){
        double pricePerObj=v[i].first/v[i].second;
        if(knapsackSize>=v[i].second){
            knapsackSize-=v[i].second;
            price+=v[i].first;
            v[i].second=0;
            i++;
            continue;
        }
        else{
            price+=knapsackSize*pricePerObj;
            break;
        }
    }
    return price;
}


/*You are given n files with their computation times. Choose any two files, add their computation times and append it to the list of computation times.
{Cost = Sum of computation time.} Do it until we are left with only one file.
Push all elements to a minheap, take top 2 elements one by one and add the cost to the answer. Push the merged file to the minheap. When single element remains, output the cost.
*/

int optimalMergePattern(priority_queue<int,vector<int>,greater<int>> v){
    int cost=0;
    while(v.size()>1){
        int temp=v.top();
        v.pop();
        temp+=v.top();v.pop();
        v.push(temp);
        cost+=temp;
    }
    return cost;
}

/*Expedition: A group of cows grabbed a truck and ventured on an expedition. The truck leaves one unit of fuel every unit of distance it travels.
To repair the truck, the cows need to drive to the nearest town (no more than 10^6 units distance).
On this road, between the town and the current location, there are N(1<=N<=10^5) fuel stops where the cows can stop to acquire additional fuel(1-100 units at each stop).
The cows want to make the minimum possible number of stops for fuels on the way to town. Capacity of the tank is sufficiently large to hold any amount of fuel.
Intial units of fuel: P(1<=P<=10^6)
Intial distance from town: L
Determine the minimum number of stops to reach the town.

Answer:
Create a maxHeap, which stores the fuels available at the stops that we have traversed.
Sort the stops on the basis of distance of stops from intial position of truck.
Keep iterating on the stops, and whenever fuel in the truck becomes empty, take the fuel from the maxHeap and add it.
Maintain the count of stops from which we have taken fuel.
*/

int expedition(int n){
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }

    int l,p;
    cin>>l>>p;

    for(int i=0;i<n;i++){
        a[i].first=l-a[i].first;
    }
    //Sorted according to a[i].first by default in ascending order.
    sort(a.begin(),a.end());
    //Number of fuel posts.
    int ans=0;
    //Current fuel=p;
    int curr=p;

    bool impossible=0;
    priority_queue<int,vector<int>> pq;
    for(int i=0;i<n;i++){
        //If fuel becomes more than total units, break.
        if(curr>=l){
            break;
        }

        //Whenever fuel is less, check for the not used biggest fuel posts, until current fuel becomes bigger.
        //Here we are just adding fuel from fuels, traversing till last fuel post not further than that to town
        while(curr < a[i].first){
            //if left posts are none, then its impossible...
            if(pq.empty()){
                impossible=1;
                break;
            }
            //else increment the used posts numbers
            ans++;
            //add fuel to tank
            curr+=pq.top();
            //delete the fuel post, from not used
            pq.pop();
        }
        //if found impossible, no further game required, shut it down.
        if(impossible) break;

        //everytime push, the fuel tank in the maxHeap, to consider it for future.
        pq.push(a[i].second);
    }

    //return -1 if it is not possible
    if(impossible){return -1;};

    //now traverse till town, no tension if current fuel is more than required, but if than fuel up till you get more than required
    while(!pq.empty() && curr < l){
        curr += pq.top();
        pq.pop();
        ans++;
    }
    //still less fuel then it is not possible
    if(curr<l){
        return -1;
    }
    //if fuel is more then return the required posts.
    return ans;
}

/*
Given an array of n elements, we have to remove exactly n/2 elements from array A and add it to another array B (intially empty).
Find the maximum and minimum values of diferences between these two arrays. 
We define the difference between these two arrays as: Summation of (abs(A[i]-B[i]))
1<=n<=10^5
Ai<=10^9
*/
void maxAndMinDifferenceInArray(vector<int> v){
    sort(v.begin(),v.end());
    int max=0,min=0;
    for(int i=0;i<v.size()/2;i++){
        min+=(v[2*i+1]-v[2*i]);
        //subtraction of odd and even terms
        max+=(v[v.size()-i-1]-v[i]);
        //may also writev[i+n/2] as actually left half is getting subtracted from right half
    }
    cout<<min<<" "<<max<<endl;
}


int main(){
    vector<int> d = {1,2,5,10,50,100,200,500,2000};
    int x = 350;
    cout<<denominationRequired(d,x)<<endl;
    vector<vector<int>> e;
    e.push_back({10,20});
    e.push_back({12,15});
    e.push_back({20,30});
    maxActivities(e);
    vector<pair<int,int>> f;
    f.push_back(make_pair(21,7));
    f.push_back(make_pair(24,4));
    f.push_back(make_pair(12,6));
    f.push_back(make_pair(40,5));
    f.push_back(make_pair(30,6));

    priority_queue<int,vector<int>,greater<int>> q;
    q.push(5);q.push(2);q.push(4);q.push(7);
    cout<<knapsack(f,20)<<endl<<optimalMergePattern(q)<<endl;

    vector<int> s = {12,-3,10,0};
    maxAndMinDifferenceInArray(s);
    cout<<expedition(4)<<endl;
return 0;}
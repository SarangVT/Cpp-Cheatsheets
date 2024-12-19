#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

#define vi vector<int>
#define pli pair<int,int>
#define vli vector<pli>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
/*in stl heaps are implemented by maxHeap
MaxHeap: priority-queue<int,vector<int>>
MinHeap: priority-queue<int,vector<int>,greater<int>>
push: O(log(N))
pop: O(log(N))
top: O(1)
size: O(1)
*/

priority_queue<int,vi> pqmax;
priority_queue<int,vi,greater<int>> pqmin;
//see we are taking advantage of auto-sorting in heap,make bigger numbers in minHeap and smaller in maxHeap
//so check if its, less than top of minHeap then, directly insert in maxHeap, else manipulate and ultimately it will sort.

void insert(int x){
    if(pqmin.size()==pqmax.size()){
        //edge case when intially sizes are 0.
        if(pqmax.size()==0){
            pqmax.push(x);
            return;
        }
        if(x<pqmax.top()){
            pqmax.push(x);
        }
        else{
            pqmin.push(x);
        }
    }
    //we are never letting their size difference greater than 1.
    else{
        if(pqmax.size()>pqmin.size()){
            if(x>pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp=pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
       if(pqmin.size()>pqmax.size()){
            if(x<pqmin.top()){
                pqmax.push(x);
            }else{
                int temp=pqmin.top();
                pqmin.pop();
                pqmin.push(x);
                pqmax.push(temp);
            }
        }
    }
 
}

double findMedian(){
    if(pqmin.size()==pqmax.size()){
        return (pqmin.top()+pqmax.top())/2.0;
    }
    else if(pqmax.size()>pqmin.size()){
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }
}

int main(){
    priority_queue<int,vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);
    cout<<pq.top()<<endl; //3
    pq.pop();
    cout<<pq.top()<<endl; //2

    priority_queue<int,vector<int>,greater<int>> pqm;
    pqm.push(3);
    pqm.push(1);
    pqm.push(2);
    cout<<pqm.top()<<endl;
    pqm.pop();
    cout<<pqm.top()<<endl;

/*Median of running stream:
You would be given an array, and each element comes in new array stepwise. Each time calculate new median of array.
Brute Force: Sort the array(nlog(n)) time, and then quote the median, n^2*log(N).
Optimal Approach: Using max and minheap. Partition the array into two parts.
*/
    insert(10);
    cout<<findMedian()<<endl;
    insert(15);
    cout<<findMedian()<<endl;
    insert(21);
    cout<<findMedian()<<endl;
    insert(30);
    cout<<findMedian()<<endl;
    insert(18);
    cout<<findMedian()<<endl;
    insert(19);
    cout<<findMedian()<<endl;


//................................................................


/*To find a smallest subsequence with minimum sum K.
1. Keep a maxheap and insert all the elements.
2. Keep popping the elements and keep adding them to a variable sum and maintain cnt(current).
3. When sum>=k, then quote the answer(cnt).
*/
//here h is the highest sum
int n;int h;
cin>>n>>h;
vi b(n);
rep(i,0,n)
    cin>>b[i];

priority_queue<int,vi> q;
rep(i,0,n)
    q.push(b[i]);

int sum=0;
int cnt=0;

while(!q.empty()){
    sum+=q.top();
    q.pop();
    cnt++;
    if(sum>=h){
        break;
    }
}
if(sum<h){
    cout<<"-1"<<endl;
}
else{
    cout<<"Length of subsequence is: "<<cnt<<endl;
}


//................................................................


/*Merge K-sorted arrays:
Brute Force: 
1. Take 2 sorted arrays and merge them, repeat this process until we are left with one array.
Optimal Approach:
1. Create a min heap of pairs. Pair->{value,array number}
2. Insert {first element, array number} of all the sorted array into minHeap.
3. Main Idea: We will pp elements form the min Heap and store into the answer array. Insert the next element of the sorted array into minHeap.
4. We also need to keep track of the indices of the elements.

*/
//number of arrays to sort
int k;
cin>>k;
//2-D vectors.

//taking input...
vector<vector<int>> a(k);
rep(i,0,k){
    //size of each array
    int size;
    cin>>size;
    a[i]=vector<int>(size);
    rep(j,0,size){
        cin>>a[i][j];
    }
}

vector<int> idx(k,0);
//storing data of idx of which element is gone in which array, intialized by 0, as its the first index.
priority_queue<pli,vector<pli>,greater<pli>>p;
rep(i,0,k){
    p.push({a[i][0],i});
}
vi ans;
//in it every time one element of each will be in min heap.
while(!p.empty()){
    pli x = p.top();
    p.pop();
    ans.push_back(x.ff);
//due to 0-indexing +1, check if the array size is greater than curr idx.
    if(idx[x.ss]+1<a[x.ss].size()){
        p.push({a[x.ss][idx[x.ss]+1],x.ss});
    }
    //to take the element from next array
    idx[x.ss]+=1;
}

rep(i,0,ans.size()){
    cout<<ans[i]<<" ";
}
//input first number of arrays to sort
//then array size along with elements in sorted order followed by same with second
cout<<endl;
return 0;}
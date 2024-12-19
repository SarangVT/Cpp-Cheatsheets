#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}

int main(){
//vector<datatype> name;
vector<int> v;
//adding elements in a vector
v.push_back(1);
v.push_back(2);
v.push_back(3);

//Precaution: If you specify the size of vector<int> a(7) it converts to array, and then all the times you do v.push_back it doesn't inserts.

v.pop_back(); //removes last element
//for printing all values of vector, v.size() gives size of vector
for(int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
}

vector<int>::iterator it;
for(it=v.begin();it!=v.end();it++){
    cout<<*it<<endl;
}

for(auto elem:v){
    cout<<elem<<endl;
}

vector<int> v2 (3,10);
//here there is a vector with size 3 and all values equal to 10.
//for assigning values of v to v2 and v2 to v.
swap(v,v2);
for(auto el:v){
    cout<<el<<endl;
}
vector<int> v3= {1,20,13,4};

sort(v3.begin(),v3.end());

//std::pair
pair<int,char> pair1;
pair1.first = 3;
pair1.second = 's';

/*for converting:
main
10 16 7 14 5 3 12 9
0  1  2 3  4 5 6 7
ans
4 7 2 6 1 0 5 3
0 1 2 3 4 5 6 7
intermediate
3 5 7 9 10 12 14 16
5 4 2 7  0  6  3  1
*/

int arr[]={10,16,7,14,5,3,12,9};
vector<pair<int,int> > t;

for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
    // pair<int,int> p;
    // p.first = arr[i];
    // p.second=i;
    t.push_back(make_pair(arr[i],i));
}
    sort(t.begin(),t.end(),myCompare);
    for(int i=0;i<t.size();i++){
        arr[t[i].second]=i;
    }
    

for(int i=0;i<t.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
return 0;}

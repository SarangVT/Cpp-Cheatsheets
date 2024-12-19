/*Time Complexity: O(S+T)
Based on string hashing.
p^i*hash[i..j] = hash[0..j] - hash[0...i-1]
j-i+1 = S //string length
if(hash[i...j]==S){
    -->occurence is found at index i
    -->hash[i..j] = (1/p^i)*(hash[0..j]-hash[o..i-1])
    -->p^i*hash(s) must be equal to hash[o...j] - hash[0...i-1]
}
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>
int p=31;
const int N=1e5+7, m = 1e9+7;
vector<long long> power(N);

int main(){
    string s = "cab";
    string t="abcabcabcd";
    int T=t.size(), S=s.size();
    power[0]=1;
    fl(i,1,N){
        power[i]=(power[i-1]*p)%m;
    }
    vector<long long> h(T+1,0);
    //(Caution: 1st el is empty), We are storing the sum of all the hashes till that index of the main string t.
    fl(i,0,T){
        h[i+1] = (h[i]+(t[i]-'a'+1)*power[i])%m;
    }
    //We are calculating the total hash value of the substring s.
    long long h_s=0;
    fl(i,0,S){
        h_s = (h_s+(s[i]-'a'+1)*power[i])%m;
    }
    for(int i=0;i+S-1<T;i++){
        //h[i]=0, as h starts filling from 1.
        long long cur_h = (h[i+S]-h[i]+m)%m;
        //If hash matches then, it is same string, as hashing doesn't allow duplication 31>26.
        if(cur_h==(h_s*power[i])%m){
            cout<<"Found at index: "<<i<<endl;
        }
    }
return 0;}
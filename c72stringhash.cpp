/*  String Hash:
    Hash Function: String --> Unique Hash
    To find: Number of unique strings in vector.
    
    To compare two strings, O(m) time is needed, where m is lebgth of string.
    Brute Force: Sort: O(nmlog(n)) + Checking if they are different strings, O(nm).
    
    Hashing:
    Time taken to compare hashes will be: O(1) as time taken to compare two integers is O(1).
    So, overall Time Complexity is O(nlog(n)+nm).
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
const int N=1e5+3, m = 1e9+7;
int p=31;
vector<long long> powers(N);

long long calculateHash(string s){
    long long hash=0;
    fl(i,0,s.size()){
        hash+=(s[i]-'a'+1)*powers[i];
    }
    return hash;
}

int main(){
    powers[0]=1;
    fl(i,0,N){
        powers[i]=(powers[i-1]*p)%m;
    }
    vector<string> strings ={"aa","ab","aa","b","cc","aa"};
    vector<long long> hashes;
    for(auto w:strings){
        hashes.push_back(calculateHash(w));
    }
    sort(hashes.begin(),hashes.end());
    int distinct=0;
    fl(i,0,hashes.size()){
        if(i==0 or hashes[i]!=hashes[i-1]){
            distinct++;
        }
    }
    cout<<distinct<<"\n";
    

/*substr(size_t pos=0, size_t len=npos);
Returns the string that starts at character position pos and spans len characters (or until the end of the string, whichever comes first.)
*/

    string t = "sarang";
    string s = "a";
    int S = s.size(), T=t.size();
    fl(i,0,T-S+1){
        if(t.substr(i,S)==s){
            cout<<"Found at index: "<<i<<"\n";
        }
    }
    //Time Complexity: O(ST)
return 0;}
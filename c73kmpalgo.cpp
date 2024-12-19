#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>

/*KMP(Knuth-Morris-Pratt) Algorithm: Calculate the indices of the occurence of string s in t.
Prefix Function: prefix[i] is the longest of the longest proper prefix of the substring s[0..i] which is also a suffix of this substring. By definition, prefix[0]=0
prefix[i] = maximum k such that
s[0...k-1] = s[i-(k-1)....i]
Time Complexity: O(S+T)
*/
vi prefix_function(string s){
    int n=s.size();
    vi pi(n,0);
    fl(i,1,n){
        //Here j represents index in left to be checked in current iteration, and i index in right.
        int j=pi[i-1];
        //If we didn't get the match we would go backwards to match, until we get the match.
        while(j>0 and s[i]!=s[j]){
            j=pi[j-1];
        }
        
        //a...a
        //ab...ab
        //abc...abc
        //If we get the match we would increment.
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}
//Time Complexity: O(N), not O(N^2)

int main(){
    string t = "abcabcd";
    string s="cab";
    vi prefix=prefix_function(t);
    for(auto i: prefix){
        cout<<i<<" ";
    }cout<<endl;
    int pos=-1;
    int i(0), j(0);

    //t--> main string, s--> substring

    while(i<t.size()){
        //If the letter to be matched, matches then increment both indices
        //j is keeping track of matched substring
        if(t[i]==s[j]){
            j++;i++;
        }
        else{
            //if it doesn't match, go backwards and try to match
            if(j!=0) j=prefix[j-1];
            else i++;
        }
        //once it matches complete substring, store its start index in pos and come out of loop.
        if(j==s.size()){
            pos = i-s.size();
            break;
        }
    }
    //Gives the start index of substring.
    cout<<pos<<endl;

    //gist: whenever mismatch occurs, the prefix function knows that the string we have matched till before the index where mismatch occurs, 
    //is how much similar or how much letters are already matching if we even take from that index, this allows us not to go backwards completely each time, if further mismatch occurs it again pushes us backwards, in the matching.
return 0;}
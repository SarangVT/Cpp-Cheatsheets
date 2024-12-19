#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define fl(i,a,b) for(int i=a;i<b;i++)
#define flb(i,a,b) for(int i=a;i>=b;i--)
#define vii <vector<pair<int,int>>

int main(){

return 0;}

/*Problem:
Neha has a digital dictionary. It has an input field in which one can search any string and the dictionary displays all the words whose prefix is thst input string in lexicographical order.
Now you are given a task to make your own digital dictionary. You will be given words that you can store in your database and then you need to design the search functionality. 
And if no such words are available for a given search word, add this word to your dictionary.

Input: N, No of words to be stored in database
Q: Number of queries
Q: Number of lines describing the query string on each line given by user.

We will create a Trie and store all the words that are in the dict. Now, in queries we need to just check the words which have prefix same as given in input. And then we need to use DFS for getting all the possibilities of words.

*/

class node{
    public:
    node* next[26];
    bool end;
    node(){
        fl(i,0,26){
            next[i]=NULL;
        }
        end=false;
    }
};

class Trie{
    private:
        node* root;
    public:
    Trie(){root=new node();}
    void insert(string &s){
        node* it=root;
        for(auto c: s){
            if(!it->next[c-'a']){
                it->next[c-'a'] = new node();
            }
            it=it->next[c-'a'];
        }
        it->end=true;
    }
    void find(string &s){
        node* it=root;
        //If word is not present, then insert it.
        for(auto c: s){
            if(!it->next[c-'a']){
                cout<<"No Suggestion"<<endl;
                insert(s);
                return;
            }
        }
        vector<string> res;
        printall(it,s,res,"");
        for(auto c:res){
            cout<<s<<" "<<c<<endl;
        }
    }

    void printall(node* it, string &s, vector<string> &res, string cur){
        if(it==NULL) return;
        if(it->end) res.push_back(cur);
        fl(i,0,26){
            if(it->next[i]){
                printall(it->next[i],s,res,cur+char('a'+i));
            }
        }
    }
};

int main(){
    Trie t;
    int n=4;
    vector<string> a={"pet","peter","rat","rack"};
    fl(i,0,n){t.insert(a[i]);}
    vector<string> s={"pe","pet","r","rac","rat"};
    int q=5;
    while(q--){
        cout<<"Suggestions for: "<<s[q]<<endl;
        t.find(s[4-q]);
        cout<<endl;
    }
return 0;}

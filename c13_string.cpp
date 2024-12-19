#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    /*Character arrays: Need to know size beforehand.
Larger size required for operations(concatenate or append).
No terminating extra character.

Strings: No need to know size beforehand.
Performing operations like concatenation and append is easier.
Terminated with a special character '\0'.
*/

//string str;
// cin>>str;
//getLine(cin,str); this would allow you to get the complete line.
// cout<<str;

string str1(5,'n');
cout<<str1<<endl;

string str2 = "SarangThakare";
//Different functions in string.

string s1 = "fam";
string s2 = "ily";
cout<<s1+s2<<endl; //here none of string changes.
s1.append(s2); //method-2: s1 = s1+s2
cout<<s1<<endl;//here s2 is appended in s1, and s1 is changed.
cout<<s1[0]<<endl; //string have 0 based indexing

s2.clear();
cout<<s2<<endl;
if(s2.empty()){
    cout<<"s2 is empty"<<endl;
}

string x ="abc";
string y="abc";
string z="def";
if(x.compare(y)==0){
    cout<<"Strings x and y are equal"<<endl;
}

if(x.compare(z)==-1){
    cout<<"Strings x and z are not equal"<<endl;
}
//compare function here gives output 0, if strings are equal, and -1 if they are not equal.
string phone = "GalaxyA35";
phone.erase(6,3); //here in erase function the arguments are the index from where the deletion starts and how many characters are to be deleted.
cout<<phone<<endl;

cout<<phone.find("ax")<<endl; //it returns the first index, where it finds it.
phone.insert(6,"F14");
cout<<phone<<endl;

cout<<phone.length()<<endl; //remember here () is there as length is a function.

string model = phone.substr(6,3);//(index from where substring is to be extracted, number of characters to be extracted).
cout<<model<<endl;
string num ="123";
int newnum = stoi(num);
cout<<newnum+2<<endl;

int d = 456;
cout<<to_string(d)+"7"<<endl;
string name = "Sarang";
sort(name.begin(),name.end());
cout<<name<<endl;
//it is sorted lexicographically.

string nam="Sarang";
cout<<'s'-'S'<<endl; //32
//therefore there is difference of 32 in ASCII value, between lower and upper case.
//for converting to uppercase
for(int i=1;i<nam.size();i++){
    if(nam[i]>='a' && nam[i]<='z'){
        nam[i]-=32;
    }
}
cout<<nam<<endl;
//for converting to lowercase
for(int i=0;i<nam.length();i++){
    if(nam[i]>='A' && nam[i]<='Z'){
        nam[i]+=32;
    }
}
cout<<nam<<endl;
//inbuilt functions
transform(nam.begin(),nam.end(),nam.begin(),::toupper);
//here arguments are (beginning iterator,ending iterator, from where to start capitalizing,operation)
//here this first two arguments are to take into action, not to perform action.
cout<<nam<<endl;
transform(nam.begin(),nam.end(),nam.begin(),::tolower);
cout<<nam<<endl;

string gnum = "23983";
sort(gnum.begin(),gnum.end(),greater<int>());
cout<<gnum<<endl;
//find the letter with max frequency.
string ar= "dfhkjghdkf";
int freq[26];
for(int i=0;i<26;i++){
    freq[i]=0;
}

for(int i=0;i<ar.length();i++){
    freq[ar[i]-'a']+=1;
}
int curr=0;
int ans=0;
for(int i=0;i<26;i++){
    curr=freq[i];
    ans =max(ans,curr);
}
cout<<ans<<endl;





return 0;}
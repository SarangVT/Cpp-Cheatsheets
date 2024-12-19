#include <iostream>
#include <stack>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

void insertAtBottom(stack <int> &st, int el){
    if(st.empty()){
        st.push(el);
        return;
    }
    int topel=st.top();
    st.pop();
    insertAtBottom(st,el);
    st.push(topel);
    //here we are storing all our original stack elements in callstack and then by base case we are adding the el.
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int el=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,el);
}

int main(){
    string s="This is a reversed sentence.";
    reverseSentence(s);

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;

return 0;}
#include <iostream>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

int postFixEvaluation(string s){
    //assuming string has only one digit operand
    stack<int>st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
            //subtracting any character(originally number) from 0 gives its int value.
        }else{
            //it is written first op2 then op1, as in stack we require opposite here.
            
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();

            switch(s[i]){
                case '+':
                st.push(op1+op2);
                break;
                case '-':
                st.push(op1-op2);
                break;
                case '*':
                st.push(op1*op2);
                break;
                case '/':
                st.push(op1/op2);
                break;
                case '^':
                st.push(pow(op1,op2));//gives op1^op2(2^3=8)
                break;
                default:
                break;
            }
        }
    }
    return st.top();
}

int preFixEvaluation(string s){
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        } else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch(s[i]){
                case '+':
                st.push(op1+op2);
                break;
                case '-':
                st.push(op1-op2);
                break;
                case '*':
                st.push(op1*op2);
                break;
                case '/':
                st.push(op1/op2);
                break;
                case '^':
                st.push(pow(op1,op2));
                break;
                default:
                break;
            }
        }
    }
    return st.top();
}

int prec(char c){
    if(c=='^'){
        return 3;
    } else if(c=='*' || c=='/'){
        return 2;
    }else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infinixtoPostFix(string s){
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        } else if(s[i]=='('){
            st.push(s[i]);
        } else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        } else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}

string infinixtoPreFix(string s){
    reverse(s.begin(),s.end()); //require algo file
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                 res+=st.top();
                 st.pop();
            }
            //to remove bracket from stack
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

bool checkbalanceparenthesis(string s){
    int n=s.size();
    stack<char>st;
    bool ans=true;
    for(int i=0;i<n;i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            st.push(s[i]);
        } else if(!st.empty() && s[i]==')'){
            if(st.top()=='('){
                st.pop();
            }
        }else if(!st.empty() && s[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
        }else if(!st.empty() && s[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
        } else{
            return false;
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}

int main(){
/*Infinix Expressions: <operand> <operator> <operand>
Precedence: 1.(),{}, []
2.^ (Power)
3.*,/
4. +,-
If same preferred operators, come, then associativity comes, priority is given to sign in left, except ^(exponentiation(2^3^5)).
*/
//Time Complexity: O(l), l is length of larger string
cout<<postFixEvaluation("46+2/5*7+")<<endl;
cout<<preFixEvaluation("-+7*45+20")<<endl;
cout<<infinixtoPostFix("(a-b/c)*(a/k-l)")<<endl;
cout<<infinixtoPreFix("(a-b/c)*(a/k-l)")<<endl;
/*balanced parenthesis: {[()]}
unbalanced parenthesis: [{()]}
*/

cout<<checkbalanceparenthesis("{[()]}")<<endl;
string x="{[()}]";
cout<<checkbalanceparenthesis(x)<<endl;
return 0;}
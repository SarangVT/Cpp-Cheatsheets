#include "bits/stdc++.h"
using namespace std;
//Given histogram, width 1 of each bar, and we have to find maximum area inscribed in it.by a rectangle continuous.
int largestRectangleBruteForce(int arr[],int n){
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int minh=arr[i];
        for(int j=i;j<n;j++){
            minh=min(arr[j],minh);
            int len=j-i+1;
            ans=max(ans,len*minh);
        }
    }
    return ans;
}

int getMaxArea(vector<int> a) {
    int n=a.size(),ans=0,i=0;
    stack<int> st;
    a.push_back(0);
    while(i<n){
        //checking whether stack's bar is bigger than current bar, if its, then count the possible areas.
        while(!st.empty() and a[st.top()] > a[i]){
            int t=st.top();
            int h=a[t];
            st.pop();
            if(st.empty()){
                ans=max(ans,h*i);
            }
            else{
                //-1 as st.top() is decremented by 1 in start of while loop, i is index of the bar which is shorter than previous one.
                int len=i-st.top()-1;
                ans=max(ans,h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

//Given non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
int getWaterHarvest(vector<int> a){
    int ans=0, n=a.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        //calculating the rain water in the gap, whenever there is increase in height, as
        while(!st.empty() and a[st.top()] < a[i]){
            int cur=st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff=i-st.top()-1;
            ans+=(min(a[st.top()],a[i]) - a[cur]) * diff;
        }
        st.push(i);
    }
    return ans;
}

bool redundantParenthesis(string s){
    stack<char> st;
    int ans=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='('){
            st.push(s[i]);
        }
        else if (s[i]==')'){
            if(st.empty()){
                return 1;
            }  
            else{
                if(st.top()=='('){
                    return 1;
                }
                else{
                    while(st.top()!='('){
                        st.pop();
                    }
                    st.pop();
                }
            }
        }
    }
    if(st.empty()){ return 0;}
    else{return 1;}
}

vector<int> stockSpan(vector<int> prices){
    //Span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price. Find the span of the stocks for all the days.
    //Brute Force: for loop from i=0 to i=n, then nested for from j=i to j=0 and break wherever it is not less.
    //Optimised Approach:
    vector<int>ans;
    stack<pair<int,int>> pd;
    for(auto price: prices){
        int j=1;
        while(!pd.empty() and pd.top().first<=price){
            j+=pd.top().second;
            pd.pop();
        };
        pd.push(make_pair(price,j));
        ans.push_back(pd.top().second);
    }

    return ans;
}

//Given an array and a value, find if there exists three numbers whose sum is equal to the given value.
//Brute Force: Time Complexity: O(N^3)
bool threeSumBF(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==target){
                    return true;
                }
            }
        }
    }
}

//Optimised Approach: Time Complexity(O(O(NlogN) intersection O(N^2))= O(N^2)
//NlogN of sorting the array.

bool threeSum(vector<int> a,int n,int target){
    bool found=false;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int lo=i+1, hi= n-1;
        while(lo<hi){
            int current = a[i]+a[lo]+a[hi];
            if(current==target){
                found=true;
            }
            if(current < target){
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    if(found==true){
        return true;
    }
    else{
        return false;
    }
}

int lengthofMaxConsecutiveOnes(vector<int> a,int k){
    int zerocnt=0, i=0, ans=0;
    for(int j=0;j<a.size();j++){
        if(a[j]==0){
            zerocnt++;
        }
        while(zerocnt>k){
            if(a[i]==0){
                zerocnt--;
            }
            i++;
        }
        ans=max(ans,j-i+1);
    }
    return ans;
}

void longestSubstringWithoutRepeatingCharacter(string s){
    vector<int> dict(256,-1);
    //vector's size=256 and is intialized each time by -1.
    int maxLength=0, start=-1;
    for(int i=0;i<s.size();i++){
        if(dict[s[i]]>start){
            //assigning the previous occurrence
            start=dict[s[i]];
        }
        //we are storing the index of occurrence of a character
        dict[s[i]]=i;
        maxLength=max(maxLength,i-start);
    }
    cout<<maxLength<<endl;
}

int main(){
    int a[6]={2,1,5,6,2,3};
    cout<<largestRectangleBruteForce(a,6)<<endl;
    vector<int> b={2,1,5,6,2,3};
    cout<<getMaxArea(b)<<endl;
    vector<int> water={0,1,0,3,1,0,1,2,3,1,2,1};
    cout<<getWaterHarvest(water)<<endl;
    cout<<redundantParenthesis("(a+(a+b))")<<endl;
    cout<<redundantParenthesis("((a+b))")<<endl;
    vector<int> priceChart={100,80,60,70,60,75,85};
    vector<int> ans=stockSpan(priceChart);
    for(auto el: ans){
        cout<<el<<" ";
    }cout<<endl;
    cout<<endl;
    vector<int> threeSumPointer={1,2,3,7,1,6,9};
    cout<<threeSum(threeSumPointer,6,5)<<endl;
    cout<<threeSum(threeSumPointer,6,24)<<endl;

    vector<int> oneandzero={1,1,1,0,0,0,1,1,1,1,0};
    cout<<lengthofMaxConsecutiveOnes(oneandzero,2)<<endl;
    longestSubstringWithoutRepeatingCharacter("abcaghjuk");
return 0;}
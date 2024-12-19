#include "bits/stdc++.h"
using namespace std;

int main(){
    vector<int> w = {-90,-3,1,2,4};
    cout<<lower_bound(w.begin(),w.end(),-90)-w.begin();
return 0;}
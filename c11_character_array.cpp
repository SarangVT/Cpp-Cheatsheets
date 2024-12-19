#include <iostream>
using namespace std;

int main(){
//Character arrays: char arr[n+1]
//This +1 due to '/0', for null character.

    char arr[100]="Jaguar";
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    if(arr[19]=='\0'){
        cout<<"All elements except assigned are null.";
    }
    cout<<endl;
    int i=0;
    while(arr[i]!='\0'){
        cout<<arr[i]<<" ";
        i++;
    }
    //so loop ends where we founded null character.
    
//Check palindrome:
int check=1;
char a[6]="nitin";
int n=5;
    for(int i=0;i<n;i++){
        if(a[i]!=a[n-1-i]){
            check=0;
            break;
        }
    }
if(check==1){
cout<<endl<<"It is a palindrome."<<endl;
}
else{cout<<"It is not a palindrome."<<endl;}

char sen[30] = "It is the largest game ever.";
int maxlength=-1;
int curr=0;
for(int i=0;i<30;i++){
    if(sen[i]!='\0' && sen[i]!=' '){
        curr++;
    }
    maxlength=max(curr,maxlength);
    if(sen[i]==' '){
        curr=0;
    }
    if(sen[i]=='\0'){
        break;
    }
}
cout<<maxlength<<endl;

//cin usually starts a different cin, when we apply space, but if we use cin.getLine()
/*int n;
cin>>n;
cin.ignore();
char arr[n+1];
cin.getLine(arr,n);
cin.ignore();
*/


return 0;}
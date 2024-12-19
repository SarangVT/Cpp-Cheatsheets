#include <iostream>
#include<string>
using namespace std;

void reverseString(string str){
    if(str.length()==0){
        return;
    }
    string ros=str.substr(1);
    reverseString(ros);
    cout<< str[0];
}

void replace(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replace(s.substr(2));
    } else{
        cout<<s[0];
        replace(s.substr(1));
    }
}

void towerOfHanoi(int n,char src,char dest,char help){
    if(n==0){return;}
    towerOfHanoi(n-1,src,help,dest); 
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,help,dest,src);
}

string removeDuplicates(string s){
    if(s.length()==0){return "";}
    char ch=s[0];
    string ans = removeDuplicates(string(s.substr(1)));
    for(int i=0;i<ans.length();i++){
        if(ch==ans[i]){
        ans.erase(i,1);}
    }
    return ch+ans;
}

string moveX(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans = moveX(s.substr(1));
    if(ch=='x'){
        return ans+ch;
    } else{return ch+ans;}
}

void printsubseq(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string ros =s.substr(1);
    //either take or not take that letter to ans.
    printsubseq(ros,ans);
    printsubseq(ros,ans+ch);
}

void printsubseqwithasciinumber(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    printsubseqwithasciinumber(ros,ans);
    printsubseqwithasciinumber(ros,ans+ch);
    printsubseqwithasciinumber(ros,ans+to_string(code));
}

string keypadArr[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s,string ans){
    //the string would be of numbers describing, which numbers are clicked.
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code = keypadArr[ch-'0'];
    string ros=s.substr(1);
    for(int i=0;i<code.length();i++){
        keypad(ros,ans+code[i]);
    }
}

void printpermutation(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        string ros = s.substr(0,i)+s.substr(i+1);
        printpermutation(ros,ans+ch);
    }
}

int countPath(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count = 0;
    for(int i=1;i<=e-s;i++){
        count+=countPath(s+i,e);
    }
    return count;
}

int countPathinMaze(int n,int i,int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countPathinMaze(n,i+1,j)+countPathinMaze(n,i,j+1);
}

//you want to fill a floor of 2*n size with tiles of 2*1, tell the number of ways.
int tilingWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return tilingWays(n-1)+tilingWays(n-2);
    //n-1:vertical and n-2 when horizontal as then other tile is fixed.
}

//ways in which we may pair or keep single our friends in a party
int friendsPairing(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    return friendsPairing(n-1)+friendsPairing(n-2)*(n-1);
}

int knapsack(int value[],int wt[],int n,int w){
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1]>w){return knapsack(value,wt,n-1,w);}
    return max(knapsack(value,wt,n-1,w-wt[n-1])+value[n-1],knapsack(value,wt,n-1,w));
}

//BackTracking: It is an algorithmic technique for solving recursive problems by trying to build every possible solution incrementally and removing those solutions that fail to satisfy the constraints of the problem at any point of time.
bool isSafe(int **arr,int x,int y,int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}

bool ratinMaze(int **arr,int x,int y,int n,int **solArr){
    if(x==n-1 && y==n-1){
        solArr[x][y]=1;
        return true;
    }
    
    if(isSafe(arr,x,y,n)){
        solArr[x][y]=1;
        if(ratinMaze(arr,x+1,y,n,solArr)){
            return true;
        }
        if(ratinMaze(arr,x,y+1,n,solArr)){
            return true;
        }
        solArr[x][y]=0;
        return false;
    }
    return false;
}

bool issafe(int **ar,int x,int y,int n){
    //remember we have to check only back from any row, not in front as we are placing it stepwise.
    //to check if a queen is there in a column, if its, then this column is not safe.
    for(int row=0;row<x;row++){
        if(ar[row][y]==1){
            return false;
        }
    }

    int row=x;
    int col=y;
    //checking back left diagonal
    while(row>=0 && col>=0){
        if(ar[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    row=x;
    col=y;
    //checking back right diagonal
    while(row>=0 && col<n){
        if(ar[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

return true;
}


bool nQueen(int **ar,int x,int n){
    if(x>=n){
        return true;
    }
    for(int col=0;col<n;col++){
        if(issafe(ar,x,col,n)){
            ar[x][col]=1;
            if(nQueen(ar,x+1,n)){
            return true;}
            ar[x][col] = 0;
                            }    
                        }
    return false;
}

int main(){
    reverseString("sarang");
    replace("pipipppipipipp");
    towerOfHanoi(3,'A','B','C'); //more than 10-15 may damage your cpu.
    cout<<removeDuplicates("nsdjkndkjsngjdnn")<<endl;
    cout<<moveX("dbxhxjhjx")<<endl;
    printsubseq("Sar","");cout<<endl;
    printsubseqwithasciinumber("AB","");cout<<endl;
    keypad("23","");
    printpermutation("ABC","");
    cout<<countPath(0,3)<<endl;
    cout<<countPathinMaze(2,0,0)<<endl;
    cout<<tilingWays(5)<<endl;
    cout<<friendsPairing(3)<<endl;
    int wt[] = {10,20,30};
    int values[] = {100,50,150};
    cout<<knapsack(values,wt,3,50)<<endl;
    int n=5;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    /*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/
//here 1 represents available and 0 blocked position.
    int **solArr= new int*[n];
    for(int i=0;i<n;i++){
        solArr[i] = new int[n];
        for(int j=0;j<n;j++){
            solArr[i][j]=0;
        }
    }

    if(ratinMaze(arr,0,0,n,solArr)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solArr[i][j]<<" ";
            }cout<<endl;
        }
    }
cout<<endl<<endl;
//N-Queen Problem:
n=4;
int **ar=new int*[n];
for(int i=0;i<n;i++){
    ar[i] = new int[n];
    for(int j=0;j<n;j++){
        ar[i][j]=0;
    }
}

if(nQueen(ar,0,n)){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ar[i][j]<<" ";
        }cout<<endl;
    }
}


}
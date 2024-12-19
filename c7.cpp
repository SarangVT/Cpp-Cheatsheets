#include <bits/stdc++.h>
using namespace std;

bool checkpt(int x,int y, int z){
    if((x*x)==(y*y+z*z) || (y*y)==(z*z+x*x) || (z*z)==(x*x+y*y)){
        return true;
    } else{return false;}
}

int power(int number,int power){
    int ans=1;
    for(int i=1;i<=power;i++){
        ans*=number;
    }
    return ans;
}

int binaryToDecimal(int num){
    int rem,i,ans;
    ans=0;
    i=0;
    while(num/10!=0){
        rem=num%10;
        ans+=(rem*power(2,i));
        num=num/10;
        i++;
    } 
    ans+=(num*=power(2,i));
    return ans;
}

int octalToDecimal(int num){
    int rem,i,ans;
    ans=0;
    i=0;
    while(num/10!=0){
        rem=num%10;
        ans+=(rem*power(8,i));
        num=num/10;
        i++;
    } 
    ans+=(num*=power(8,i));
    return ans;
}

int hexadecimalToNumber(string n){
    int ans=0;
    int x=1;
    int s = n.size();
    for(int i=s-1;i>=0;i--){
        if(n[i]>='0' && n[i]<='9'){
            ans += x*(n[i]-'0');
        } 
        else if(n[i] >= 'A' && n[i] <= 'F'){
            ans += x*(n[i] - 'A' + 10);
        }
        x*=16;
    }
    return ans;
}

int decimalToBinary(int n){
    int x = 1;
    int ans = 0;
    while(x<=n){
        x*=2;
    }
    x/=2;
    while(x>0){
        int lastDigit = n/x;
        n -= lastDigit*x;
        x/=2;
        ans = ans*10 + lastDigit;
    }
    return ans;

}

int decimalToOctal(int n){
    int ans = 0;
    int d = 1;
    while(n/d!=0){
        d*=8;
    }
    d/=8;

    while(n>0){
        int lastDigit = n/d;
        n-=(d*lastDigit);
        d/=8;
        ans = (ans*10+lastDigit);
    }
}

string decimalToHexaDecimal(int n){
    int x=1;
    string ans = "";
    while(x<=n){
        x*=16;
    }
    x/=16;

    while(x>0){
        int lastDigit = n/x;
        n -= lastDigit*x;
        x/=16;
        if(lastDigit <= 9){
            ans = ans + to_string(lastDigit);
        } else{
            char c = 'A' + lastDigit - 10;
            ans.push_back(c);
        }
    }
    return ans;
}

int addTwoBN(int x,int y){
    int m = binaryToDecimal(x);
    int n =binaryToDecimal(y);
    int ans = decimalToBinary(m+n);
    return ans;
}

int addtwobn(int a,int b){
    int ans=0;
    int prevCarry = 0;

    while(a>0 && b>0){
        if(a%2==0 && b%2==0){
            ans = ans*10 + prevCarry;
            prevCarry = 0;           
        }
        else if (a%2==0 && b%2==1 || a%2==1 && b%2==0){
            if(prevCarry==1){
            ans = ans*10 + 0;
            prevCarry = 1;
            }
            else{
                ans = ans*10+1;
                prevCarry = 0;
            }
        }
        else if(a%2==1 && b%2==1){
            ans = ans*10+prevCarry;
            prevCarry=1;
        }
        a/=10;
        b/=10;
    }
    while(a>0){
        if(prevCarry==1){
            if(a%2==1){
            ans = ans*10+0;
            prevCarry = 1;
        }
        else{
            ans = ans*10+1;
            prevCarry = 0;
        }
    } else{
        ans = ans*10 + (a%2); 
    }
    a/=10;
}


    while(b>0){
    if(prevCarry==1){
        if(b%2==1){
        ans = ans*10+0;
        prevCarry = 1;
    }
    else{
        ans = ans*10+1;
        prevCarry = 0;
    }
} else{
    ans = ans*10 + (b%2); 
}
    b/=10;
}

if(prevCarry==1){
    ans = ans*10 + 1;
}

int finalans = 0;
//to reverse the number as units digits went to biggest digit
while(ans>0){
    int lastDigit = ans%10;
    finalans = finalans*10+lastDigit;
    ans/=10;
}

return finalans;
}


int main(){
    cout<<checkpt(3,4,5)<<endl<<checkpt(3,4,6);
    cout<<binaryToDecimal(1101010111)<<endl; //warning: don't enter bigger numbers.
    cout<<octalToDecimal(1101010111)<<endl; //warning: don't enter bigger numbers.
    cout<<hexadecimalToNumber("A546ABCFD")<<endl;
    cout<<decimalToBinary(123)<<endl;
    cout<<decimalToOctal(15)<<endl;
    cout<<decimalToHexaDecimal(1450)<<endl;
    cout<<addTwoBN(10101,11010)<<endl;
    cout<<addtwobn(10101,11010)<<endl;
return 0;}
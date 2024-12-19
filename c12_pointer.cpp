#include <iostream>
#include <string>
using namespace std;

/*
void increment(int a){
    a++;
}
int main(){
    int a=2;
    increment(a);
    cout<<a<<endl;
}
here 2 would be printed, as function just takes value no actual variable goes inside it.
*/

//so we have to send address of the variable instead of value.

int swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int main(){
//in memory addresses of datatypes are in hexadecimal codes.

int a = 10;
int*aptr=&a;

cout<<*aptr<<endl;
*aptr=20;
cout<<a<<endl;

//Pointer Arithmetic
cout<<aptr<<endl;
aptr++;
cout<<aptr<<endl;
//here in hexadecimal pattern, value increases by 4, as int size is 4 bytes.
char ch = 'a';
char*cptr=&ch;
cout<<cptr<<endl;
cptr++;
cout<<cptr<<endl;
//here it increases by 1.

//Arrays: It can be used as pointers.
int arr[]={17678,3,4,6};
cout<<*arr<<endl;
//here pointer points to the first element.
//eg to print all elements using  pointer.

int *ptr = arr;
for(int i=0;i<4;i++){
    cout<<*ptr<<endl;
    ptr++;//writing arr++ is not allowed as only pointer can advance, but pointer can't change its value.
      //but you may write cout<<*(arr+i), here this is indexing pointer, so we have to advance it by i not 4i due to size ofint(4 byte).
}
//here it is possible as array is contiguous in memory.

int b=10;
int*bptr=&b;
int **q=&bptr;//this is pointer to pointer

cout<<*q<<endl; //one time dereferencing, means it gives address of where it points.
cout<<**q<<endl; //two time dereferencing means it gives b.

//Passing pointers to functions.
int a1=3;
int a2=6;
int *a1p=&a1;
int *a2p=&a2;
swap(*a1p,*a2p);
swap(&a1,&a2);
swap(a1p,a2p);
//3 methods to input in such functions.
cout<<a1<<" "<<a2<<endl;

//Stack and heap:
//Computers allocate memory in the form of stack and variables in its each layer are local and can't be accessed in other layers, also they are deleted as stack returns.
//But, to make variables which are global, we have to manually create as well as delete them, using pointers.
//In this way, they are created in heap(free store) instead of stack.
//Actually the pointer is created in stack, which points to the data stored in heap.

int *p = new int();//allocate memory
*p=10;
cout<<*p<<endl;
delete(p);
//cout<<*p<<endl;

p=new int[4];
delete[]p;
p=NULL;

//this is dynamically allocated memory, and its size can be changed after compilation.
return 0;}
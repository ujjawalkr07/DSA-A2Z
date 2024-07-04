/*
Print numbers from 1 to n without the help of loops. You only need to complete the function printNos() that takes N as parameter and prints number from 1 to N recursively.
solution:-backtracking 
here printing will be done after function call.
*/

#include<iostream>
using namespace std;
void printNos(int n);
int main()
{
    int n;
    cout<<"enter n:- ";
    cin>>n;
    printNos(n);
    return 0;
}
void printNos(int n)
    {
        if(n==0)
            return;
        printNos(n-1);
        cout<<n<<" ";
    }
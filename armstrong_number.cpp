/*
An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

Examples:-153,9474,371
Example 1:
Input:N = 153
Output:True
Explanation: 1^3+5^3+3^3 = 1 + 125 + 27 = 153
*/
#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cout<<"enter number:- ";
    cin>>n;
    int num=n;
    // counting no of digit 
    int count=0;
    while(num!=0)
    {
        count++;
        num=num/10;
    }
    cout<<"no of digit "<<count<<endl;
    // adding digit raised to power of count
    int sum=0;
    int temp=n;
    while(temp!=0)
    {
        int digit=temp%10;
        sum+=(int)pow(digit,count);
        temp=temp/10;
    }
    cout<<"sum is "<<sum<<endl;
    // comparison
    if(sum==n)
        cout<<"yes, it is a armstrong number.";
    else
        cout<<"no, it is not a armstrong number.";
    return 0;
}
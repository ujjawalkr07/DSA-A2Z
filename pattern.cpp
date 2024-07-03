/*
   for n=3, pattern:-
3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3

for n=5 pattern:-
5 5 5 5 5 5 5 5 5
5 4 4 4 4 4 4 4 5
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5
5 4 3 2 1 2 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 3 3 3 3 4 5
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5
 */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    // top half
     for(int i=0;i<n;i++)
    {
        // left side
        for(int j=0;j<i;j++)
        {
            cout <<n-j<<" ";
        }
        // taking middle element as space in before problem
        for(int k=0;k<=2*n-3-2*i;k++)
        {
            cout <<n-i<<" ";
        }
        // right side
        for(int j=i;j>=0;j--)
        {
            cout <<n-j<<" ";
        }
        cout<<endl;
    }
    // bottom half
    for(int i=n-2;i>=0;i--)
    {
        // left side
        for(int j=0;j<=i;j++)
        {
            cout <<n-j<<" ";
        }
        // taking middle element as space in before problem
        for(int k=0;k<2*n-3-2*i;k++)
        {
            cout <<n-i<<" ";
        }
        // right side
        for(int j=i;j>=0;j--)
        {
            cout <<n-j<<" ";
        }
        cout<<endl;
    }
    
}
/*
The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. It operates on the principle that the GCD of two numbers remains the same even if the smaller number is subtracted from the larger number.

To find the GCD of n1 and n2 where n1 > n2:

Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
Once one of them becomes 0, the other number is the GCD of the original numbers.
Eg, n1 = 20, n2 = 15:

gcd(20, 15) = gcd(20-15, 15) = gcd(5, 15)

gcd(5, 15) = gcd(15-5, 5) = gcd(10, 5)

gcd(10, 5) = gcd(10-5, 5) = gcd(5, 5)

gcd(5, 5) = gcd(5-5, 5) = gcd(0, 5)

Hence, return 5 as the gcd.
----------------------------
this can be written in short as
gcd(a,b) = gcd(b,a%b) where a>b
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
        int A;
        int B;
        cout <<"enter a and b for which lcm and gcd is to be found:- ";
        cin>>A>>B;
        int a=A;
        int b=B;
        vector <long long> v(2);
        while(min(a,b) != 0)
        {
            int c = a;
            a = max(a,b) % min(a,b);
            b = min(c,b);
        }
        v[1] = max(a,b);
        
        v[0] = A*B/v[1];
        cout<<"lcm is "<<v[0]<<" and gcd is "<<v[1]<<endl;
        /*for (int num : v) 
        {
            cout << num << " ";
        }*/
    return 0;
}
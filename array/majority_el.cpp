#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        /* brute force approach here we are counting frequency of each element and 
        then checking if  it is greater than n/2.
        t.c=O(n^2) and s.c=O(1).
        int el=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j]==arr[i])
                    count++;

            }
            if(count>(n/2))
                return arr[i];
        }
        return -1;
    */

    //  better approach using hash map
    /* using hash map key->array element and value->frequency
     t.c=O(n*log n)+O(n)
     s.c=O(n)
    
    map<int,int>mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it:mpp)
    {
        if(it.second>(n/2))
            return it.first;
    }
    return -1;
    */
    // optimal approach:-Moore’s Voting Algorithm:
    /*
    Intuition:
If the array contains a majority element, its occurrence must be greater than the floor(N/2). 
Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array.
 So when we traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 

After traversing the whole array, we will check the element stored in the variable. If the question states that the array must contain a majority
 element, the stored element will be that one but if the question does not state so, 
 then we need to check if the stored element is the majority element or not.
  If not, then the array does not contain any majority element.

Approach: 
Initialize 2 variables:
Count –  for tracking the count of element
Element – for which element we are counting
Traverse through the given array.
If Count is 0 then store the current element of the array as Element.
If the current element and Element are the same increase the Count by 1.
If they are different decrease the Count by 1.
The integer present in Element should be the result we are expecting 
    */
        int count=0;
        int el;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                count=1;
                el=arr[i];
            }
            else if(arr[i]==el)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        int count1=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==el)
                count1++;

        }
        if(count1>n/2)
            return el;
        return -1;
    }

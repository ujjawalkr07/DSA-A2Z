#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& arr);
void nextPermutation(vector<int>& arr) {
        /* brute force approach. here we are finding all the permutation and then we
        will check with given array and return the next one which is its 
        next permutation
        t.c=O(n!*n) which is very large if no is bit big.
        s.c=O(1) 
        */
        // optimal approach
        /* better approach 
         C++ provides an in-built function called next_permutation()
          which directly returns the lexicographically next greater permutation of the input.
          --
          next_permutation(arr,arr+n);
        */
        int ind = -1;
        int n= arr.size();
        for(int i= n-2 ;i>=0 ;i--)
        {     // this for loop is to find index of first dip i.e first element from back
                // which is smaller than next element 
            if(arr[i]<arr[i+1])
            {
                ind=i;
                break;
            }
        }
        if(ind == -1)
        { // index will be -1 when there is no dip i.e whole array is in decreasing 
        // which means that it is last permutation and its next perm is first permutation 
        // i.e all element are in ascending order
            reverse(arr.begin(),arr.end());
        }
        for(int i=n-1;i>ind;i--)
        {   // here we are swapping element which is just greater than index element
            if(arr[i]>arr[ind])
            {
                swap(arr[i],arr[ind]);
                break;
            }
        }
        // now reversing the rest array i.e array from index+1 to end. to get next permutation
        reverse(arr.begin()+ind+1,arr.end());
    }
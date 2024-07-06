/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter limit of array:-";
    cin>>n;
    int nums[n];
    cout<<endl<<"enter elements of array in ascending array";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int i=0;
    for(int j=1;j<n;j++)
    {
        if(nums[i]!=nums[j])
        {
            nums[i+1]=nums[j];
            i++;
        }
    }
    cout<<endl<<"unique elements in array:-"<<i+1<<endl<<"the array after deleting duplicate is ";
    for(int k=0;k<i+1;k++)
    {
        cout<<nums[k]<<" ";
    }
    return 0;
}

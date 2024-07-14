// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        // this is brute force approach
        // vector<int>temp;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(target==nums[i]+nums[j])
        //         {
        //             temp.push_back(i);
        //             temp.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return temp;

        // better approach using unoredered hash map having t.c=O(n*logn i.e in best and avg case )and ((n^2 i.e in case of worst case))
        // vector<int> temp;
        // unordered_map<int,int> mpp;
        // for(int i=0;i<n;i++)
        // {
        //     int el=arr[i];
        //     int more_needed=target-el;
        //     if(mpp.find(more_needed) != mpp.end())
        //     {
        //         temp.push_back(i);
        //         temp.push_back(mpp[more_needed]);

        //     }
        //     mpp[el]=i;
        // }
        // return temp;
        

        // best case two pointer
        /*Time Complexity: O(N) + O(N*logN), where N = size of the array.
Reason: The loop will run at most N times. And sorting the array will take N*logN time complexity.

Space Complexity: O(1) as we are not using any extra space.*/
        int left=0, right=n-1;
        vector<int> temp;
        sort(arr.begin(),arr.end());
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum==target)
            {
                temp.push_back(arr[left]);
                temp.push_back(arr[right]);
            }
            else if(sum<target)
                left++;
            else
                right--;

        }
        return temp;

    }
};

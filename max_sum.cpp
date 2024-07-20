#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        /*
        brute force approach of t.c=O(n^3)
        int max_sum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum=0;
                for(int k=i;k<=j;k++)
                {
                    sum+=arr[k];
                }
                max_sum=max(max_sum,sum);
            }
        }
        return max_sum;
    */
    /*
        better approach with time complexity of O(n^2)
        
        int curr_sum[n+1];
        curr_sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            curr_sum[i]=curr_sum[i-1]+arr[i-1];
        }
        int max_sum=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            int sum=0;
            for(int j=0;j<i;j++)
            {
                sum=curr_sum[i]-curr_sum[j];
                max_sum=max(max_sum,sum);
            }
        }
        return max_sum;
*/
    
        // best approach using kadane algorithm that has time complexity of O(n)
        /*
        The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
    Here, we will iterate the given array with a single loop and while iterating 
    we will add the elements in a sum variable. 
    Now, if at any point the sum becomes less than 0, we will set the sum as 0 as 
    we are not going to consider any subarray with a negative sum. 
    Among all the sums calculated, we will consider the maximum one.
        */
        int maxi=INT_MIN;
        int sum=0;
        int start = 0;
        int ans_start=-1, ans_end=-1;
        for(int i=0;i<n;i++)
        {
            if(sum==0)
                start=i;
            sum+=arr[i];
            if(sum>maxi)
            {
                maxi=sum;
                ans_start=start;
                ans_end=i;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
    }
int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
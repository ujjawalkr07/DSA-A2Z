#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& arr) {
        int n=arr.size();
        /* brute force approach
        where t.c=O(n^2) and s.c=O(1)

        int maxpro=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]>arr[i])
                {
                    maxpro=max(maxpro,(arr[j]-arr[i]));
                }
            }
        }
        return maxpro;
        */
        // optimal approach 
        // Time complexity: O(n) ,Space Complexity: O(1)
        int maxpro=0;
        int minprice=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(minprice>arr[i])
            {
                minprice=arr[i];
            }
            maxpro=max(maxpro,(arr[i]-minprice));
        }
        return maxpro;
    }
int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
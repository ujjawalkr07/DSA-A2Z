#include<bits/stdc++.h>
using namespace std;
vector<int> leaders(int n, int arr[]);
vector<int> leaders(int n, int arr[]) {
        // Code here
        /* brute force approach
        Time Complexity: O(N^2)
        Space Complexity: O(N) 
        vector<int >temp;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=arr[i];
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]>arr[i])
                {
                    maxi=arr[j];
                    break;
                }
            }
            if(maxi == arr[i])
                temp.push_back(arr[i]);
        }
        return temp;
        */
       //Optimized Approach
       //Time Complexity: O(N)
       //Space Complexity: O(N)
        int max=arr[n-1];   // last element is always leader
        vector<int >ans;
        ans.push_back(max);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i] > max)
            {
                ans.push_back(arr[i]);
                max=arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = leaders(n,arr);
  
  
  for(int i = ans.size()-1;i>=0;i--){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}
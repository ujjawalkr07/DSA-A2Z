#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& arr);
int longestConsecutive(vector<int>& arr) {
        /*
        brute force approach
        t.c=O(n^2)
        s.c=O(1)
        int longest=0;
        int count=0;
        
        for(int i=0;i<arr.size();i++)
        {
            int x=arr[i];
            count=1;
            while(ls(arr,x+1) == true)
            {
                x=x+1;
                count=count+1;
            }
            longest=max(count,longest);
        }
        return longest;
    }
    int ls(vector<int>& arr,int num)
    linear search for brute force solution.
    {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==num)
                return true;
        }
        return false;
    }
    */
        
    /* Better Approach(Using sorting): 
    We can simply sort the array and run a for loop to find 
    the longest consecutive sequence.
    Time Complexity: O(NlogN) + O(N)
    Space Complexity: O(1)


    if(nums.size() == 0) return 0;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int lastsmaller=INT_MIN;
    int count=0;
    int longest=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]-1 == lastsmaller)
        {
            count+=1;
            lastsmaller=nums[i];
        }
        else if(lastsmaller != nums[i])
        {
            count=1;
            lastsmaller=nums[i];
        }
        longest=max(longest,count);
    }
    return longest;
    */

    /* optimal approach
    We will adopt a similar approach to the brute-force method 
    but with optimizations in the search process. Instead of searching 
    sequences for every array element as in the brute-force approach, 
    we will focus solely on finding sequences only for those numbers 
    that can be the starting numbers of the sequences. 
    This targeted approach narrows down our search and improves efficiency.
    We will do this with the help of the Set data structure
    Time Complexity: O(N) + O(2*N) ~ O(3*N)
    Space Complexity: O(N)
    */
        int n=arr.size();
        if(n==0)
            return 0;
        int longest=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(arr[i]);
        }
        for(auto it: st)
        {
            if(st.find(it-1) == st.end())
            {
                int cnt=1;
                int x=it;
                while(st.find(x+1) != st.end())
                {
                    x=x+1;
                    cnt=cnt+1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
    
int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestConsecutive(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
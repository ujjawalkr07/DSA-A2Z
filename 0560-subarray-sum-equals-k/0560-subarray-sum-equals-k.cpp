class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        /* brute force approach
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum=0;
                for(int k=i;k<=j;k++)
                {
                    sum=sum+arr[k];
                }
                if(sum==k)
                {
                    count++;
                }
            }
        }
        return count;
        */

        /* better approach
        int count=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=arr[j];
                if(sum==k)
                {
                    count++;
                }
            }
        }
        return count;
    */
    
    // optimal approach using hash map with presum and count as id and value
        unordered_map<int ,int >mpp;
        mpp[0] = 1;
        int presum=0,count=0;
        for(int i=0;i<n;i++)
        {
            presum+=arr[i];
            int remove=presum-k;
            count+=mpp[remove];
            mpp[presum]+=1;
        }
        return count;
    }
};
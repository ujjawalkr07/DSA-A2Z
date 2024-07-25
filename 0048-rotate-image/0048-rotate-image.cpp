class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        /* brute force approach
        t.c=O(m*n), s.c=O(m*n) i.e here we are using extra array to find it
        int arr[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[j][m-1-i]=matrix[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=arr[i][j];
            }
        }
        */
        // optimal approach- 
        //observation- first taking transpose and the reversing the row of matrix
         // transpose
         for(int i=0;i<m-1;i++)
         {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
         }
         //reverse
         for(int i=0;i<m;i++)
         {
            // row is mat[i]
            reverse(matrix[i].begin(),matrix[i].end());
         }
    }
};
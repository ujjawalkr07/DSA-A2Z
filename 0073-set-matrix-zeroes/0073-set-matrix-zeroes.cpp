class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // brute force solution
        int n=matrix.size();
        int m=matrix[0].size();
        /*
        vector<int>temp_col;
        vector<int>temp_row;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    temp_row.push_back(i);
                    temp_col.push_back(j);
                }
            }
        }
        for(int i=0;i<temp_col.size();i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][temp_col[i]]=0;
            }
        }
        for(int i=0;i<temp_row.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[temp_row[i]][j]=0;
            }
        }
        */
        
        // better solution
        vector<int>col(m,0);
        vector<int>row(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i] || col[j])
                {
                        matrix[i][j]=0;
                }
            }
        }
        
        
    }
};
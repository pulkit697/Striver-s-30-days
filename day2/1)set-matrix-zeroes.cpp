// https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        bool row = 0;
        bool col = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j] == 0){
                    if(i == 0)
                    {
                        row = 1;
                    }
                    if(j == 0)
                    {
                        col = 1;
                    }
                    if(i>0 && j>0)
                    {
                        arr[i][0] = 0;
                        arr[0][j] = 0;
                    }
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            if(arr[i][0] == 0)
            {
                /*MAKE ROW ZERO*/
                for(int j=0;j<n;j++)    arr[i][j]=0;
            }
        }
        for(int j=1;j<n;j++)
        {
            if(arr[0][j] == 0)
            {
                for(int i=1;i<m;i++)    arr[i][j]=0;
            }
        }
        if(row == 1)
        {
            for(int j=0;j<n;j++)    arr[0][j] = 0;
        }
        if(col == 1)
        {
            for(int i=0;i<m;i++)    arr[i][0] = 0;
        }
        
    }
};
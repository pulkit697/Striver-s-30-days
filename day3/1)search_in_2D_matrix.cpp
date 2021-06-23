// Ques1
// https://leetcode.com/problems/search-a-2d-matrix/
// arr[i][m-1]<arr[i+1][0]
// Time O(log(n) + log(m))
// Space O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tar) {
        int n = arr.size();
        int m = arr[0].size();
        int lo = 0;
        int hi = n-1;
        int row = -1;
        int mid = -1;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(arr[mid][0] == tar)  return 1;
            if(arr[mid][0]<tar){
                row   = mid;
                lo = mid+1;
            }else{
                hi   = mid-1;
            }
        }
        if(row == -1)   return 0;
        lo = 0;
        hi = m-1;
        int col = -1;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(arr[row][mid] == tar)    return 1;
            if(arr[row][mid]<tar){
                lo = mid+1;
            }else{
                hi   = mid-1;
            }
        }
        return 0;
    }
};

// Ques 2
// row and column wise sorted matrix
// https://leetcode.com/problems/search-a-2d-matrix-ii/
// Time O(n+m)
// Space O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tar) {
        int n = arr.size();
        int m = arr[0].size();
        int i = 0;
        int j = m-1;
        while(i<n && j>=0)
        {
            if(arr[i][j] == tar)    return 1;
            if(arr[i][j] > tar) j--;
            else    i++;
        }
        return 0;
    }
};
// https://leetcode.com/problems/xor-queries-of-a-subarray/
// Time O(n)
// Space O(n)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> temp(n+1);
        temp[0]=0;
        for(int i=0;i<n;i++)
            temp[i+1]=temp[i]^arr[i];
        vector<int> v;
        for(auto& it:queries)
        {
            v.push_back(temp[it[1]+1]^temp[it[0]]);
        }
        return v;
    }
};
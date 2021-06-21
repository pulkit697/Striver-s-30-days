// https://leetcode.com/problems/pascals-triangle/submissions/

class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n == 1)  return {{1}};
        if(n == 2)  return {{1},{1,1}};
        vector<vector<int>> ans = generate(n-1);
        int x = ans.back().size()+1;
        vector<int> v(x);
        v[0]=1;
        v[x-1] = 1;
        for(int i=1;i<x-1;i++)
            v[i] = ans.back()[i-1] + ans.back()[i];
        ans.push_back(v);
        return ans;
    }
};
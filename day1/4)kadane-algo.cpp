// https://leetcode.com/problems/maximum-subarray/submissions/
// time O(n)
// space O(1)

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int curr = 0;
        int mx = INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            curr+=arr[i];
            mx = max(mx,curr);
            if(curr<0)  curr=0;
        }
        return mx;
    }
};
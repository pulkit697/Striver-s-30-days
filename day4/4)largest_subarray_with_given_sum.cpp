// https://leetcode.com/problems/subarray-sum-equals-k/
// Time O(nlogn)
// Space O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        int ans = 0 ;
        mp[0]=1;
        for(int& i:nums)
        {
            sum+=i;
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};
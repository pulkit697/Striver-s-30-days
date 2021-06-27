// https://leetcode.com/problems/longest-consecutive-sequence/
// Time O(nlogn)
// Space O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        int count=0;
        int mx=0;
        int prev;
        bool flag=0;
        for(auto &it:s)
        {
            if(!flag || it-prev>1)
                count=0;
            count++;
            prev=it;
            mx=max(mx,count);
            flag=1;
        }
        return mx;
    }
};
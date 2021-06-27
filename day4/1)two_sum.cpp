// https://leetcode.com/problems/two-sum/
// Time O(nlogn)
// Space O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();i++)
            temp.push_back({nums[i],i});
        sort(temp.begin(),temp.end());
        int i = 0;
        int j = nums.size()-1;
        while(i<j)
        {
            int sum = temp[i].first+temp[j].first;
            // cout<<sum<<'\n';
            if(sum==target){
                ans.push_back(temp[i].second);
                ans.push_back(temp[j].second);
                return ans;
            }
            else if(sum<target)
                i++;
            else if(sum>target)
                j--;
        }
        return ans;
    }
};
// https://leetcode.com/problems/majority-element-ii/
// Time O(n)
// Space O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0;
        int el1=INT_MIN,el2=INT_MAX;
        for(auto& it:nums)
        {
            if(it == el1)
                c1++;
            else if(it == el2)
                c2++;
            else if(c1 == 0){
                el1 = it;
                c1 = 1;
            }
            else if(c2 == 0){
                el2 = it;
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        int a = 0;
        int b = 0;
        for(auto it:nums){
            if(it == el1)
                a++;
            if(it == el2)
                b++;
        }
        vector<int> v;
        if(a>nums.size()/3)
            v.push_back(el1);
        if(b>nums.size()/3)
            v.push_back(el2);
        return v;
    }
};
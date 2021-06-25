// https://leetcode.com/problems/majority-element/
// Time O(n)
// Space O(1)
// BOYER MOORE VOTING ALGORITHM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int el = -1;
        for(auto& it:nums)
        {
            if(it == el){
                c++;
            }
            else if(c == 0)
            {
                el = it;
                c = 1;
            }
            else
            {
                c--;
            }
        }
        return el;
    }
};
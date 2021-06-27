// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Time O(n)
// Space O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool freq[256];
        memset(freq,0,sizeof(freq));
        int start = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            while(freq[s[i]]!=0)
            {
                freq[s[start++]]=0;
            }
            freq[s[i]]=1;
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};
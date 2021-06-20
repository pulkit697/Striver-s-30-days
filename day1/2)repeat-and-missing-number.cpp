// https://leetcode.com/problems/missing-number/
// time O(n)
// space O(1)

// way 1
class Solution {
public:
    int missingNumber(vector<int>& v) {
        v.push_back(1);
        int n = v.size();
        for(int i=0;i<n-1;i++)
        {
            v[v[i]%n]+=n;
        }
        for(int i=0;i<n;i++)
        {
            if(v[i]<n)  return i;
        }
        return n;
    }
};

// way 2
class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n = v.size();
        v.push_back(1);
        for(int i=0;i<n;i++)
        {
            v[abs(v[i])]*=-1;
        }
        int idx = 0;
        for(int i=0;i<=n;i++)
        {
            if(v[i]>0)  return i;
            if(v[i] == 0)   idx = i;
        }
        return idx;
    }
};
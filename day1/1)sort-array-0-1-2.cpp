// https://leetcode.com/problems/sort-colors/
// time O(n)
// space O(1)
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int i = 0;
        int j = arr.size()-1;
        for(int k=0;k<=j;k++)
        {
            if(arr[k] == 0){
                swap(arr[i],arr[k]);
                i++;
            }
            else if(arr[k] == 2)
            {
                swap(arr[j],arr[k]);
                j--;
                k--;
            }
        }
    }
};
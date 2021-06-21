// 121. Best Time to Buy and Sell Stock
// 122. Best Time to Buy and Sell Stock II
// 123. Best Time to Buy and Sell Stock III
// 188. Best Time to Buy and Sell Stock IV
// 309. Best Time to Buy and Sell Stock with Cooldown
// 714. Best Time to Buy and Sell Stock with Transaction Fee

// 121
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int mx = arr[n-1];
        for(int i=n-1;i>=0;i--)
        {
            ans = max(ans,mx-arr[i]);
            mx = max(mx,arr[i]);
        }
        return ans;
    }
};

// 122
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans = 0;
        int prev = arr[0];
        int n = arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]<=arr[i-1])
            {
                ans+=(arr[i-1]-prev);
                prev = arr[i];
            }
        }
        ans+=(arr[n-1]-prev);
        return ans;
    }
};

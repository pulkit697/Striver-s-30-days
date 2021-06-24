// https://leetcode.com/problems/powx-n/
// Time O(log(n))
// Space O(1)

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)  return 1.0;
        double ans = myPow(x,n/2);
        ans = ans*ans;
        if(abs(n)%2==1){
            if(n>0){
                ans*=x;
            }else{
                ans/=x;
            }
        }
        return ans;
    }
};
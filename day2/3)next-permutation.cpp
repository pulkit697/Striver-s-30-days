// https://leetcode.com/problems/next-permutation/submissions/

class Solution {
    void sort(vector<int>& v,int k)
    {
        int j = v.size()-1;
        int i=k;
        while(i<j)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    int bs(vector<int>&v,int start,int& val)
    {
        int end = v.size()-1;
        int ans = start;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(v[mid]>val){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
public:
    void nextPermutation(vector<int>& arr) {
        bool flag = 0;
        int j=arr.size()-2;
        while(j>=0)
        {
            if(arr[j]<arr[j+1])
            {
                int x= arr[j];
                int idx = bs(arr,j+1,x);
                arr[j]=arr[idx];
                arr[idx]=x;
                sort(arr,j+1);
                flag=1;
                break;
            }
            j--;
        }
        if(flag == 0)   sort(arr,0);
    }
};
// https://leetcode.com/problems/reverse-pairs/
// Time O(NlogN)
// Space O(n)
class Solution {
    int ans = 0;
    void merge(vector<int>& arr,int lo,int mid,int hi)
    {
        int n = hi-lo+1;
        int i=lo,j=mid+1,k=0;
        while(i<=mid && j<=hi)
        {
            int y = arr[i];
            y = y/2;
            if(arr[i]%2 == 1)
                y++;
            if(y>arr[j]){
                ans+=(mid-i+1);
                j++;
            }else{
                i++;
            }
        }
        int temp[n];
        i=lo,j=mid+1,k=0;
        while(i<=mid && j<=hi)
        {
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
            }
        }
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        while(j<=hi){
            temp[k++] = arr[j++];
        }
        for(int z=0;z<n;z++)
        {
            arr[z+lo] = temp[z];
        }
    }
    void mergeSort(vector<int>& arr,int i,int j)
    {
        if(i>=j)    return;
        int mid = (i+j)/2;
        mergeSort(arr,i,mid);
        mergeSort(arr,mid+1,j);
        merge(arr,i,mid,j);
    }
public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergeSort(nums,0,nums.size()-1);
        // for(int i=0;i<nums.size();i++)  cout<<nums[i]<<"  ";
        return ans;
    }
};
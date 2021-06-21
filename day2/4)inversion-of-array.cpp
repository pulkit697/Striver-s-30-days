// https://leetcode.com/problems/global-and-local-inversions/submissions/
// time O(nlogn)
// space O(n)

class Solution {
    long long c = 0;
    void merge(vector<int>& v,int start,int mid,int end)
    {
        int i = start;
        // cout<<i<<"  "<<mid<<"  "<<end<<"       ";
        int n = end-i+1;
        int j = mid+1;
        int arr[n];
        int k=0;
        while(i<=mid && j<=end)
        {
            if(v[i]<=v[j]){
                arr[k++] = v[i++];
            }else{
                c+=(mid-i+1);
                arr[k++] = v[j++];
            }
        }
        while(i<=mid)   arr[k++] = v[i++];
        while(j<=end)   arr[k++] = v[j++];
        // cout<<"*&^%$#@!\n";
        for(int z=0;z<n;z++){
            v[start+z] = arr[z];
        }
    }
    void mS(vector<int>& v,int i,int j)
    {
        if(i>=j)    return;
        int mid = (i+j)/2;
        mS(v,i,mid);
        mS(v,mid+1,j);
        merge(v,i,mid,j);
    }
    int local(vector<int>& v)
    {
        int c1 = 0;
        if(v.size()<2)  return 0;
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1]) c1++;
        }
        return c1;
    }
public:
    bool isIdealPermutation(vector<int>& arr) {
        int c1 = local(arr);
        c = 0;
        mS(arr,0,arr.size()-1);
        // cout<<c<<"  "<<c1<<'\n';
        return c == c1;
    }
};
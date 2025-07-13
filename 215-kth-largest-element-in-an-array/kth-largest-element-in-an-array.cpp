class Solution {
public:
    // int partition(vector<int>&nums , int l , int r){
    //     int p =  nums[r];
    //     int i = l ;
    //     for(int j = l ; j < r ; ++j) if(nums[j] <= p) swap(nums[i++],nums[j]);
    //     swap(nums[i],nums[r]);
    //     return i;
    // }
    // int qs(vector<int>&nums , int l ,int r , int k){
    //     if(l == r) return nums[l];
    //     int p = partition(nums,l,r);
    //     if(p == k) return nums[k];
    //     else if(p < k ) return qs(nums,p+1,r,k);
    //     else return qs(nums,l,p-1,k);
    // }
    int findKthLargest(vector<int>& nums, int k) {
        int n  =  nums.size();
        // return qs(nums,0,n-1,n-k); // kth largest is n-k th smallest 
        
        
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        
        for (int num: nums) {
            minValue = min(minValue, num);
            maxValue = max(maxValue, num);
        }
        
        vector<int> count(maxValue - minValue + 1);
        for (int num: nums) {
            count[num - minValue]++;
        }
        
        int remain = k;
        for (int num = count.size() - 1; num >= 0; num--) {
            remain -= count[num];
            if (remain <= 0) {
                return num + minValue;
            }
        }
        
        return -1;
    }
};
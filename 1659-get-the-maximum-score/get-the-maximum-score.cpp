class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int mod = 1e9 + 7;
        long long sum1 = 0, sum2 = 0  , result =0 ;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while (i < n1 && j < n2){
            if (nums1[i] < nums2[j])  sum1 += nums1[i++];
            else if (nums1[i] > nums2[j])  sum2 += nums2[j++];
            else {
                result += max(sum1, sum2) + nums1[i]; 
                sum1 = 0 , sum2 = 0;
                i++, j++;
            }
        }
        while(i < n1) sum1 += nums1[i++];
        while(j < n2) sum2 += nums2[j++];
        result += max(sum1, sum2);
        return result % mod;
    }
};
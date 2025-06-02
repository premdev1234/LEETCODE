#define vi vector<int>
class Solution {
public:
    int s[200002];
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int reach =  0 ; 
        for(int i = 0 ; i < n/2 ;i++){
            int a =  nums[i] , b = nums[n-1-i];
            int min_sum =  min(a,b) ,  mx_sum = max(a,b) ,  sum =  a + b ;
            reach = max(reach , min_sum+mx_sum);
            s[1] += 2;
            s[min_sum+1]--;
            s[min_sum+mx_sum]--;
            s[min_sum+mx_sum+1]++;
            s[mx_sum+limit+1]++   ;
        }
        reach =  max(reach,2*limit);

        int res = INT_MAX;
        for(int i = 2 ; i <= reach ; i++){ 
            s[i] += s[i-1];
            res = min(res,s[i]);  
        }        
        return res ;
    }
};
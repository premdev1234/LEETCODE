class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        std::vector<int> p(n) , s(n);
        p[0] = prices[0] , s[n-1] = prices[n-1];
        int ans = 0 ;
        for(int i = 1 ; i < n ; ++i)p[i] = std::min(p[i-1],prices[i]) , s[n-i-1] = std::max(s[n-i],prices[n-i-1]);
        for(int i = 0 ; i < n ; ++i)ans = std::max(ans , s[i] - p[i]);
        return ans ;
    }
};
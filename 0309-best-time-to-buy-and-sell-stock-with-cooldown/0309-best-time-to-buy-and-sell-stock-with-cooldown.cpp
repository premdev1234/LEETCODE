class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0] , sold = INT_MIN , rest = 0 , n  = (int)prices.size();
        for (int i = 1; i < n; i++) {
            int prevHold = hold , prevSold = sold , prevRest = rest;
            hold = max(prevHold, prevRest - prices[i]);
            sold = prevHold + prices[i];
            rest = max(prevRest, prevSold);
        }
        return max(sold, rest);
    }
};
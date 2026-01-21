class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        vector<pair<int,int>> v(n) ;
        v[0].first = prices[0];
        v[n-1].second = prices[n-1];
        for(int  i = 1 ; i < n ; ++i)v[i].first = min(prices[i] , v[i-1].first );
        for(int i = n - 2 ; i>= 0 ; --i)v[i].second = max(prices[i],v[i+1].second);
        int profit = 0 ;
        for(int i = 0 ;  i < n ; ++i)profit = max(profit , v[i].second - v[i].first);
        return profit;
    }
};
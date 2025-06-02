class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> buyPQ; // Max heap: {price, amount}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> sellPQ; // Min heap: {price, amount}
        const int MOD = 1e9 + 7;

        for (auto& order : orders) {
            int price = order[0], amount = order[1], type = order[2];

            if (type == 0) {
                // Buy order: match with lowest sell price
                while (amount > 0 && !sellPQ.empty() && sellPQ.top().first <= price) {
                    auto [sellPrice, sellAmount] = sellPQ.top();
                    sellPQ.pop();

                    int matched = min(amount, sellAmount);
                    amount -= matched;
                    sellAmount -= matched;

                    if (sellAmount > 0)
                        sellPQ.push({sellPrice, sellAmount});
                }
                if (amount > 0)
                    buyPQ.push({price, amount});
            } else {
                // Sell order: match with highest buy price
                while (amount > 0 && !buyPQ.empty() && buyPQ.top().first >= price) {
                    auto [buyPrice, buyAmount] = buyPQ.top();
                    buyPQ.pop();

                    int matched = min(amount, buyAmount);
                    amount -= matched;
                    buyAmount -= matched;

                    if (buyAmount > 0)
                        buyPQ.push({buyPrice, buyAmount});
                }
                if (amount > 0)
                    sellPQ.push({price, amount});
            }
        }

        long long backlog = 0;
        while (!buyPQ.empty()) {
            backlog = (backlog + buyPQ.top().second) % MOD;
            buyPQ.pop();
        }
        while (!sellPQ.empty()) {
            backlog = (backlog + sellPQ.top().second) % MOD;
            sellPQ.pop();
        }

        return backlog;
    }
};

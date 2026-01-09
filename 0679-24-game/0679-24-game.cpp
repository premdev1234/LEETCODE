class Solution {
private:
    static constexpr double EPSILON = 1e-6, TARGET = 24.0;
    bool canFormTarget(vector<double>& values) {
        const int count = values.size();
        if (count == 1)
            return fabs(values[0] - TARGET) < EPSILON;
        for (int i = 0; i < count; ++i) {
            for (int j = i + 1; j < count; ++j) {
                const double a = values[i], b = values[j];
                vector<double> reduced;
                reduced.reserve(count - 1);
                for (int k = 0; k < count; ++k)
                    if (k != i && k != j)
                        reduced.push_back(values[k]);
                vector<double> candidates = generateResults(a, b);
                for (double result : candidates) {
                    reduced.push_back(result);
                    if (canFormTarget(reduced))
                        return true;
                    reduced.pop_back();
                }
            }
        }
        return false;
    }
    vector<double> generateResults(double a, double b) {
        vector<double> results;
        results.reserve(6);
        results.push_back(a + b), results.push_back(a - b),
            results.push_back(b - a), results.push_back(a * b);
        if (fabs(b) > EPSILON)
            results.push_back(a / b);
        if (fabs(a) > EPSILON)
            results.push_back(b / a);
        return results;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> values;
        values.reserve(cards.size());
        for (int value : cards)
            values.push_back(static_cast<double>(value));
        return canFormTarget(values);
    }
};

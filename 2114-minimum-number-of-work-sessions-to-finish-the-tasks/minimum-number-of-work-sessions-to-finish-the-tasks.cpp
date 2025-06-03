#define vi vector<int>
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rrep(i, a, b) for(int i = a; i >= b; --i)
#define sz(x) (int)(x).size()
#define INF INT_MAX
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        const int n = sz(tasks);
        const int maxMask = 1 << n;
        vector<int> minSessionsRequired(maxMask, INF);
        minSessionsRequired[0] = 0;

        // For all subsets
        rep(mask, 1, maxMask) {
            // Check each submask of mask
            for (int submask = mask; submask; submask = (submask - 1) & mask) {
                int total = 0;
                rep(i, 0, n) {
                    if (submask & (1 << i))
                        total += tasks[i];
                }
                if (total <= sessionTime) {
                    minSessionsRequired[mask] =
                        min(minSessionsRequired[mask],
                            1 + minSessionsRequired[mask ^ submask]);
                }
            }
        }

        return minSessionsRequired[maxMask - 1];
    }
};
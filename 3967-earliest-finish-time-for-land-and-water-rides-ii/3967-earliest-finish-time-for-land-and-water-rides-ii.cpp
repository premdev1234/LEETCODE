class Solution {
public:
    int MAX = 1e7 ;
    int earliestFinishTime(vector<int>& lst , vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int l = MAX, w = MAX, minL = MAX, minW = MAX;
        int n = (int)lst.size(), m = (int)wst.size();
        for (int i = 0; i < n; i++) l = min(l, lst[i] + ld[i]);
        for (int i = 0; i < m; i++) {
            w = min(w, wst[i] + wd[i]);
            minL = min(minL, max(wst[i], l) + wd[i]);
        }
        for (int i = 0; i < n; i++) minW = min(minW, max(lst[i], w) + ld[i]);
        return min(minW, minL);
    }
};
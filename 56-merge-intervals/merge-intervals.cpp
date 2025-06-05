class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        vector<int> interval;
        int last;

        for(int i = 0; i < intervals.size(); i++)
        {
            if(i == 0)
            {
                interval.push_back(intervals[i][0]);
                last = intervals[i][1];
                continue;
            }

            if(intervals[i][0] <= last)
            {
                last = max(intervals[i][1],last);
            }
            else
            {
                interval.push_back(last);
                result.push_back(interval);
                interval.clear();
                interval.push_back(intervals[i][0]);
                last = max(intervals[i][1],last);

            }
        }

        interval.push_back(last);
        result.push_back(interval);

        return result;
        
    }
};
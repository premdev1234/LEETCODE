class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        int len1 = s1.size(), len2 = s2.size();
        unordered_map<int, pair<int, int>> index_map;

        int s1_count = 0, s2_count = 0, s1_index = 0;
        while (s1_count < n1)
        {
            for (char c : s1)
            {
                if (c == s2[s1_index])
                {
                    s1_index++;
                    // one full s2 match
                    if (s1_index == len2)
                    {
                        s2_count++;
                        s1_index = 0;
                    }
                }
            }

            s1_count++;
            //  cycle detection
            if (index_map.count(s1_index))
            {
                auto [s1_prev_count, s2_prev_count] = index_map[s1_index];

                // cycle lengtha and repetitions
                int cycle_length = s1_count - s1_prev_count;
                int cycle_s2_count = s2_count - s2_prev_count;
                int remaining_cycle = (n1 - s1_count) / cycle_length;

                s2_count += remaining_cycle * cycle_s2_count;
                s1_count += remaining_cycle * cycle_length;
            }
            index_map[s1_index] = {s1_count, s2_count};
        }
        return s2_count / n2;
    }
};

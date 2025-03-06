class Solution
{
public:
    long long appealSum(string s)
    {
        // unordered_map<char, int> cache; // stores last occurance of a character
        int cache[26];
        fill(cache, cache + 26, -1); // not visited = -1
        long long curr = 0, total_appeal = 0;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            char c = s[i] - 'a'; // convert char to int between 0-25
            // if(cache.find(c) != cache.end()){
            //     curr += i - cache[c]  ;
            // } else {
            //     curr = i +1 ;
            // }
            // cache[c] = i;
            // total_appeal += curr;
            curr += (i - cache[c]);
            cache[c] = i;
            total_appeal += curr;
        }
        return total_appeal;
    }
};
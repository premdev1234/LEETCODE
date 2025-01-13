class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    if (s.empty() || words.empty()) {
            return {};
        }
        
        int word_length = words[0].size();
        int total_words = words.size();
        int substring_length = word_length * total_words;
        vector<int> result;
        unordered_map<string, int> word_count;

        for (const auto& word : words) {
            word_count[word]++;
        }

        for (int i = 0; i < word_length; i++) {
            int left = i, count = 0;
            unordered_map<string, int> temp_count;

            for (int right = i; right + word_length <= s.size(); right += word_length) {
                string word = s.substr(right, word_length);

                if (word_count.find(word) != word_count.end()) {
                    temp_count[word]++;
                    count++;

                    while (temp_count[word] > word_count[word]) {
                        string left_word = s.substr(left, word_length);
                        temp_count[left_word]--;
                        count--;
                        left += word_length;
                    }

                    
                    if (count == total_words) {
                        result.push_back(left);
                    }
                } else {
                    temp_count.clear();
                    count = 0;
                    left = right + word_length;
                }
            }
        }

        return result;
    }
};
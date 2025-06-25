class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int l1 = words1.size() , l2 =  words2.size();
        if(l1 < l2) return countWords(words2 , words1);
        int cnt =0 ;
        unordered_map<string,int> mp1 , mp2 ;
        for(string& word : words1) mp1[word]++;
        for(string& word : words2){
            if(mp1.find(word) != mp1.end() ) mp2[word]++;
        }
        for(auto [a,b] : mp2){
            if(b == 1 and mp1[a] == 1) cnt++;
        }
        return cnt;
    }
};
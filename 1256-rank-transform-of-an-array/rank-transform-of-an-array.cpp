class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> a ; unordered_map<int,int> rnk ;
        for(const int&num : arr)a.insert(num);
        int rank = 1;
        for(int num : a){
            rnk[num] = rank;
            rank++;
        } 
        for(int& num : arr) num = rnk[num];
        return move(arr);
    }
};
class Solution {
    vector<vector<int>> rects;
    vector<int> prefix;
    mt19937 rng;
public:
    vector<int> ans ;
    Solution(vector<vector<int>>& rects)  : rects(rects), rng(random_device{}()){
        prefix.reserve(rects.size());
        int points = 0 ;
        for(const auto& r : rects){
            points +=  (abs(r[2]-r[0])+1)*(abs(r[3]-r[1])+1);
            prefix.push_back(points);
        }

    }
    
    vector<int> pick() {
        uniform_int_distribution<int> dist(1,prefix.back());
        int random_point =  dist(rng);
        int index = lower_bound(prefix.begin(),prefix.end(),random_point)-prefix.begin();
        const auto& rectangle = rects[index];
        uniform_int_distribution<int> x_distribution(rectangle[0],rectangle[2]);
        uniform_int_distribution<int> y_distribution(rectangle[1],rectangle[3]);
        return {x_distribution(rng),y_distribution(rng)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
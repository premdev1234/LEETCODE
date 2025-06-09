class Solution {
public:
    int maxArea(vector<int>& height) {
        int n =  height.size();
        int l = 0 , r =  n-1 ;
        int water = INT_MIN;
        while(l < r){
            int curr =  (r-l)*min(height[l],height[r]); // water in current container
            water = max(curr,water) ; // replace water with curr if curr is greater then water
            if(height[l] <= height[r] ) l++; // of lower height then increment left position
            else r--;  // else decrease right pointer towards left
        }
        return water;
    }
};
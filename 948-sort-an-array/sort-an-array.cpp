class Solution {
public:
    int nextGap(int gap) {
        if (gap <= 1) return 0;
        return (gap / 2) + (gap % 2); // Ceiling of gap/2
    }
    void inPlaceMerge(vector<int>& arr, int start, int mid, int end) {
        int gap = end - start + 1;
        for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
            for (int i = start; i + gap <= end; ++i) {
                int j = i + gap;
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }
    void inPlaceMergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            inPlaceMergeSort(arr, l, mid);
            inPlaceMergeSort(arr, mid + 1, r);
            inPlaceMerge(arr, l, mid, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        inPlaceMergeSort(nums,0,nums.size()-1);
        return move(nums);
    }
};




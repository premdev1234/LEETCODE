class Solution {
public:
    void merge(vector<int>& A, int start, int mid, int end) {
        int n1 = (mid - start + 1);
        int n2 = (end - mid);
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
            L[i] = A[start + i];
        for (int j = 0; j < n2; j++)
            R[j] = A[mid + 1 + j];
        int i = 0, j = 0;
        for (int k = start; k <= end; k++) {
            if (j >= n2 || (i < n1 && L[i] <= R[j]))
                A[k] = L[i++];
            else
                A[k] = R[j++];
        }
    }

    int mergesort_and_count(vector<int>& A, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            int count = mergesort_and_count(A, start, mid) +
                        mergesort_and_count(A, mid + 1, end);
            int j = mid + 1;
            for (int i = start; i <= mid; i++) {
                while (j <= end && A[i] > A[j] * 2LL)
                    j++;
                count += j - (mid + 1);
            }
            merge(A, start, mid, end);
            return count;
        } else
            return 0;
    }

    struct node {
        int val, count_ge;
        node *left, *right;
        node(int val) : val(val), left(nullptr), right(nullptr) {
            count_ge = 1;
        }
    };
    node* insert(node* root, int val) {
        if (!root)
            return new node(val);
        else if (val == root->val)
            root->count_ge++;
        else if (val < root->val)
            root->left = insert(root->left, val);
        else
            root->count_ge++, root->right = insert(root->right, val);
        return root;
    }
    int search(node* root, long long target) {
        if (!root)
            return 0;
        else if (target == root->val)
            return root->count_ge;
        else if (target < root->val)
            return search(root->left, target) + root->count_ge;
        else
            return search(root->right, target);
    }

    int reversePairs(vector<int>& nums) {
        // brute force
        int n = nums.size();
        int r = 0;
        // for(int i = 0 ; i < n-1 ; ++i){
        //     for(int j = i+1 ; j < n ; ++j){
        //         if(nums[i] > 2LL*nums[j])r++;
        //     }
        // }
        // return r;
        // node*root = nullptr;
        // for(int i = 0 ; i < n ; i++){
        //     r += search(root,2LL*nums[i]+1);
        //     root = insert(root,nums[i]);
        // }
        // return r;
        return mergesort_and_count(nums, 0, n - 1);
    }
};
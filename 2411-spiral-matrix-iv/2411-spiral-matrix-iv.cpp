class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> result(m, vector<int>(n, -1));

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        bool flag = false;

        while(top <= bottom && left <= right) {

            for(int i = left; i <= right; ++i) {
                if(head) {
                    result[top][i] = head->val;
                    head = head->next;
                } else {
                    flag = true;
                    break;
                }
            }

            if(flag) break;
            ++top;

            for(int i = top; i <= bottom; ++i) {
                if(head) {
                    result[i][right] = head->val;
                    head = head->next;
                } else {
                    flag = true;
                    break;
                }
            }

            if(flag) break;
            --right;

            if(top <= bottom) {
                for(int i = right; i >= left; --i) {
                    if(head) {
                        result[bottom][i] = head->val;
                        head = head->next;
                    } else {
                        flag = true;
                        break;
                    }
                }
                --bottom;
            }

            if(flag) break;

            if(left <= right) {
                for(int i = bottom; i >= top; --i) {
                    if(head) {
                        result[i][left] = head->val;
                        head = head->next;
                    } else {
                        flag = true;
                        break;
                    }
                }
                ++left;
            }

            if(flag) break;
        }

        return result;
    }
};
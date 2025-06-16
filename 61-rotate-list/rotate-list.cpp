class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Count nodes
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k %= n;
        if (k == 0) return head;

        // Make the list circular
        tail->next = head;

        // Find new tail: (n - k - 1) steps from head
        ListNode* new_tail = head;
        for (int i = 0; i < n - k - 1; ++i) {
            new_tail = new_tail->next;
        }

        // Break the circle
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;

        return new_head;
    }
};

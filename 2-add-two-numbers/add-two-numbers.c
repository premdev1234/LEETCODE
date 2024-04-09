/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * addTwoNumbers(struct ListNode *num1, struct ListNode *num2) {
    struct ListNode *result = NULL;
    struct ListNode *current = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int sum = carry;
        if (num1 != NULL) {
            sum += num1->val;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            sum += num2->val;
            num2 = num2->next;
        }
        
        carry = sum / 10;
        sum %= 10;

        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = sum;
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return result;
}
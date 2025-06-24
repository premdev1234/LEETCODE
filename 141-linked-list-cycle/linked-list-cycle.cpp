/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head or !head-> next) return false;
        ListNode *fast = head ;
        while(fast->next and fast->next->next){
            fast = fast->next->next;
            head = head->next ;
            if(fast == head) return true;
        }
        return false;

    }
};
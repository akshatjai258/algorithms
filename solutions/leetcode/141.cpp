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
        set<ListNode*> nodes;
        
        while (head != nullptr) {
            if (nodes.count(head) != 0) {
                return true;
            } else {
                nodes.insert(head);
            }
            
            head = head->next;
        }
        
        return false;
    }
};
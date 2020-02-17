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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> values;
        ListNode* previous = nullptr;
        ListNode* current = head;
        
        while (current != nullptr) {
            if(values.count(current->val) != 0) {
                previous->next = current->next;
                delete current;
                
            } else {
                values.insert(current->val);
                previous = current;
                
            }
            current = previous->next;
            
        }
        
        
        return head;
        
    }
};
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
    ListNode* middleNode(ListNode* head) {
        int middle = 0;
        ListNode* current = head;
        
        while (head != nullptr) {
            head = head->next; 
            middle++;
        }
        
        middle = (middle / 2) + 1;
        
        while (current != nullptr && middle > 1) {
            current = current->next;
            middle--;

        }
        
        head = current;
            
        return head;
    }
};
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
    int getDecimalValue(ListNode* head) {
        int decimal_conversion = 0;
        
        while (head != nullptr) {             
            decimal_conversion = ((decimal_conversion * 2) + head->val);   
            head = head->next;
        }
             
        return decimal_conversion;
    }
};
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
    void deleteNode(ListNode* node) {
        while(node->next != nullptr){
            node->val = node->next->val;
            if(node->next->next == nullptr){
                ListNode* temp = node->next;
                node->next = nullptr;
                delete temp;
                return;
            }
            node = node->next;
        }
        return;
    }
};
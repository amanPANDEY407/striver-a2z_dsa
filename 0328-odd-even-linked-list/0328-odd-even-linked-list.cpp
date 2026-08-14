/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return head;
        }
        if(head->next->next == nullptr){
            return head;
        }
        ListNode* even = head->next;
        ListNode* even1 = head->next;
        ListNode* odd = head;
        while(odd != nullptr && even != nullptr && odd->next != nullptr && even->next != nullptr){
            odd->next =even->next;
            even->next =odd->next->next;
            odd->next->next = even1;
            odd = odd->next;
            even = even->next;
        }
        return head;
    }
};
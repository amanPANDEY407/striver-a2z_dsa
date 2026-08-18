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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i <= n; i++){
            if(fast != nullptr){
                fast = fast->next;
            }
            else{
                head = slow->next;
                delete slow;
                return head;
            }
        }
        while(fast!= nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        temp->next = nullptr;
        delete temp;
        return head;

    }
};
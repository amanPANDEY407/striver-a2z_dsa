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
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return nullptr;
        }
        ListNode* temp = head;
        int N = 0;
        while(temp != nullptr){
            N++;
            temp = temp->next;
        }
        temp = head;
        if(N == n){
            head = temp->next;
            temp->next= nullptr;
            delete temp;
            return head;
        }
        for(int i = 1; i < N - n; i++){
            temp = temp->next;
        }
        ListNode* a = temp->next;
        temp->next = temp->next->next;
        a->next = nullptr;
        delete a;
        return head;

    }
};
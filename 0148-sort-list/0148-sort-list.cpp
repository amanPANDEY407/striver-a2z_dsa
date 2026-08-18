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
    ListNode* merge2(ListNode* lefthead,ListNode* righthead){
        ListNode* tail = nullptr;
        ListNode* temp1 = nullptr;
        ListNode* head = nullptr;
        if(lefthead->val < righthead->val){
            head = lefthead;
            lefthead = lefthead->next;
        }
        else{
            head = righthead;
            righthead = righthead->next;
        }
        tail = head;
        while(lefthead != nullptr && righthead != nullptr){
            if(lefthead->val < righthead->val){
                tail->next = lefthead;
                lefthead = lefthead->next;
            }
            else{
                tail->next = righthead;
                righthead = righthead->next;
            }
            tail = tail->next;
        }
        if (lefthead != nullptr) {
        tail->next = lefthead;
        }
        else {
        tail->next = righthead;
        }
        return head;
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast != nullptr){
            slow = slow->next;
            if(fast->next == nullptr){
                fast = nullptr;
            }
            else{
                fast = fast->next->next;
            }
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* righthead = middle->next;
        middle->next = nullptr;
        ListNode* lefthead = head;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        return merge2(lefthead, righthead);
    }
};
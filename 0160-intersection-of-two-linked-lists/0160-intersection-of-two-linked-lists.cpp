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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }
        if(headA->next == nullptr && headB->next == nullptr){
            if(headA == headB){
                return headA;
            }
            else{
                return nullptr;
            }
        }
        ListNode* a = headA;
        ListNode* b = headB;
        int cnta = 0;
        int cntb = 0;
        while(a != b){
            if(a->next != nullptr){
                a = a->next;
            }
            else if(cnta == 0){
                a = headB;
                cnta = 1;
            }
            else{
                return nullptr;
            }
            if(b->next != nullptr){
                b = b->next;
            }
            else if(cntb == 0){
                b = headA;
                cntb = 1;
            }
            else{
                return nullptr;
            }
        }
        return a;
    }
};
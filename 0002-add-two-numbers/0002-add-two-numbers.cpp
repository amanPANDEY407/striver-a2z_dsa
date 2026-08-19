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
    ListNode* sumt(ListNode* a, ListNode* b){
        int carry = 0;
        ListNode* ans = a;
        ListNode* prev = nullptr;
        int z;
        while(a != nullptr){
            if(b != nullptr){
                z = (a->val + b->val + carry)%10;
                carry = (a->val + b->val + carry)/10;
                a->val = z;
                prev = a;
                a = a->next;
                b = b->next;
            }
            else if(carry != 0){
                z = (a->val + carry)%10;
                carry = (a->val + carry)/10;
                a->val = z;
                prev = a;
                a = a->next;
            }
            else{
                return ans;
            }
        }
        if(carry != 0){
            ListNode* node = new ListNode(carry);
            prev->next = node;
        }
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l11 = l1;
        ListNode* l22 = l2;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0 ; i < 100; i++){
            if(l1 != nullptr){
                cnt1++;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                cnt2++;
                l2 = l2->next;
            }
            if(l1 == nullptr && l2 == nullptr){
                break;
            }
        }
        if(cnt1 >= cnt2){
            return sumt(l11, l22);
        }else{
            return sumt(l22,l11);
        }
    }
};
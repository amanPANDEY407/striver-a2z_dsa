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
    int length(ListNode* head){
        int cnt = 0;
        while(head != nullptr){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = length(head);
        ListNode* temp = head;
        ListNode* a;
        ListNode* prev = nullptr;
        ListNode* lat = temp->next;
        ListNode* pres = temp;
        ListNode* hold = nullptr;
        for(int i = 0 ; i < (n/k)*k; i++){
            a = temp;
            for(int j = 0; j < k; j++){
                a = a->next;
                i++;
            }
            i--;
            if(temp->next == a){
                return head;
            }
            /*if(temp->next->next == a){
                if(i/k == 0){
                    head = temp->next;
                }
                temp->next->next = temp;
                temp->next = a;
                temp = a;
                continue;
            }*/
            while(pres!= a){
                pres->next = prev;
                prev = pres;
                pres = lat;
                if(lat != nullptr) lat = lat->next;
            }
            if(i/k == 0){
                    head = prev;
             }
             if(hold != nullptr){
                hold->next = prev;
             }
             hold = temp;
            temp->next = a;
            temp =a;
            prev = nullptr;
        }
        return head;
    }
};
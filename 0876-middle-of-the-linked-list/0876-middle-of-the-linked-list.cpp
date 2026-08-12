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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        cnt = (cnt + 2)/2;
        temp = head;
        for(int i = 1; i < cnt; i++){
            temp = temp->next;
        }
        return temp;
    }
};
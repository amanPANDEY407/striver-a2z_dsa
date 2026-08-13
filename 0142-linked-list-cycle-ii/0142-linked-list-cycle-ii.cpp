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
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp = head;
        ListNode *tort = head;
        ListNode *hare = head;
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        while(hare!= nullptr && hare->next != nullptr){
            tort = tort->next;
            hare = hare->next->next;
            if(hare == tort){
                break;
            }
        }
    if(hare == tort){
      tort = temp;
      while(tort != hare){
        tort = tort->next;
         hare = hare->next;
         }
         return tort;
      }
      return nullptr;
    }
};
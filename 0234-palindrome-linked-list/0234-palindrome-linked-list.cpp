class Solution {
public:
    bool isPalindrome(ListNode *head) {
        // Base case: an empty list or single node is a palindrome
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        // 1. Find the middle of the linked list
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. Reverse the second half of the list
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        while (curr != nullptr) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // 3. Compare the first half and the reversed second half
        ListNode *p1 = head;
        ListNode *p2 = prev; // 'prev' is now the head of the reversed half
        
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return true;
    }
};
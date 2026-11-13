class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* subTail = curr;
        ListNode* prevNode = nullptr;

    
        for (int i = 0; i <= right - left; i++) {
            ListNode* next = curr->next;

            curr->next = prevNode;
            prevNode = curr;
            curr = next;
        }

    
        prev->next = prevNode;
        subTail->next = curr;

        return dummy.next;
    }
};

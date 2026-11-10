class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode lessDummy(0);
        ListNode greaterDummy(0);

        ListNode* less = &lessDummy;
        ListNode* greater = &greaterDummy;

        ListNode* curr = head;

        while (curr != nullptr) {

            if (curr->val < x) {
                less->next = curr;
                less = less->next;
            }
            else {
                greater->next = curr;
                greater = greater->next;
            }

            curr = curr->next;
        }

        greater->next = nullptr;

        less->next = greaterDummy.next;

        return lessDummy.next;
    }
};
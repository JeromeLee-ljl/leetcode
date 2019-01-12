// Given a linked list, rotate the list to the right by k places, where k is non-negative.

// Example 1:
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL

// Example 2:
// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL

struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || k < 0) return NULL;
    int len = 1;
    struct ListNode *end, *new_end, *new_head;
    end = new_end = head;
    for (; end->next != NULL; end = end->next) len++;

    if (k % len == 0) return head;
    for (int i = k % len + 1; i < len; i++) {
        new_end = new_end->next;
    }
    new_head = new_end->next;
    new_end->next = NULL;
    end->next = head;
    return new_head;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) 
            return true;
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = head;
    while (ptr2->next != NULL && ptr2->next->next != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    struct ListNode* prev = NULL;
    struct ListNode* curr = ptr1->next;
    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    struct ListNode* p1 = head;
    struct ListNode* p2 = prev;
    while (p2 != NULL) {
        if (p1->val != p2->val) 
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

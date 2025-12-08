/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return false;
    struct ListNode *temp1 = head;
    struct ListNode *temp2 = head;
    while (temp1 != NULL && temp1->next != NULL) {
        temp2 = temp2->next;
        temp1 = temp1->next;
        temp1 = temp1->next;
        if (temp1 == temp2)
            return true;
    }
    return false;
}

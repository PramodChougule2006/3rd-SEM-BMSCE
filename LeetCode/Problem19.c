/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* ptr = head;
    int count = 0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    if(count==1 && n==1)
    {
        free(head);
        return NULL;
    }
    if(count==n)
    {
        struct ListNode* temp = head;
        head=head->next;
        free(temp);
        return head;
    }
    int i=1;
    struct ListNode* prev = head;
    struct ListNode* ptr1 = head->next;
    while(i<count-n)
    {
        prev=ptr1;
        ptr1=ptr1->next;
        i++;
    }
    prev->next=ptr1->next;
    free(ptr1);
    return head;
}

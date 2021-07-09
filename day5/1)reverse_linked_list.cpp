// https://leetcode.com/problems/reverse-linked-list/
// Time: O(n)
// Space: O(1)
// Iterative:
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev=NULL;
    ListNode* next;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
// Recursive:
ListNode* reverse(ListNode* head)
{
    if(head==NULL || head->next==NULL)  return head;
    ListNode* temp = reverse(head->next);
    head->next->next = head;
    head->next=NULL;
    return temp;
}
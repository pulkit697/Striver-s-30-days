// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Time: O(n)
// Space: O(1)
// Iterative:
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head,*slow=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(!fast)
        return head->next;
    while(fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next = slow->next->next;
    return head;
}
// Recursive:
ListNode* remove(ListNode* head,int& k)
{
    if(head==NULL)
        return head;
    head->next=remove(head->next,k);
    k--;
    if(k == 0)
        return head->next;
    return head;
}
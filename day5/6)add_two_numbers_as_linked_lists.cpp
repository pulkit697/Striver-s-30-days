// https://leetcode.com/problems/add-two-numbers/
// Time: O(n)
// Space: O(1)
// Way 1:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = 0;
    int x = 0;
    ListNode* prev=NULL;
    ListNode* head = l1;
    while(l1 && l2)
    {
        x = l1->val + l2->val + c;
        l1->val = x%10;
        c = x/10;
        prev = l1;
        l1=l1->next;
        l2=l2->next;
    }
    while(l1){
        x = l1->val + c;
        l1->val = x%10;
        c=x/10;
        prev=l1;
        l1=l1->next;
    }
    prev->next=l2;
    while(l2){
        x = l2->val + c;
        l2->val = x%10;
        c=x/10;
        prev=l2;
        l2=l2->next;
    }
    if(c){
        prev->next = new ListNode(c);
    }
    return head;
}
// Way 2:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = 0;
    ListNode* ptr = new ListNode(0);
    ListNode* head = ptr;
    int sum=0;
    while(l1 || l2 || c)
    {
        sum = c;
        if(l1){
            sum+=l1->val;
        }
        if(l2){
            sum+=l2->val;
        }
        c = sum/10;
        sum = sum%10;
        if(l1){
            l1->val = sum;
            ptr->next = l1;
        }
        else if(l2){
            l2->val = sum;
            ptr->next = l2;
        }
        else{
            ptr->next = new ListNode(sum);
        }
        if(l1)
            l1=l1->next;
        if(l2)
            l2=l2->next;
        ptr=ptr->next;
    }
    return head->next;
}
// https://leetcode.com/problems/merge-two-sorted-lists/
// Time: O(n)
// Space: O(1)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode();
        ListNode* ptr=head;
        while(l1 && l2){
            if(l1->val<=l2->val){
                ptr->next = l1;
                l1=l1->next;
            }else{
                ptr->next = l2;
                l2=l2->next;
            }
            ptr=ptr->next;
        }
        while(l1){
            ptr->next=l1;
            l1=l1->next;
            ptr=ptr->next;
        }
        while(l2){
            ptr->next=l2;
            l2=l2->next;
            ptr=ptr->next;
        }
        return head->next;
    }
// https://leetcode.com/problems/delete-node-in-a-linked-list/
// Time: O(1)
// Space: O(1)
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
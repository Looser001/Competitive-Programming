//https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // loop through each element of the lists
        // if list1 exists but list2 does not OR if list1->val < list2->val, then the next sentinel value will equal list1
        // otherwise apply same functionality to list 2
        ListNode* sentinel = new ListNode(-1);
        ListNode* tmp = sentinel;
        
        while(list1 || list2) {
            if ((list1 && !list2) || (list1 && list2 && list1->val < list2->val)) {
                tmp->next = list1;
                list1 = list1->next;
            } else if ((!list1 && list2) || (list1 && list2 && list1->val >= list2->val)) {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;
        }
        return sentinel->next;  
    }
};

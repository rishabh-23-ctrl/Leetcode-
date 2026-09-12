/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* curr1 = first;
        ListNode* temp1 = first->next;
        ListNode* curr2 = second;

        while(temp1 != NULL && curr2 != NULL){
            if((curr2->val >= curr1->val) && (curr2->val <= temp1->val)){
                ListNode* temp2 = curr2->next;
                curr2->next = temp1;
                curr1->next = curr2;
                curr1 = curr2;
                curr2 = temp2;
                //temp1 = temp1->next;
            }
            else{
                curr1 = temp1;
                temp1 = temp1->next;
            }
        }
        if(curr2 != NULL) curr1->next = curr2;
        return first;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        //if first node of list1 is <= to first node of list2
        if(list1->val <= list2->val){
            return merge(list1, list2);
        }

        //if first node of list2 is <= to first node of list2
        else{
            return merge(list2, list1);
        }

    }
};
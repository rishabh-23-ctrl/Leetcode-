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
        ListNode* next1 = first->next;
        ListNode* curr2 = second;

        while(next1 != NULL && curr2 != NULL){
            //if(curr2->next != NULL) next2 = curr2->next;
            if((curr2->val >= curr1->val) && (curr2->val <= next1->val)){
                ListNode* next2 = curr2->next;
                curr1->next = curr2;
                curr2->next = next1;
                curr1 = curr2;
                curr2 = next2; 
            }
            else{
                curr1 = next1;
                next1 = next1->next;
            }
        }
        if(curr2 != NULL) curr1->next = curr2;
        return first;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;  //lis1 is empty
        if(list2 == NULL) return list1;   //list2 is empty

        if(list1->val <= list2->val){
           return merge(list1, list2);
        }
        else return merge(list2, list1);

    }
};
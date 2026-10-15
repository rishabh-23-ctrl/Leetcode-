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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *curr = head;
        while(curr -> next != NULL){
            ListNode *temp = curr->next;
            if(curr->val == curr->next->val){
                curr->next = temp->next;  //remove duplicate
                delete temp;   //deleting duplicate node
            }
            else{
                curr = curr->next;    //moving forward
            }
        }
        return head;
    }
};
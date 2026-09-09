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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        if(head == NULL){
            return head;
        }
        ListNode* temp = head;
        //to check no. of nodes is group is upto k or not
        for(int i = 0; i < k; i++){
            if(temp == NULL) return head;
            temp = temp->next;
        }

        //reverse first group
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* frwd = NULL;
        int cnt = 0;
        while(curr && cnt < k){
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
            cnt++;
        }

        //Connect node of another group
        head->next = reverseKGroup(curr, k);   //recursive call to reverse other groups also
        return prev;
    }
};
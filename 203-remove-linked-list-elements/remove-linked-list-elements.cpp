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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)return head;
        while(head && head->val == val){head= head->next;}
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            while(temp->next &&temp->next->val == val)
            {
                if(temp->next->next != NULL){temp->next = temp->next->next;}
                else {temp->next = NULL;}
            }
            temp = temp->next;
        }
        return head;
        
    }
};
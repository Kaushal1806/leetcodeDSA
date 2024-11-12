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
        ListNode * temp = head;
        if(head == NULL )return head;
        while(temp->next != NULL )
        {
            while(temp->val == temp->next->val)
            {
                if(temp->next->next){
                    temp->next = temp->next->next;
                }
                else{
                    temp->next = NULL;
                    return head;
                }

            }
            temp = temp->next;
        }
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /* here we are using hash map where we are entering each element 
        one by one by traversal and if particular element is already present 
        in map then we will return true or false after traversal of whole loop

        //brute force 
        map<ListNode*,int>mpp;
        ListNode* temp=head;
        while(temp != NULL)
        {
            if(mpp.find(temp) != mpp.end() )
            {
                return true;
            }
            mpp[temp]=1;
            temp=temp->next;
        }
        return false;
        */
        /* by  using tortoise-Hare method 
        here we are moving slow by one and fast by two and if fast and slow 
        comes at same location then we return true*/
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast != NULL && fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
        
    }
};
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
    ListNode *detectCycle(ListNode *head) {
        /*
        // using hash map
        here if we are putting value in map and check if any element is already
        present in map then we are returning the temp and if we are not getting 
        then we are returnnig NULL after traversal of every node

        map<ListNode*,int>mpp;
        ListNode* temp=head;
        while( temp != NULL)
        {
            if(mpp.find(temp) != mpp.end())
            {
                return temp;
            }
            mpp[temp]=1;
            temp=temp->next;
        }
        return NULL;
        */
        /*Tortoise-Hare method
        step 1:- detecting wheteher it is present or not
        step 1:- now we are checking for starting point of loop*/
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast != NULL && fast->next != NULL)   // traversing till we reach last element
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast)    // checking if there is loop
            {
                slow = head;    // assigning slow to head
                while(slow != fast)     // traversing till slow and fast become equal
                {   // we are moving fast and slow by one step
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        
        }
        return NULL;

    }
};
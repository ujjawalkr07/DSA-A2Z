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
    ListNode* reverseList(ListNode* head) {
        /*
        //using stack:- comping all data into stack and then again copying     back to linked list
        t.c=O(n)+O(n)   // for copying into stack and then copying back into linked list 
        s.c=O(n)    // for using extra stack
        ListNode* temp=head;
        stack<int>st;
        while(temp != NULL)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp != NULL)
        {
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
        */
        //by exchanging the curr and back pointer 
        ListNode* curr=head;
        ListNode* back=NULL;
        while(curr != NULL)
        {
            ListNode* front=curr->next;
            curr->next=back;
            back=curr;
            curr=front;

        }
        return back;
    }
};
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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=1;
        while(temp != NULL)
        {
            count++;
            temp=temp->next;
        }
        temp=head;
        if(count%2 == 0)
        {
            int cnt=1;
            while(cnt != (count)/2)
            {
                cnt++;
                temp=temp->next;
                
            }
        }
        else
        {
            int cnt1=1;
            while(cnt1 != (count+1)/2)
            {
                cnt1++;
                temp=temp->next;
            }
        }
        return temp;
    }
};
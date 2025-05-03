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

// version 1
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        while(head) {
            values.push_back(head->val);
            head=head->next;
        }
        int maximum=INT_MIN;
        int n = values.size();
        for(int i=0; i<n/2; i++) {
            maximum=max(maximum, values[i]+values[n-i-1]);
        }
        return maximum;
    }
};

// version 2
/*
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int maximum=INT_MIN;

        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* reversed=nullptr;
        ListNode* cur=slow;
        ListNode* cur_next=slow->next;
        while(cur) {
            cur_next = cur->next;
            cur->next=reversed;
            reversed = cur;
            cur = cur_next;;
        }

        cur = head;
        while(reversed) {
            maximum=max(maximum, cur->val+reversed->val);
            cur=cur->next;
            reversed=reversed->next;
        }
        return maximum;
    }
};
*/

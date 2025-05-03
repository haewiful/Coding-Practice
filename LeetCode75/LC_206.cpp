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
        if(head==nullptr) return nullptr;
        ListNode* reversed = new ListNode(head->val);
        ListNode* cur = reversed;
        head = head->next;
        while(head!=nullptr) {
            ListNode* tmp = head->next;
            head->next = reversed;
            reversed=head;
            head=tmp;
        }
        return reversed;
    }
};

// version 2
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* reversed = nullptr;
        while(head) {
            reversed = new ListNode(head->val, reversed);
            head=head->next;
        }
        return reversed;
    }
};
*/

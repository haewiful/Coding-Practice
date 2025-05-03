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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* last_odd = head;
        ListNode* current = head;
        if(current!=nullptr) current = current->next;
        
        while(current!=nullptr && current->next!=nullptr) {
            ListNode* tmp=last_odd->next;
            last_odd->next=current->next;
            last_odd=last_odd->next;
            ListNode* next_cur = current->next->next;
            current->next=next_cur;
            current=next_cur;
            last_odd->next = tmp;
        }
        return head;
    }
};

// version1
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
    ListNode* deleteMiddle(ListNode* head) {
        int n=0;
        ListNode* pre_middle=nullptr;
        ListNode* current = head;
        while(current!=nullptr) {
            n++;
            if(n%2==0) {
                if(pre_middle==nullptr) {
                    pre_middle=head;
                } else {
                    pre_middle=pre_middle->next;
                }
            }
            current = current->next;
        }
        if(pre_middle==nullptr) return nullptr;

        ListNode* del = pre_middle->next;
        pre_middle->next = del->next;
        delete del;
        return head;
    }
};

// version 2
/*
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        int n=0;
        ListNode* pre_middle=head;
        ListNode* current = head->next->next;
        while(current!=nullptr && current->next!=nullptr) {
            pre_middle = pre_middle->next;
            current=current->next->next;
        }
        ListNode* del = pre_middle->next;
        pre_middle->next = del->next;
        delete del;

        return head;
    }
};
*/


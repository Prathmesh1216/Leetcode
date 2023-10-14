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
    int len(ListNode* head){
        if(head==NULL) return 0;
        return 1 + len(head->next);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int l = len(head);
        if(n==l) return head->next;
        int a = l-n-1;
        while(a--){
            head= head->next;
        }
        head->next = head->next->next;
        return temp;
    }
};
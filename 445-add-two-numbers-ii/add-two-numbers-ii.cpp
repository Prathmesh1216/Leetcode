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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1,v2;
        while(l1!=NULL){
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        vector<int> v;
        ListNode* ans = new ListNode();
        ListNode* t = ans;
        int cry = 0;
        int i = 0;
        int j = 0;
        while(i<v1.size() && j<v2.size()){
            v.push_back((v1[i]+v2[j]+cry)%10);
            cry = (v1[i]+v2[j]+cry)/10;
            i++;
            j++;
        }
        while(i<v1.size()){
            v.push_back((v1[i]+cry)%10);
            cry = (v1[i]+cry)/10;
            i++;
        }
        while(j<v2.size()){
            v.push_back((v2[j]+cry)%10);
            cry = (v2[j]+cry)/10;
            j++;
        }
        if(cry==1) v.push_back(1);
        int k = v.size()-1;
        //ListNode* prev = new ListNode();
        while (k >= 0) {
    t->val = v[k];
    k--;
    if (k >= 0) {
        ListNode* tt = new ListNode();
        t->next = tt;
        t = t->next;
    }
}
        return ans;

    }
};
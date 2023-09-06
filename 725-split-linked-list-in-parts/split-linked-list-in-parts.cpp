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
        ListNode* temp = head;
        int ans = 0;
        while(temp!=NULL){
            ans ++;
            temp = temp->next;
        }
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int n = len(head);
       // cout << n << endl;
        if(n<=k){
            ListNode* temp = head;
            while(n>0){
                ListNode* t = new ListNode(temp->val);
                ans.push_back(t);
                temp = temp->next;
                n--;
                k--;
            }
            while(k--){
                ans.push_back(NULL);
            }
            return ans;
        }
        vector<int> ls(k,n/k);
        int a = n%k;
        int i = 0;
        while(a>0){
            ls[i]++;
              i++;
              a--;
        }
      //  for(auto it : ls) cout << it << endl;
        ListNode* temp = head;
        for(int j = 0;j<k;j++){
            ListNode* t = new ListNode(temp->val);
            temp = temp->next;
            ListNode* h1 = t;
            ls[j]--;
            while(temp!=NULL && ls[j]>0){
                ListNode* t1 = new ListNode(temp->val);
                temp = temp->next;
                t->next = t1;
                t = t1;
                ls[j]--;
            }
            ans.push_back(h1);
        }
        return ans;

        
    }
};
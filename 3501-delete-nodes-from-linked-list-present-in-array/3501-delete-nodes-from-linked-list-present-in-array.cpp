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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<int> ans;
        ListNode* temp = head;
        while(temp!=NULL){
            if(mp[temp->val]==0){
                ans.push_back(temp->val);
            }
            temp =temp->next;
        }
        ListNode* root = head;
        for(int i=0; i<ans.size(); i++){
            if(i==ans.size()-1) root->next = NULL;
            root->val = ans[i];
            root = root->next;
        }
        return head;
    }
};
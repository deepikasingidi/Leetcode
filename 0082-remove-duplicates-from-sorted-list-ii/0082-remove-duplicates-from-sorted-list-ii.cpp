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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> vec;
        map<int, int> mp;
        ListNode* temp = head;
        while(temp!=NULL){
            mp[temp->val]++;
            temp = temp->next;
        }
        for(auto it:mp){
            if(it.second==1) vec.push_back(it.first);
        }
        ListNode *root = NULL, *temp1 = NULL;
        for(int i=0; i<vec.size(); i++){
            ListNode* node = new ListNode(vec[i]);
            if(root==NULL && temp1==NULL){
                root = temp1 = node;
            }
            else{
                temp1->next = node;
                temp1 = node;
            }
        }
        return root;
    }
};
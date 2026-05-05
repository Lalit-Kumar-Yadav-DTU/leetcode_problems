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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* tail = head;
        int cnt = 1;
        while(tail->next){
            tail = tail->next;
            cnt++;
        }
        k = k%cnt;
        if(k==0) return head;
        int steps = cnt-k-1;
        ListNode* curr = head;
        while(steps){
            curr = curr->next;
            steps--;
        } 
        ListNode* newhead = curr->next;
        tail->next = head;
        curr->next = NULL;
        return newhead;
    }
};
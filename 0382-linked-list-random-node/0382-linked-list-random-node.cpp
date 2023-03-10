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
    int len=0;
    ListNode * headNode;
public:
    Solution(ListNode* head) {
        headNode=head;
        ListNode *temp=headNode;
        while(temp){
            len++;
            temp=temp->next;
        }
    }
    
    int getRandom() {
        int rand_index=rand()%len;
        ListNode* temp=headNode;
        for(int i=0;i<rand_index;i++)
        {
            temp=temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
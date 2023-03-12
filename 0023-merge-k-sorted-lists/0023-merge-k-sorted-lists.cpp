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

    ListNode* mergeTwoSortedlists(ListNode* l1, ListNode * l2)
    {
        if(!l1) return l2;
        if(l2==NULL) return l1;

        if(l1->val < l2->val)
        {
            l1->next=mergeTwoSortedlists(l1->next,l2);
            return l1;
        }
        else
        {
                 l2->next=mergeTwoSortedlists(l1,l2->next);
            return l2;
        }
        return NULL;
    }    


    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>&lists )
    {
        if(start>end)
        {
            return NULL;
        }
         if(start==end)
        {
            return lists[start];
        }
        int mid=start+(end-start)/2;
      ListNode*  L1=partitionAndMerge(start,mid,lists);
       ListNode*  L2=partitionAndMerge(mid+1,end,lists);

        return mergeTwoSortedlists(L1,L2);

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();

        if(k==0)
        return NULL;

        return partitionAndMerge(0,k-1,lists);
    }
};
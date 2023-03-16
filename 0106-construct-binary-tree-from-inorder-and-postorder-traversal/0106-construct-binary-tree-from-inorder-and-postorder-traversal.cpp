/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBT(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if(inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int root_candidate = root->val;
        int i = inStart;
      
        //YOu can optimize this by storing index of inorder values in a map for direct access
        for(; i<=inEnd; i++) {
            if(inorder[i] == root_candidate) {
                break;
            }
        }
        int leftSize  = i-inStart;
        int rightSize = inEnd-i;
      
        root->left = buildBT(inorder, postorder, inStart, i-1, postStart, postStart+leftSize-1);
        root->right  = buildBT(inorder, postorder, i+1, inEnd, postEnd-rightSize, postEnd-1);
      
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = NULL;
        int n          = postorder.size();
        int inStart    = 0;
        int inEnd      = n-1;
        int postStart  = 0;
        int postEnd    = n-1;
        root           = buildBT(inorder, postorder, inStart, inEnd, postStart, postEnd);
        return root;
    }
};
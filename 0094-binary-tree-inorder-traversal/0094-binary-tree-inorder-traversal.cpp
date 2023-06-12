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
    void solve(TreeNode*root,vector<int>&in){
        if(root==NULL)return;
         if(root->left)solve(root->left,in);
         in.push_back(root->val);
        if(root->right)solve(root->right,in);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>in;
        solve(root,in);
        return in;
    }
};
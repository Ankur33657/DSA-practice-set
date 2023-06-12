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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v1;
        if(root==NULL)return v1;
        
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size();
            vector<int>vec;
            while(size--){
           
             TreeNode*res=qu.front();
          vec.push_back(res->val);
            qu.pop();
            if(res->left)qu.push(res->left);
            if(res->right)qu.push(res->right);
            }
             v1.push_back(vec);
        }
       
        return v1;
    }
};
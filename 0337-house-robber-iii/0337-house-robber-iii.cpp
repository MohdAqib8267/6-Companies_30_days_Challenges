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
    unordered_map<TreeNode*,int>mp;
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
          if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        if(root->left==NULL and root->right==NULL){
            return root->val;
        }
        //if we take the current root then we can take in next step, grandchild child of this root
        int take = root->val;
       if(root->left){  
        take+=solve(root->left->left)+solve(root->left->right);
        }
        if(root->right){
        take+=solve(root->right->left)+solve(root->right->right);
        }
        
        //if we dont take current root then we can take child root
        int not_take = solve(root->left)+solve(root->right);
        return mp[root]=max(take,not_take);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};
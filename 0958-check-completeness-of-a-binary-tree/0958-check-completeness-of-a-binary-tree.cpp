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
    bool isCompleteTree(TreeNode* root) {
         queue<TreeNode*> q;
        q.push(root);
        vector<int>v;
        while(!q.empty()) {
            TreeNode *disc = q.front();
            q.pop();
            if(disc) {
                v.push_back(disc->val);
            } else {
                v.push_back(-1);
                continue;
            }
            q.push(disc->left);
            q.push(disc->right);
        }
       bool flag = false;
        for(auto &i: v) {
            if(!flag and i==-1) flag = true;
            else if(flag and i!=-1) return false;
        }
        return true;
    }
};
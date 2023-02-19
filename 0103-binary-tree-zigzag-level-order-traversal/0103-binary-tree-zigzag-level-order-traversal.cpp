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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        int flag=-1;
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                temp.push_back(node->val);
                
                    if(node->right!=NULL){
                        q.push(node->right);
                    }
                    if(node->left!=NULL){
                        q.push(node->left);
                    }
                    q.pop();
            }
            if(flag==-1){
                reverse(temp.begin(),temp.end());
            }
            flag=-1*flag;
            ans.push_back(temp);
          
        }
        return ans;
    }
};
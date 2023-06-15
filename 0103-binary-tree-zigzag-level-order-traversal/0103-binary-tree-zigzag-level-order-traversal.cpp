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
        if(root==NULL) return ans;
      int flag=-1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++){
                TreeNode* p = q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->right){
                    q.push(p->right);
                }
                if(p->left){
                    q.push(p->left);
                }
                
            }
            if(flag==-1){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
           flag=-1*flag;
        }
        return ans;
    }
};
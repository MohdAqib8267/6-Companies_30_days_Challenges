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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        if(root==NULL){
            return 0;
        }
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            int first,last;
            for(int i=0;i<sz;i++){
                auto p=q.front();
                q.pop();
                TreeNode* node=p.first;
                int pos=p.second;
                if(i==0){
                    first=pos;
                }
                if(i==sz-1){
                    last=pos;
                }
                if(node->left){
                    q.push({node->left,(long long)2*pos+1});
                }
                if(node->right){
                    q.push({node->right,(long long)2*pos+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
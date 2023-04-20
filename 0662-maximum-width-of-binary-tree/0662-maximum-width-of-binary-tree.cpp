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
        if(root==NULL){
            return 0;
        }
        int ans=INT_MIN;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            auto p=q.front();
            int mn=p.second;
            int first, last;
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front().first;
                int curr = q.front().second-mn;
                q.pop();
                
                if(i==0){
                    first = curr;
                }
                if(i==sz-1){
                    last = curr;
                }
                if(node->left != NULL){
                    q.push({node->left,(long long)2*curr+1});
                }
                if(node->right != NULL){
                    q.push({node->right,(long long)2*curr+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
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
    int idx=0;
    TreeNode* solve(int st,int en,vector<int>& preorder,vector<int>& inorder){
        if(st>en) return NULL;
        
        int curr = preorder[idx];
        idx++;
        TreeNode* root=new TreeNode(curr);
        
        int pos;
        for(int i=st;i<=en;i++){
            if(inorder[i]==curr){
                pos=i;
                break;
            }
        }
        root->left=solve(st,pos-1,preorder,inorder);
        root->right=solve(pos+1,en,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(0,preorder.size()-1,preorder,inorder);
    }
};
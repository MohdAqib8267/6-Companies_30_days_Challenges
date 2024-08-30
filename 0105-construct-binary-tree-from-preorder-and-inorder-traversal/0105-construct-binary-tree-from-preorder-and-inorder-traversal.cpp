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
    int position(int st,int en,vector<int>&inorder,int value){
        for(int i=st;i<=en;i++){
            if(inorder[i]==value){
                return i;
            }
        }
        return -1;
    }
    TreeNode* construct(int st,int en,vector<int>& preorder, vector<int>& inorder){
        if(st>en){
            return NULL;
        }
        int value = preorder[idx++];
        int pos = position(st,en,inorder,value);
        TreeNode* root = new TreeNode(value);
        root->left = construct(st,pos-1,preorder,inorder);
        root->right = construct(pos+1,en,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return construct(0,n-1,preorder,inorder);
    }
};
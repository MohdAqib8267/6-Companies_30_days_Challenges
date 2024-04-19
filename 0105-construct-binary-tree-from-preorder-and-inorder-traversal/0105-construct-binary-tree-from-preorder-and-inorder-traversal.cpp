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
    int findPos(int val,int st,int en,vector<int>&inorder){
        for(int i=st;i<=en;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    int idx=0;
    TreeNode* solve(int st,int en,vector<int>& preorder, vector<int>& inorder){
        if(st>en){
            return NULL;
        }
        int currNode=preorder[idx];
        idx++;
        if(st==en){
            return new TreeNode(currNode);
        }
        TreeNode* root=new TreeNode(currNode);
        int pos=findPos(currNode,st,en,inorder);
        root->left=solve(st,pos-1,preorder,inorder);
        root->right=solve(pos+1,en,preorder,inorder);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
            TreeNode* root=solve(0,preorder.size()-1,preorder,inorder);
            
           return root;
            
        
    }
};
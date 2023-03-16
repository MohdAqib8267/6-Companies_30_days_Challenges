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
    TreeNode* construct(int st,int en,int &idx,vector<int>& inorder,vector<int>& postorder){
        if(st>en){
            return NULL;
        }
        int val = postorder[idx];
        idx--;
        TreeNode* root = new TreeNode(val);
        if(st==en){
            return root;
        }
        int pos;
        for(int i=st;i<=en;i++){
            if(inorder[i]==val){
                pos = i;
                break;
            }
        }
        root->right = construct(pos+1,en,idx,inorder,postorder);
        root->left = construct(st,pos-1,idx,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int st=0;
        int en=inorder.size()-1;
        
        int idx=postorder.size()-1;
        return construct(st,en,idx,inorder,postorder);
    }
};
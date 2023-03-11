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
    void DFS(TreeNode* root,unordered_map<int,int>&left,unordered_map<int,int>&right){
       
        if(left.find(root->val)!=left.end()){
            TreeNode* node = new TreeNode(left[root->val]);
            root->left=node;
            DFS(node,left,right);
        }
        if(right.find(root->val)!=right.end()){
            TreeNode* node = new TreeNode(right[root->val]);
            root->right=node;
            DFS(node,left,right);
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        int n=desc.size();
        unordered_map<int,int>parent;
        unordered_map<int,int>left;
        unordered_map<int,int>right;
       
        for(int i=0;i<n;i++){
          
            parent[desc[i][1]]=desc[i][0];
            if(desc[i][2]==1){
                left[desc[i][0]]=desc[i][1];
            }
            else{
                right[desc[i][0]]=desc[i][1];
            }
        }
        
        int rt;
        
        for(auto it:parent){
            if(parent.find(it.second)==parent.end()){
                rt=it.second;
            }
           
        }
        TreeNode* root=new TreeNode(rt);
        
        //Like DFS
       
         DFS(root,left,right);
        return root;
    }
};
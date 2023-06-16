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
    vector<TreeNode*> buildTrees(int st,int en){
        vector<TreeNode*>ans;
        if(st>en){
            ans.push_back(NULL);
            return ans;
        }
            // Iterate through all values from start to end to construct left and right subtree recursively
        for(int i=st;i<=en;i++){
             vector<TreeNode*>leftSubTrees = buildTrees(st,i-1);
             vector<TreeNode*>rightSubTrees = buildTrees(i+1,en);    
            // loop through all left and right subtrees and connect them to ith root  
            for(int j=0;j<leftSubTrees.size();j++){
                for(int k=0;k<rightSubTrees.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSubTrees[j];
                    root->right = rightSubTrees[k];
                    ans.push_back(root);
                }
            }
        }
       return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
       return buildTrees(1,n);
    }
};
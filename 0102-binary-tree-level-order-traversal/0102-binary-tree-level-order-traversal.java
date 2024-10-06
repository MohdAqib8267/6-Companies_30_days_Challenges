/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode>q = new LinkedList<TreeNode>();
        q.add(root);
       
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
         if(root==null){
            return ans;
        }
        while(!q.isEmpty()){
            int sz = q.size();
            List<Integer>temp = new ArrayList<Integer>();
            for(int i=0;i<sz;i++){
                TreeNode node = q.peek();
                q.remove();
                temp.add(node.val);
                if(node.left != null){
                    q.add(node.left);
                }
                if(node.right != null){
                    q.add(node.right);
                }
            }
            ans.add(temp);
        }
        return ans;
    }
}
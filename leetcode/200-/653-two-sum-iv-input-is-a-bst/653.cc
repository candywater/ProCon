/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

  bool findTarget(TreeNode* root, int k) {
    return dfs(root, k, root);
  }

  bool dfs(TreeNode* now, int k, TreeNode* root){
    if(now == NULL) return false;
    return
      search(root, k - now->val, now)
      || dfs(now->right, k, root)
      || dfs(now->left, k, root);
  }

  bool search(TreeNode* root, int target, TreeNode* srcnode){
    if(root == NULL) return false;
    if(target < root->val) return search(root->left, target, srcnode);
    else if(target > root->val) return search(root->right, target, srcnode);
    else if(root == srcnode) return search(root->left, target, srcnode);
    else return true;//target == root->val
  }
};

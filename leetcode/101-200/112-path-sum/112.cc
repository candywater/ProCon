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
  bool hasPathSum(TreeNode* root, int sum) {
    if(root == NULL) return false;
    return dfs(root, 0, sum);
  }
  int dfs(TreeNode* head, int count, int sum){
    if(head == NULL){
      return false;
    }
    if(head->right == NULL && head->left == NULL)
      return count + head->val == sum;
    return dfs(head->right, count + head->val, sum) ||
          dfs(head->left, count + head->val, sum);
  }
};

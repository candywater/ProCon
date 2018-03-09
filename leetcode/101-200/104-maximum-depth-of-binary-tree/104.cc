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
  int maxDepth(TreeNode* root) {
    return dfs(root);
  }

  const int& max(const int& a, const int& b){
    return a < b ? b : a;
  }

  int dfs(TreeNode* p){
    if(p == NULL) return 0;
    else {
      return max(dfs(p->right) + 1, dfs(p->left) + 1);
    }
  }
};

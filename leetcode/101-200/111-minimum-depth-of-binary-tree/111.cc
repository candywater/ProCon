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
  int minDepth(TreeNode* root) {
    if(root == NULL) return 0;
    //TreeNode* head = root;
    int res = INT_MAX;
    dfs(root, 1, res);
    return res;
  }
  void dfs(TreeNode* head, int count, int& max){
    if(head == NULL){
      return;
    }
    if(head->right == NULL && head->left == NULL){
      if(count < max) max = count;
      return;
    }
    dfs(head->right, count + 1, max);
    dfs(head->left, count + 1, max);
  }
};

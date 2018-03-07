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
  void flatten(TreeNode* root) {
    TreeNode* res;
    res = root;
    dfs(res);
  }

  void dfs(TreeNode* head){
    if(head == NULL){
      return;
    }
    dfs(head->left);
    dfs(head->right);
    rotate(head);
  }

  //cause q->left->right is NULL;
  void rotate(TreeNode* q){
    if(q == NULL) return;
    if(q->left == NULL) return;
    if(q->right == NULL){
      q->right = q->left;
      q->left = NULL;
      return;
    }
    TreeNode* tmp = q->right;
    q->right = q->left;
    q->left = NULL;
    while(q->right != NULL){
      q = q->right;
    }
    q->right = tmp;
  }

};

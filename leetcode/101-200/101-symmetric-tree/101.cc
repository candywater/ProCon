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
  bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    reverse(root->right);
    return isequals(root->right, root->left);
  }

  void reverse(TreeNode* p){
    if(p == NULL) return;
    else{
      TreeNode* tmp = p->right;
      p->right = p->left;
      p->left = tmp;
      reverse(p->right);
      reverse(p->left);
    }
  }

  bool isequals(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    if(p->val != q->val) return false;
    if(p->val == q->val)
      return isequals(p->left, q->left) && isequals(p->right, q->right);
  }
};

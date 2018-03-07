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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int deepth = getdeepth(root);
    vector<vector<int>> res(deepth, vector<int>());
    if(root == NULL) return res;
    dfs(root, res, 0);
    res.push_back(std::vector<int>(1, root->val));
    removeNull(res);
    return res;
  }

  void removeNull(vector<vector<int>>& a){
      if(a[0].size() == 0) a = vector<vector<int>>(a.begin() + 1, a.end());
  }

  int getdeepth(TreeNode* p){
    if(p == NULL) return 0;
    else {
      return max(getdeepth(p->right) + 1, getdeepth(p->left) + 1);
    }
  }

  void dfs(TreeNode* root, vector<vector<int>>& res, int deepth){
    if(root == NULL) return;
    dfs(root->left, res, deepth + 1);
    dfs(root->right, res, deepth + 1);
    if(root->left == NULL && root->right == NULL) return;
    vector<int>& tmp = res[res.size() - deepth - 1];
    if(root->left != NULL) tmp.push_back(root->left->val);
    if(root->right != NULL) tmp.push_back(root->right->val);
  }
};

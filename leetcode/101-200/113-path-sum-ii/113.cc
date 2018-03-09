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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    std::vector<vector<int>> res;
    dfs(root, 0, sum, vector<int>(), res);
    return res;
  }
  void dfs(TreeNode* head, int count, int sum, vector<int> tmp, vector<vector<int>>& res ){
    if(head == NULL){
      return;
    }
    if(head->right == NULL && head->left == NULL){
      tmp.push_back(head->val);
      if(count + head->val == sum) res.push_back(tmp);
      tmp.pop_back();
      return;
    }

    tmp.push_back(head->val);
    dfs(head->right, count + head->val, sum, tmp, res);
    dfs(head->left, count + head->val, sum, tmp, res);
    tmp.pop_back();
  }
};

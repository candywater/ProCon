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
  bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    TreeNode* head = root;
    getdeepth(head);
    return dfs(root);
  }

  bool dfs(TreeNode* head){
    if(head == NULL) return true;
    bool left = dfs(head->left);
    bool right = dfs(head->right);
    bool balance = isbalance(head->left, head->right);
    return left && right && balance;
  }

  bool isbalance(TreeNode* a, TreeNode* b){
    int vala = 0, valb = 0;
    if(a == NULL) vala = 0; else vala = a->val;
    if(b == NULL) valb = 0; else valb = b->val;
    int val = vala - valb;
    return val <= 1 && val >= -1;
  }

  const int& max(const int& a, const int& b){
    return a < b ? b : a;
  }

  int getdeepth(TreeNode* p){
    if(p == NULL) return 0;
    p->val = max(getdeepth(p->right) + 1, getdeepth(p->left) + 1);
    cout << p->val << endl;
    return p->val;
  }
};

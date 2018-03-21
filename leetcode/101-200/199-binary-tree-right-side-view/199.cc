#include "vector"
#include "iostream"
#include "climits"

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    if(root == NULL) return vector<int>();
    int deepth = getdeepth(root);
    vector<int> res(deepth, INT_MIN);
    dfs(root, res, 0);
    return res;
  }

  void dfs(TreeNode* head, vector<int>& res, int deepth){
    if(head == NULL) return;
    if(res[deepth] == INT_MIN)
      res[deepth] = head->val;

    dfs(head->right, res, deepth + 1);
    dfs(head->left, res, deepth + 1);
  }

  int getdeepth(TreeNode* head){
    if(head == NULL) return 0;
    else return max(getdeepth(head->right), getdeepth(head->left)) + 1;
  }

  template<typename T>
  T max(T a, T b){
    return a > b ? a : b;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

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

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    int deepth = getdeepth(root);
    vector<TreeLinkNode*> res(deepth, NULL);
    dfs(root, res, 0);
  }

  void dfs(TreeLinkNode* head, vector<TreeLinkNode*>& res, int deepth){
    if(head == NULL) return;
    head->next = res[deepth];
    res[deepth] = head;

    dfs(head->right, res, deepth + 1);
    dfs(head->left, res, deepth + 1);
  }

  int getdeepth(TreeLinkNode* head){
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

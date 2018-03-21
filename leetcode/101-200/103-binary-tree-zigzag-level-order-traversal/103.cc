/**
 * Definition for a binary tree node.
 */

#include "iostream"
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    int deepth = getdeepth(root);
    vector<vector<int>> res(deepth, vector<int>());
    dfs(root, res, 0);
    for(int i = 0; i < deepth; i++)
      if(i % 2 != 0) reverse(res[i]);
    return res;
  }

  void reverse(vector<int>& vec){
    vector<int> temp = vec;
    for(int i = temp.size() - 1; i >= 0; i--){
      vec[vec.size() - i - 1] = temp[i];
    }
  }

  template<typename T>
  void dfs(T* head, vector<vector<int>>& res, int deepth){
   if(head == NULL) return;
   res[deepth].push_back(head->val);

   dfs(head->left, res, deepth + 1);
   dfs(head->right, res, deepth + 1);
  }

  template<typename T>
  int getdeepth(T* head){
   if(head == NULL) return 0;
   else return max(getdeepth(head->right), getdeepth(head->left)) + 1;
  }
};

 int main(int argc, char const *argv[]) {
   /* code */
   return 0;
 }

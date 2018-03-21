#include "vector"
#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    int deepth = getdeepth(root);
    vector<vector<int>> res(deepth, vector<int>());
    dfs(root, res, 0);
    vector<double> result(deepth, 0);
    for(int i = 0; i < deepth; i++)
      result[i] = ave(res[i]);
    return result;
  }


  double ave(vector<int>& vec){
    double j = 0;
    for(auto i : vec){
      j += i;
    }
    return j / (double)vec.size();
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

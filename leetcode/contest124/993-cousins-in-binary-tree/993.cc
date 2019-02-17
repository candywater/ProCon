#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}
template<typename T> 
void showmatrix(T a){
  for(auto j: a){for(auto i : j){ cout << i; }cout << endl;}
  cout << endl;
}
void check(int i = 0){
  cout << "checkpoint:[" << i << "]" << endl;
}
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
  TreeNode* papa = NULL;

public:
  int dfs(TreeNode* head, TreeNode* parent, int val, int depth){
    if(head == NULL) return -1;
    if(head->val == val){
      if(papa == NULL) papa = parent;
      else if(papa == parent) return -1;
      return depth;
    } 
    int res = dfs(head->right, head, val, depth+1);
    if(res == -1)
      return dfs(head->left, head, val, depth+1);
    else return res;
  }
  bool isCousins(TreeNode* root, int x, int y) {
    papa = NULL;
    if(x==y) return true;
    int dx = dfs(root, NULL, x, 0);
    int dy = dfs(root, NULL, y, 0);
    cout << "dx:" << dx << " dy:" << dy << endl;
    return dx == dy;
  }
};


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;
  TreeNode* a = new TreeNode(1);
  a->left = new TreeNode(2);
  a->right = new TreeNode(3);
  a->left->right = new TreeNode(4);
  a->right->right = new TreeNode(5);
  cout << s.isCousins(a, 5, 4) << endl;
}

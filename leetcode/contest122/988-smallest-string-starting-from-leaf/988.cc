#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <set>

using namespace std;

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
  set<string> a;
  int depth = 0;
  string reverse(string s){
    string res;
    for(int i = s.size()-1; i >= 0; i--)
      res.push_back(s[i]);
    return res;
  }
  void dfs(TreeNode* head, string res, int d){
    if(head==NULL) return;
    if(head->right == NULL && head->left ==NULL){
      res.push_back(head->val + 'a');
      //debug
      //cout << "res:" << res <<endl;
      a.insert(reverse(res));
      return;
    } 
    res.push_back(head->val + 'a');
    dfs(head->right, res, d+1);
    dfs(head->left, res, d+1);
  }
  void dfs(TreeNode* head, int d){
    if(depth < d) depth =d ;
    if(head == NULL) return;
    dfs(head->right, d+1);
    dfs(head->left, d+1);
  }
  string smallestFromLeaf(TreeNode* root) {
    a.clear();
    dfs(root, "", 0);
    //return *(a.end()--);
    //.debug
    //show(a);
    return *a.begin();
  }
};

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  Solution s;
  TreeNode a(0);
  a.left = new TreeNode(1);
  a.right = new TreeNode(2);
  a.left->left = new TreeNode(3);
  a.left->right = new TreeNode(4);
  a.right->left = new TreeNode(3);
  a.right->right = new TreeNode(4);
  cout << s.smallestFromLeaf(&a) << endl;

  
}

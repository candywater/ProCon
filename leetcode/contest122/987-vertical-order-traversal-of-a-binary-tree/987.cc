#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <map>
#include <algorithm>

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
  void vAppend(vector<int>& v, vector<int> ele){
    sort(ele.begin(), ele.end());
    for(auto i : ele){
      v.push_back(i);
    }
  }
public:
  map< pair<int, int>, vector<int> > list;
  void dfs(TreeNode* head, int x, int y){
    if(head == NULL) return;
    if(list.count({x, y}) == 0) list[{x, y}] = vector<int>();
    list[{x, y}].push_back(head->val);
    dfs(head->left, x-1, y+1);
    dfs(head->right, x+1, y+1);
  }
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    dfs(root, 0, 0);
    vector< vector<int> > res;
    map< int, vector<int> > resm;
    for(auto& i: list){
      if(resm.count(i.first.first) == 0) resm[i.first.first] = vector<int>();
      vAppend(resm[i.first.first], i.second);
      //sort(res.rbegin()->begin(), res.rbegin()->end());
    }
    for(auto& i :resm){
      res.push_back(i.second);
    }
    return res;
  }
};


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

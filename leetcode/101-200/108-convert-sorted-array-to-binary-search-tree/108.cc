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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0) return NULL;
    int mid = (nums.size() - 1) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    TreeNode* head = root;

    /*head->left = new TreeNode(233);
    cout << head->left->val << endl;
    head = head->right;
    head = new TreeNode(322);
    cout << root->right->val << endl;*/

    dfs(head, nums, 0, (int)(nums.size() - 1));

    return root;
  }

  //follow the binary search, as
  // if val < target , l = l, r = mid - 1;
  // if val > target , l = mid + 1, r = r;
  // so, if val < target, index = (l + r)/2 = (l + mid - 1) / 2;
  //     if val > target, index = (l + r)/2 = (mid + 1 + r) / 2 = (mid + 1 + size() - 1)/2
  // end statement : l > r; it means,
  // if val < target, l > mid - 1;
  // if val > target, mid + 1 > r
  void dfs(TreeNode* head, const vector<int>& nums, int l, int r){
    //if(l > r) return;
    cout << l << " " << r  << " " << nums[(l+r)/2]<< endl;
    int mid = (l + r) / 2;
    if(l <= mid - 1){
      head->left = new TreeNode(nums[(l + mid - 1)/2]);
      dfs(head->left, nums, l, mid - 1);
    }
    if(mid + 1 <= r){
      head->right = new TreeNode(nums[(mid + 1 + r)/2]);
      dfs(head->right, nums, mid + 1, r);
    }
  }

};

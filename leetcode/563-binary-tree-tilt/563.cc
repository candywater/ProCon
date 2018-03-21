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
   int findTilt(TreeNode* root) {
     transTree(root);
     return dfs(root);
   }

   template<typename T>
   int transTree(T* head){
     if(head == NULL)
       return 0;
     int left = transTree(head->left);
     int right= transTree(head->right);
     head->val = left + right + head->val;
     return head->val;
   }

   template<typename T>
   int dfs(T* head){
     if(head == NULL)
       return 0;
     int left = dfs(head->right);
     int right = dfs(head->left);
     return getTile(head) + left + right;
   }

   template<typename T>
   int getTile(T* head){
     if(head == NULL) return 0;
     int left = head->left == NULL ? 0 : head->left->val;
     int right= head->right == NULL ? 0 : head->right->val;
     int res = left - right;
     return res > 0 ? res : -res;
   }
 };

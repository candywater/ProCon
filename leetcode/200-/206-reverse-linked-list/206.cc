/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/
class Solution {
  ListNode* res = NULL;
public:
  ListNode* reverseList(ListNode* head) {
    res = new ListNode(-1);
    ListNode* result = res;
    dfs(head);
    return result->next;
  }

  template<typename T>
  void dfs(T* head){
    if(head == NULL) return;
    dfs(head->next);
    res->next = new T(head->val);
    res = res->next;
  }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> map;
    while(head != NULL) {
      if(map.count(head) > 0) return true;
      map.insert(head);
      head = head->next;
    }
    return false;
  }
};

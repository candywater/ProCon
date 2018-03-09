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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = head;
    ListNode* front = head;
    if(head != NULL) head = head->next;
    while(head != NULL){
      if(front->val == head->val) {
        head = head->next;
        front->next = head;
      }
      else{
        front = head;
        head = head->next;
      }
    }
    return res;
  }
};

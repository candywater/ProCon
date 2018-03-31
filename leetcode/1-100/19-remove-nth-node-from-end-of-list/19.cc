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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int deepth = getDeepth(head);
    int target = deepth - n;
    if(target == 0) return head->next;
    else removeNth(head, target,1);
    return head;
  }

  void removeNth(ListNode* head, int target, int i){
    if(i != target)
      removeNth(head->next, target, i+1);
    else {
      head->next = head->next->next;
    }
  }

  int getDeepth(ListNode* head){
    if(head == NULL) return 0;
    else return getDeepth(head->next) + 1;
  }
};

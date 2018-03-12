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
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     unordered_set<ListNode*> map;
     while(headA != NULL){
       map.insert(headA);
       headA = headA->next;
     }
     while(headB != NULL){
       if(map.count(headB) > 0) return headB;
       headB = headB->next;
     }
     return NULL;
   }
 };

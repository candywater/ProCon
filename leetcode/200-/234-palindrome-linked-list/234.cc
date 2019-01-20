/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
   ListNode* point;
   bool flg;
 public:
   bool isPalindrome(ListNode* head) {
     flg = true;
     if(head == NULL) return true;
     point = head;
     dfs(head);
     return flg;
   }

   template <typename T>
   void dfs(T* head){
     if(head == NULL) return;
     //if(point == NULL) return; //useless statement
     /*if(head->next == point) return; //length is even number case.
     if(head->next != NULL)
        if(head->next->next == point) return;//length is odd number case*/
      //cannot find stop statement
      //O(2n)
     dfs(head->next);

     cout << head->val << " " << point->val << endl;
     if(head->val != point->val) flg = false;
     point = point->next;
   }

 };

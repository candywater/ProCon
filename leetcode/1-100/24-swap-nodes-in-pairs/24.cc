#include "iostream"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:

    void show( ListNode* head ){
      for(; head != NULL; ){
        cout << head->val << " ";
        head = head->next;
      }
      cout << endl;
    }
    ListNode* swap(ListNode* head){
      if(head == NULL) return NULL;
      if(head->next == NULL) return head;
      //show(head);//debug
      ListNode* first = head;
      ListNode* second = head->next;
      ListNode* third = head->next->next;
      head = second;
      head->next = first;
      head->next->next = third;
      //cout << "checkpoint" << endl;
      //show(head);//debug
      head->next->next = swap(head->next->next);
      return head;
    }

    ListNode* swapPairs(ListNode* head) {
      return swap(head);
    }

};

void show( ListNode* head ){
  for(; head != NULL; ){
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  ListNode b = ListNode(2);
  ListNode b1= ListNode(3);
  ListNode b2= ListNode(4);
  ListNode b3= ListNode(5);
  b.next = &b1;
  b1.next = &b2;
  b2.next = &b3;
  show(&b);

  Solution a;
  ListNode* res = a.swapPairs(&b);
  show(res);

  return 0;
}

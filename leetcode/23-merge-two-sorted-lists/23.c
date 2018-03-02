#include "iostream"
#include "stack"
#include "climits"
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* res = NULL;
    int a = INT_MAX;
    int b = INT_MAX;
    while(l1->next != NULL && l2->next != NULL){
      if(l1 != NULL) a = l1->val;
      if(l2 != NULL) b = l2->val;

    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

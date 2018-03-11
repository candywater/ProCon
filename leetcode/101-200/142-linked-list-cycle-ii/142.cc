#include "unordered_set"
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
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> map;
    while(head != NULL) {
      if(map.count(head) > 0) return *(map.find(head));
      map.insert(head);
      head = head->next;
    }
    return NULL;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

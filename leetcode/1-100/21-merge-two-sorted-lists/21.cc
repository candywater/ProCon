#include "iostream"
#include "stack"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* head = NULL;
      stack<int> res;
      while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            res.push(l1->val);
            l1 = l1->next;
          }
        else{
            res.push(l2->val);
            l2 = l2->next;
        }
      }


      if(l1 == NULL) head = l2;
      else if(l2 == NULL) head = l1;

        //debug
        /*stack<int> debug = res;
        while(!debug.empty()){
          cout << debug.top() << endl;
          debug.pop();
        }
        */
        while(!res.empty()){
          ListNode* r = new ListNode(res.top());
          res.pop();
          r->next = head;
          head = r;
        }
        return head;
      }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

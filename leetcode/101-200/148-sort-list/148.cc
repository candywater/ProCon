#include "iostream"
#include "algorithm"
#include "vector"

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
  ListNode* sortList(ListNode* head) {
    if(head == NULL) return head;
    vector<int> v;
    while(head != NULL){
      v.push_back(head->val);
      head = head->next;
    }
    sort(v.begin(), v.end());
    //show(v);

    head = new ListNode(v[0]);
    ListNode* res = head;
    for(int i = 1; i < (int)v.size(); i++){
      head->next = new ListNode(v[i]);
      head = head->next;
    }
    return res;
  }

  template<typename T>
  void show(const vector<T>& t){
    for(auto i : t)
      cout << i << " ";
    cout << endl;
  }
};


int main(int argc, char const *argv[]) {

  ListNode* a = new ListNode(1);
  ListNode* aa = a;
  a->next = new ListNode(2);
  a = a->next;
  a->next = new ListNode(0);
  a = a->next;

  cout << aa->val << " "
    << aa->next->val << " "
    << aa->next->next->val << endl;

  Solution b;
  aa = b.sortList(aa);

  cout << aa->val << " "
    << aa->next->val << " "
    << aa->next->next->val << endl;

  /* code */
  return 0;
}

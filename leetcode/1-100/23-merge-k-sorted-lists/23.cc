#include "set"
#include "vector"
#include "iostream"
#include "utility"

using namespace std;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct Comp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
  }
};
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    set<pair<int, int>, Comp> table;
    ListNode* res = new ListNode(0);
    ListNode* head = res;
    for(int i = 0; i < static_cast<int>(lists.size()); i++){
      if(lists[i] == NULL) continue;
      table.insert(make_pair(lists[i]->val, i));
    }
    while(static_cast<int>(table.size())){
      int value = table.begin()->first;
      int index = table.begin()->second;
      head->next = new ListNode(value);
      head = head->next;

      lists[index] = lists[index]->next;
      table.erase(table.begin());
      if(lists[index] != NULL)
        table.insert(make_pair(lists[index]->val, index));
    }
    return res->next;
  }
};

template<typename T>
void show(T* a){
  while(a != NULL){
    cout << a->val << " ";
    a = a->next;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  vector<ListNode*> qqq;
  ListNode* a = new ListNode(2);
  a->next = new ListNode(3);
  a->next->next = new ListNode(4);
  a->next->next->next = new ListNode(5);
  qqq.push_back(a);
  a = new ListNode(5);
  a->next = new ListNode(8);
  a->next->next = new ListNode(9);
  a->next->next->next = new ListNode(10);
  qqq.push_back(a);

  a = new ListNode(0);
  a->next = new ListNode(2);
  a->next->next = new ListNode(3);
  a->next->next->next = new ListNode(10);
  qqq.push_back(a);

  for(auto i : qqq){
    show(i);
  }

  Solution b;
  show(b.mergeKLists(qqq));


  return 0;
}

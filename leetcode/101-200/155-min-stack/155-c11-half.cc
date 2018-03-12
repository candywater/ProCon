#include "iostream"
#include "climits"
#include "memory"

using namespace std;

class intList{
  int val;
  unique_ptr<intList> next;
public:
  intList(int n){
    this->val = n;
    this->next = move(nullptr);
  }
  intList(int n, intList* head){
    this->val = n;
    this->next = move(unique_ptr<intList>(head));
  }
  int getVal(){
    return val;
  }
  intList* getNext(){
    return next.get();
  }

  ~intList(){}

};

class MinStack {
  intList* list;
public:
  /** initialize your data structure here. */
  MinStack() {
    list = NULL;
  }

  void push(int x) {
    intList* tmp = new intList(x, list);
    list = tmp;
  }

  void pop() {
    intList* tmp = list;
    list = list->getNext();
    delete tmp;
  }

  int top() {
    return list->getVal();
  }

  int getMin() {
    intList* tmp = list;
    int min = INT_MAX;
    while(tmp != NULL){
      if(tmp->getVal() < min) min = tmp->getVal();
      tmp = tmp->getNext();
    }
    return min;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

 int main(int argc, char const *argv[]) {
   /* code */
   return 0;
 }

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}
template<typename T> 
void showmatrix(T a){
  for(auto j: a){for(auto i : j){ cout << i; }cout << endl;}
  cout << endl;
}
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
  vector<Interval> intervalIntersection(vector<Interval>& a, vector<Interval>& b) {
    vector<Interval> list;
    vector<Interval> res;
    for(auto i: a) list.push_back(i);
    for(auto i: b) list.push_back(i);
    auto comp = [&](Interval a, Interval b){
      if(a.start == b.start) return a.end > b.end;
      return a.start < b.start;
    };
    sort(list.begin(), list.end(), comp);
    
    if(list.size() == 0) return res;
  
    Interval tmp = *list.begin();
    for(int i = 1; i < list.size(); i++){
      // 包含
      if(list[i].start == tmp.start) {
        res.push_back(list[i]);
      }
      // 包含
      else if(list[i].end <= tmp.end) {
        res.push_back(list[i]);
      }
      // 分离
      else if(list[i].start > tmp.end) {
        tmp = list[i];
      }
      // 相交
      else{
        Interval t(list[i].start, tmp.end);
        res.push_back(t);
        tmp = Interval(tmp.start, list[i].end);
      }
    }
    return res;
  }
};


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

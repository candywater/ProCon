#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}

template<typename T> 
void showpair(T a){
  for(auto i : a){ cout << i.first << "," << i.second << " "; }
  cout << endl;
}

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  //https://leetcode.com/problems/merge-intervals/solution/
  vector<Interval> merge(vector<Interval>& in) {
    if(in.size() <= 0) return vector<Interval>();
    auto sortmethod = [](Interval& a, Interval& b){
      if(a.start == b.start)
        return a.end > b.end;
      else
        return a.start < b.start;
    };
    vector<Interval > range;
    sort(in.begin(), in.end(), sortmethod);
    int tmp1 = in.begin()->start;
    int tmp2 = in.begin()->end;
    for(auto i : in){
      if(i.start> tmp2){
        range.push_back({tmp1, tmp2});
        tmp1 = i.start;
        tmp2 = i.end;
      }
      else if(i.end> tmp2){
        tmp2 = i.end;
      }
    }
    range.push_back({tmp1, tmp2});
    return range;
  }
};

int main(int argc, char *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);
  return 0;
}



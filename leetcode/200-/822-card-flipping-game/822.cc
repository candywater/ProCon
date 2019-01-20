#include "iostream"
#include "set"
#include "map"
#include "unordered_set"
#include "vector"

using namespace std;

class Solution {
public:
  int flipgame(vector<int>& fronts, vector<int>& backs) {
    unordered_set<int> badnums;
    multimap<int, int> goodnums;
    for(int i = 0; i < fronts.size(); i++){
      if(fronts[i] == backs[i])
        badnums.insert(fronts[i]);
      //cout << "front:" << fronts[i] << " " << i << endl;
      //cout << "backs:" << backs[i] << " " << i << endl;
    }
    //show(badnums);
    for(int i = 0; i < fronts.size(); i++){
      if(badnums.count(fronts[i]) == 0){
        goodnums.insert({fronts[i], i});
        //cout << "front:" << fronts[i] << " " << i << endl;
      }
      if(badnums.count(backs[i]) == 0){
        goodnums.insert({backs[i], i});
        //cout << "backs:" << backs[i] << " " << i << endl;
      }
    }
    for(auto i = goodnums.begin(); i != goodnums.end(); i++){
      //cout << i->first << " " << i->second << endl;
      bool flg = true;
      for(int j = 0; j < fronts.size(); j++){
        if(j == i->second) continue;
        if(fronts[j] == i->first && backs[j] == i->first){
          flg = false;
          break;
        }
      }
      if(flg) return i->first;
    }
    return 0;
  }

  template<typename T>
  void show(T a){
    for(auto i : a)
      cout << i << " ";
    cout << endl;
  }
};

template<typename T>
void show(T a){
  for(auto i : a)
    cout << i << " ";
  cout << endl;
}

int main(int argc, char const *argv[]) {
  Solution a;
  std::vector<int> b = {
    //1,2,4,4,7
    1,1
  };
  std::vector<int> c = {
    //1,3,4,1,3
    2,2
  };
  cout << " res: " << a.flipgame(b,c);
  return 0;
}

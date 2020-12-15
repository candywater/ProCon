#include <vector>
using namespace std;

  vector<int> s; // contains nodes that do not contains parents
  vector< int > itsparent; // contains its parents
  vector< int > itschild;// contains its children
  vector< int > res;
  while(!s.empty()){
    int i = *s.begin();
    s.erase(i);
    res.push_back(i);
    for(int j : itschild[i]){
      itschild[i].erase(j);
      itsparent[j].erase(i);
      if(itsparent[j].empty()) {
        s.insert(j);
      }
    }
  }
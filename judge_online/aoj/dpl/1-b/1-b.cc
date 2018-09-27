//learnt from http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2062308#1

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

template<typename T>
void show(T a){
  for(auto i = a.begin(); i != a.end(); i++)
    cout << *i << " ";
  cout << endl;
}

int main(void){
  int m, n, tmpvalue, tmpweight;
  cin >> n >> m;
  vector<int> dplist(m+1, 0);
  vector<int> values = vector<int>(n, 0);
  vector<int> weights = vector<int>(n, 0);
  for(auto i = 0; i < n; ++i){
    cin >> tmpvalue >> tmpweight;
    values[i] = tmpvalue;
    weights[i] = tmpweight;
  }

  //dplist[i] : a
  //i : weight
  //a : maxium value
  //subproblem: maxium value at that weight
  for(auto i = 0; i < n; ++i){
    for(auto j = m; j >= 1; --j){
      if(weights[i] <= j){
        dplist[j] = max(dplist[j], dplist[j-weights[i]] + values[i]);
      }
      else{
        dplist[j] = dplist[j];
      }
    }
    //show(dplist);
  }

  cout << dplist[m] << endl;
  return 0;
}
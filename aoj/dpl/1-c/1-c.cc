#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
void show(T a){
  for(auto i : a){
  }
  cout << endl;
}

int main(int argc, char *argv[]){
  int n, w;
  cin >> n >> w;
  vector<int> value(n, 0);
  vector<int> weight(n, 0);
  vector<int> dplist(w+1, 0);
  for(int i = 0; i < n; i++){
    int t1, t2;
    cin >> t1 >> t2;
    value[i] = t1;
    weight[i] = t2;
  }

  //dplist[i] : a
  //i : weight
  //a : max value at that weight
  //subproblem: max value at that weight(minium subproblem is that what value is a single object?)
  for(int i = 1; i <= w; i++){
    int maxium = 0;
    for(int j = 0; j < n; j++){
      if(weight[j] > i) continue;
      int tmp = dplist[i-weight[j]] + value[j];
      maxium = max(tmp, maxium);
    }
    dplist[i] = maxium;
  }

  cout << dplist[w] << endl;
  return 0;
}
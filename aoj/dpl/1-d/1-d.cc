#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


template<typename T>
void show(T a){
  for(auto i : a){
    cout << i << " ";
  }
  cout << endl;
}
//learnt from http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1058947#1

int main(int argc, char *argv[]){
  int n, tmp;
  vector<int> list;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    list.push_back(tmp);
  }
  vector<int> dp (n+1, INT_MAX);

  //O(nlogn)
  for(int i = 0; i < n; i++){
    auto j = lower_bound(dp.begin(), dp.end(), list[i]);
    *j = list[i];
  }

  auto j = lower_bound(dp.begin(), dp.end(), INT_MAX);
  cout << j - dp.begin() << endl;

/*
  //O(n^2)
  for(int i = 0; i < n; i++){
    for(int j = i; j >= 0; j--){
      if(list[i] > list[j]){
        dp[i]= max(dp[i], dp[j]+1);
      }
    }
  }
  cout << *(max_element(dp.begin(), dp.end())) << endl;
*/
  return 0;
}
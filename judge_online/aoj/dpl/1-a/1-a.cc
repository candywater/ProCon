/*c++11*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

void dp(set<int>& coins, vector<int>& ints, int pos);
template<typename T>
void show(T);

int main(int args, char *argc[]){

  int n, m;
  int tmp; 
  set<int> coins;
  vector<int> ints;

  cin >> n >> m;
  ints = vector<int>(n+1, 0);
  for(int i = 0; i < m; i++){
    cin >> tmp;
    coins.insert(tmp);
  }
  dp(coins, ints, 1);

  //cout << endl;
  cout << ints[n] << endl;

  return 0;
}

void dp(set<int>& coins, vector<int>& ints, int pos){
  if(pos == static_cast<int>(ints.size())) return;
  int min = INT_MAX;
  for(auto i = coins.begin(); i != coins.end(); i++){
    //cout << *i << " " ;//debug
    if(*i > pos) break;
    int tmp = ints[pos - *i] + 1;
    min = min < tmp ? min : tmp;
    //cout << "pos:" << pos;
    //show(ints);
    //cout << "tmp:" << tmp << " " ;//debug
  }
  ints[pos] = min;
  dp(coins, ints, pos + 1);
}

template<typename T>
void show(T a){
  cout << endl << "show:" << endl;
  for(auto i = a.begin(); i != a.end(); i++){
    cout << *i << " ";
  }
  cout << endl; 
}
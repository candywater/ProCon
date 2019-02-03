#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

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

class Solution {
public:
  int addEvenAll(vector<int>& a){
    int res = 0;
    for(auto i : a){
      if(i % 2 == 0){
        res += i;
      }
    }
    return res;
  }
  vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& queries) {
    vector<int> res;
    for(auto& i : queries){
      a[i[1]] += i[0];
      res.push_back( addEvenAll(a) );
    }
    return res;
  }
};



int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}




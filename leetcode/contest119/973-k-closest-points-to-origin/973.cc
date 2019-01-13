#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}

template<typename T> 
void showv(T a){
  for(auto j : a)
    for(auto i : j){ cout << i << " "; }
  cout << endl;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      auto comp = [&](vector<int>& a, vector<int>& b){
        double ha = hypot(a[0], a[1]);
        double hb = hypot(b[0], b[1]);
        return ha < hb;
      };
      sort(points.begin(), points.end(), comp);
      
      return vector< vector<int> >(points.begin(), points.begin()+k);

    }
};

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  Solution a;
  vector<vector<int>> b = {{1,3},{-2,2}};
  showv(a.kClosest(b, 1));

}

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}

class Solution {
public:
  // a <= b <= c
  bool isTriangle(int a, int b, int c){
    return a + b > c;
  }
  int largestPerimeter(vector<int>& a) {
    sort(a.begin(), a.end());
    for(int i = a.size()-1; i >= 2; i--){
      if(isTriangle(a[i-2], a[i-1], a[i]))
        return a[i] + a[i-1] + a[i-2];
    }
    return 0;
  }
};

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  Solution a;
  vector<int> b = {3,6,2,3};
  cout << a.largestPerimeter(b) << endl;
}

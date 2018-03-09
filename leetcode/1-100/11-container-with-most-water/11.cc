#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int min(const int& a, const int& b){
    return a < b ? a : b;
  }
 int max(const int& a, const int& b){
    return a > b ? a : b;
  }
 
  public:
  int maxArea(vector<int>& height) {
    int res = 0;
    for(size_t i = 0, j = height.size() - 1; i != j; ){
      int tmp = min(height[i], height[j]) * (j - i);
      //debug
      /*
      cout << "i > j " << (int)(height[i] > height[j]) << endl;
      cout << "height[i]:" << height[i] << " height[j]:" << height[j] << endl;
      cout << "tmp:" << tmp << endl;
      cout << "i:" << i << " j:" << j << endl;
      */
      if(height[i] > height[j]) j--;
      else i++;
      res = max(res, tmp);
      //cout << "res:" << res << endl << endl;
   }
    return res;
  }            
};

int main(){
  vector<int> v;
  int tmp;
  while(cin >> tmp){
    cin.ignore(1);
    v.push_back(tmp);
  }
  cin >> tmp;
  v.push_back(tmp);

  cout << v[0] << endl;
  cout << v[v.size() - 1] << endl;

  Solution a;
  cout << a.maxArea(v) << endl;


  return 0;
}

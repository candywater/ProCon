#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}

class Solution {
public:
//https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/217979/O(n)-Clean-Python-Solution-8-Lines-with-Picture-Explanation!
//https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/217980/Java-O(N)-with-HashMap-and-preSum
  int subarraysDivByK(vector<int>& a, int k) {
    unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0;
    int res = 0;
    for(int& i: a){
      sum += i;
      sum = sum % k;
      if(sum < 0) sum += k;
      if(map.count(sum%k) <= 0){
        map[sum%k] = 1;
      }
      else{
        res += map[sum%k];
        map[sum%k] += 1;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  Solution a;
  vector<int> b = {4,5,0,-2,-3,1};
  cout << a.subarraysDivByK(b, 5) << endl;
  vector<int> c = {-7,2,3,0,-9};
  cout << a.subarraysDivByK(c, 3) << endl;
}

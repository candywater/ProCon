class Solution {
public:
  //crazy Fibonacci
  int climbStairs(int n) {
    vector<int> t;
    t.push_back(0);
    t.push_back(1);
    t.push_back(2);
    for(size_t i = 3; i <= n; i++){
      t.push_back( t[i-1] + t[i-2] );
    }
    return t[n];
  }
};

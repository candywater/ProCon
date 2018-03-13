class Solution {
public:
  int trailingZeroes(int n) {
    //2，5，10，...
    //follow https://leetcode.com/problems/factorial-trailing-zeroes/discuss/52373/Simple-CC++-Solution-(with-detailed-explaination)
    //even numbers x 5
    // 5, 10, 15, 20, 25, 30, ...
    // 5, 25, 125, 625, ...
    // 5^1, 5^2, 5^3, 5^4,

    int res = 0;
    for(long long i = 5; i <= n; i = i*5){
      res += (n/i);
    }

    return res;
  }
};

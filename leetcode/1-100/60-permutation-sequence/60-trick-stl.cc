class Solution {
public:
  string getPermutation(int n, int k) {
    string num;
    for(int i = 1; i <= n; i++){
      num.push_back(i+'0');
    }
    for(int i = 0; i < k-1; i++){
      next_permutation(num.begin(), num.end());
    }
    return num;
  }
};
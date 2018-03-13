class Solution {
public:
  int hammingWeight(uint32_t n) {
    bitset<32> a(n);
    return (int)a.count();
  }
};

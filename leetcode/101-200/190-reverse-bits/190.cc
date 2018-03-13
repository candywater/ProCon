#include "iostream"
#include "bitset"

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    bitset<32> t(n);
    for(int i = 0, j = 31; i < j; i++, j--){
      bool flg = t[i];
      t[i] = t[j];
      t[j] = flg;
    }
    return (uint32_t)t.to_ulong();
  }
};


int main(int argc, char const *argv[]) {
  /* code */
  Solution a ;
  cout << a.reverseBits(43261596) << endl;
  return 0;
}

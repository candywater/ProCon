#include "iostream"
#include "set"
#include "vector"

using namespace std;

class Solution {
public:
  //O(nlogn)
  int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    set<int> table(nums.begin(), nums.end());
    int max = 1;
    int tmp = *table.begin();
    int count = 1;
    for(set<int>::iterator i = ++table.begin(); i != table.end(); i++){
      //cout << tmp << endl;
      if(++tmp == *i) count++;
      else{
        max = max < count ? count : max;
        count = 1;
        tmp = *i;
      }
    }
    max = max < count ? count : max;
    return max;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

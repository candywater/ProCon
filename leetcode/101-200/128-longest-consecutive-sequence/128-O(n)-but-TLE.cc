#include "iostream"
#include "set"
#include "vector"

using namespace std;

class Solution {
public:
  //シータ(2n)
  int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    unordered_set<int> table(nums.begin(), nums.end());
    int max = 1;
    int count = 0;
    for(int i = 0; i != nums.size(); i++){
      int tmp = nums[i];
      count = 1;
      //cout << tmp << endl;
      while(table.count(++tmp)){
        //cout << tmp << endl;
        count++;
      }
      max = max > count ? max : count ;
    }
    return max;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

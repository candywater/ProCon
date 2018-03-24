#include "iostream"
#include "vector"
#include "map"
#include "unordered_map"
#include "set"
#include "algorithm"

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    //https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C++-solution-around-50ms-O(N*N)-with-explanation-and-comments
    set<vector<int>> res;
    sort(nums.begin(), nums.end());

    for(int target = 0; target != static_cast<int>(nums.size()); target++){
      int i = target + 1, j = static_cast<int>(nums.size()) - 1;
      for( ; i < j; ){
        int sum = nums[i] + nums[j];
        /*cout << "?? " << sum << " " << nums[target] << ":"
          << nums[target] << " "
          << nums[i] << " " << nums[j] << " " << endl;*/
        if(sum < -nums[target]) i++;
        else if(sum > -nums[target]) j--;
        else{
          //cout << "!!" << endl;
          vector<int> tmp;
          tmp.push_back(nums[target]);
          tmp.push_back(nums[i]);
          tmp.push_back(nums[j]);
          sort(tmp.begin(), tmp.end());
          res.insert(tmp);
          i++;
          j--;
        }
      }
    }

    vector<vector<int>> temp;
    temp.assign(res.begin(), res.end());
    return temp;
  }

  template<typename T>
  void show(T a){
    for(auto i : a){
      cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    }
    cout << endl;
  }
};

void showvec(vector<vector<int>> vec){
  for(auto i : vec){
    for(auto j : i){
      cout << j << " " ;
    } cout << endl;
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  Solution a ;
  vector<int> b = {
    //1,2,3,4,5,6,7
    -1,0,1,2,-1,-4
  };
  showvec(a.threeSum(b));
  return 0;
}

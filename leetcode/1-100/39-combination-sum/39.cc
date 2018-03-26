
#include "iostream"
#include "vector"
#include "set"
#include "algorithm"

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    set<vector<int>> restmp;
    vector<int> temp;
    backtrack(restmp, temp, candidates, target, 0);

    res.assign(restmp.begin(), restmp.end());

    return res;
  }
  void backtrack(
    set<vector<int>>& res, vector<int>&temp, const vector<int>& candidates,
    const int& target, int now){
    if(now == target){
      vector<int> sortedtmp = temp;
      sort(sortedtmp.begin(), sortedtmp.end());
      res.insert(sortedtmp);
    }
    if(now > target) return;

    for(int i = 0; i < candidates.size(); i++){
      temp.push_back(candidates[i]);
      backtrack(res, temp, candidates, target, now+candidates[i]);
      temp.pop_back();
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> mao;
    for(int i = 0; i < numbers.size(); i++){
      if(mao.count(target-numbers[i]) > 0)
        return {mao[target-numbers[i]], i+1};
      else
        mao.insert({numbers[i], i+1});
    }
    return {-1, -1};
  }
};

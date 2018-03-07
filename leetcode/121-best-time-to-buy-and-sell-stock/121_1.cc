class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int max = 0;
    for(size_t i = 0; i < prices.size(); i++){
      int now = prices[i];
      for(size_t j = i + 1; j < prices.size(); j++){
        int tmp = prices[j] - prices[i];
        max = (tmp > max) ? tmp : max;
      }
    }
    return max;
  }
};

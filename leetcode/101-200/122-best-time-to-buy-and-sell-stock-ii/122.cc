class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if(prices.size() == 1) return 0;
    int max = 0;
    for(size_t i = 1; i < prices.size(); i++){
      int tmp = prices[i] - prices[i-1];
      if(tmp > 0) max += tmp;
    }
    return max;
  }
};

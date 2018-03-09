class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;
    int max = 0;
    int min = INT_MAX;
    for(size_t i = 0; i < prices.size(); i++){
      int now = prices[i];
      if(now < min) min = now;
      else{
        int tmp = now - min;
        max = (tmp > max) ? tmp : max;
      }
    }
    return max;
  }
};

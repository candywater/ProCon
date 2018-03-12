class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_multiset<int> map(nums.begin(), nums.end());
    unordered_set<int> m(nums.begin(), nums.end());
    int max = 0;
    int major = 0;

    for(auto i= m.begin(); i != m.end(); i++){
      int tmp = map.count(*i);
      if(max < tmp){
        major = *i;
        max = tmp;
      }
    }
    //cout << max << endl;
    return major;
  }
};

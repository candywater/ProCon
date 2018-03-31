class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> res;
    //O(n^3)
    sort(nums.begin(), nums.end());
    int i = 0, j = static_cast<int>(nums.size()) - 1,
      m = i + 1, n = j - 1;
    //用夹逼法....
    for( ; i != static_cast<int>(nums.size()); i++)
    for(j = static_cast<int>(nums.size()) - 1; j != i; j--){
      m = i + 1, n = j - 1;
      int tmp1 = nums[i] + nums[j];
      for(; m < n && m < j && n > i; ){
        //show(i,j,m,n,nums);
        int tmp2 = nums[m] + nums[n];
        if(tmp1 + tmp2 < target) m++;
        else if(tmp1 + tmp2 > target) n--;
        else{
          vector<int> t;
          t.push_back(nums[i]);
          t.push_back(nums[j]);
          t.push_back(nums[m]);
          t.push_back(nums[n]);
          sort(t.begin(), t.end());
          res.insert(t);
          m++;
          n--;
        }
      }
    }
    vector<vector<int>> temp;
    temp.assign(res.begin(), res.end());
    return temp;
  }
  void show(int i, int j, int m, int n, vector<int>& nums){
    cout << i << " " << j << " " << m << " " << n << endl;
    cout << nums[i] << " " << nums[j] << " " << nums[m] << " " << nums[n] << endl;
  }
};

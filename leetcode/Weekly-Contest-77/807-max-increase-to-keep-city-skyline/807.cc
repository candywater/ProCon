class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int res = 0;
    vector<int> top(grid.size(), -1);//i
    vector<int> left(grid[0].size(), -1);//j
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[i].size(); j++){
        if(grid[i][j] > top[i]) top[i] = grid[i][j];
        if(grid[i][j] > left[j]) left[j] = grid[i][j];
      }
    }

    //show(top);
    //show(left);

    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[i].size(); j++){
        int tmptop = top[i] - grid[i][j];
        int tmpleft = left[j] - grid[i][j];
        res += tmptop < tmpleft ? tmptop : tmpleft;
      }
    }

    return res;
  }

  template<typename T>
  void show(T a){
    for(auto i : a){
      cout << i << " ";
    }
    cout << endl;
  }
};

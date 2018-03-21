#include "iostream"
#include "vector"

using namespace std;

class Solution {
  //(1, 0)
  //(0, -1)
  //(-1, 0)
  //(0, 1)
  const vector<int> dx = {1, 0, -1, 0};
  const vector<int> dy = {0, -1, 0, 1};
public:
  int numIslands(vector<vector<char>>& grid) {
    //follow https://leetcode.com/problems/number-of-islands/discuss/56347/Simple-Java-Solution
    // O(n^2)
    int count = 0;
    for(int i = 0; i < static_cast<int>(grid.size()); i++){
      for(int j = 0; j < static_cast<int>(grid[i].size()); j++){
        if(grid[i][j] == '1'){
          count++;
          dfs(grid, i, j);
        }
        //show(grid);
      }
    }
    return count;
  }
  //set explored area 9
  void dfs(vector<vector<char>>& grid, int x, int y){
    if(x < 0 || y < 0) return;
    if(x >= static_cast<int>(grid.size())) return;
    if(y >= static_cast<int>(grid[x].size())) return;
    if(grid[x][y] == '9') return;
    if(grid[x][y] == '0') return;
    grid[x][y] = '9';
    for(int i = 0; i < 4; i++){
      dfs(grid, x+dx[i], y+dy[i]);
    }
  }

  //debug
  void show(const vector<vector<char>>& grid){
    for(int i = 0; i < static_cast<int>(grid.size()); i++){
      for(int j = 0; j < static_cast<int>(grid.size()); j++){
        cout << grid[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<char>> v = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
  };
  Solution a;
  cout << a.numIslands(v) << endl;
  return 0;
}

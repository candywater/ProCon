#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <climits>
#include <queue>

using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}
template<typename T> 
void showmatrix(T a){
  for(auto j: a){for(auto i : j){ cout << i; }cout << endl;}
  cout << endl;
}
void check(int i = 0){
  cout << "checkpoint:[" << i << "]" << endl;
}


class Solution {
  vector<int> dx = {0, 1, 0, -1};
  vector<int> dy = {1, 0, -1, 0};
public:
  void adjacent(vector<vector<int>>& v, int x, int y){
    //if(v[x][y] == 1 || v[x][y] == 0) return;
    for(int i = 0; i < 4; i++){
      int xx = dx[i]+x;
      int yy = dy[i] + y;
      if(xx < 0 || yy < 0) continue;
      if(xx >= v.size()) continue;
      if(yy >= v[xx].size()) continue;
      if(v[xx][yy]==0) continue;
      v[xx][yy] = 2;
    }
  }
  int perminute(vector<vector<int>>& grid){
    queue<pair<int, int>> q;
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[i].size(); j++){
        if(grid[i][j] == 2)
          q.push({i, j});
      }
    }
    while(!q.empty()){
      adjacent(grid, q.front().first, q.front().second);
      q.pop();
    }
    int count = 0;
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[i].size(); j++){
        if(grid[i][j] == 1) count++;
      }
    }
    return count;
  }
  int countorange(vector<vector<int>>& grid){
        int count = 0;
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[i].size(); j++){
        if(grid[i][j] == 1) count++;
      }
    }
    return count;
  }
  int orangesRotting(vector<vector<int>>& grid) {
    int count = INT_MAX;
    int minute = 0;

    if(countorange(grid) == 0) return 0;

    while(true){
      minute++;
      int tmp = perminute(grid);
      if(tmp == 0) return minute;
      else if(tmp < count) count = tmp;
      else return -1;
    }
    return -1;
  }
};


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;
  vector<vector<int>> a = {
  {2,1,1},
  {1, 1, 0},
  {0, 1, 1}
};
vector<vector<int>> b =
{{2,1,1},{0,1,1},{1,0,1}};
vector<vector<int>> c ={{0, 2}};

  int res=  s.orangesRotting(
    b
  );
  cout << res << endl;
}

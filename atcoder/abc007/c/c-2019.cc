#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

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

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

void bfs(vector< vector<int> >& map, vector< vector<bool> >& v, const pair<int, int>& s, const pair<int, int>& g){
  queue< pair<int, int> > q;
  q.push(s);
  map[s.first][s.second] = 0;
  while(!q.empty()){
    pair<int, int> p = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int x = p.first+dx[i];
      int y = p.second+dy[i];
      if(x >= v.size()) continue;
      if(y >= v[x].size()) continue;
      if(v[x][y]){
        q.push({x, y});
        map[x][y] = map[p.first][p.second] + 1;
        v[x][y] = false;
        if(x == g.first && y == g.second) return;// 枝刈り
      }
    }
  }
} 

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int r, c;
  pair<int, int> s, g;
  cin >> r >> c;
  cin >> s.first >> s.second;
  cin >> g.first >> g.second;
  s.first -= 1;
  s.second -= 1;
  g.first -= 1;
  g.second -= 1;
  vector< vector<bool> > v(r, vector<bool>(c, false));
  vector< vector<int> > map(r, vector<int>(c, -1));
  
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      char tmp;
      cin >> tmp;
      if(tmp == '#')// wall
        v[i][j] = false;
      else
        v[i][j] = true;
    }
  }
  
  bfs(map, v, s, g);
  //showmatrix(map);
  //showmatrix(v);

  cout << map[g.first][g.second] << endl;
}

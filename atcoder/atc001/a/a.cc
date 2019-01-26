#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int count = 0;

bool dfs(int x, int y, vector< vector<char> >& v){
  if(x >= v.size()) return false;
  if(y >= v[x].size()) return false;
  if(v[x][y] == '#') return false;
  if(v[x][y] == 'g') return true;
  //cout << ++ count << endl;
  v[x][y] = '#';
  vector<bool> res = {false, false, false, false};
  for(int i = 0; i < 4; i++){
    res[i] = dfs(x + dx[i], y + dy[i], v);
  }
  return res[0] || res[1] || res[2] || res[3];
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w;
  cin >> h >> w;
  vector< vector<char> > c(h, vector<char>(w));
  int sx, sy;
  for(int i = 0; i < c.size(); i++){
    for(int j = 0; j < c[i].size(); j++){
      cin >> c[i][j];
      if(c[i][j] == 's'){
        sx = i;
        sy = j;
      }
    }
  }
  
  cout << (dfs(sx, sy, c) == true ? "Yes" : "No") << endl;

}

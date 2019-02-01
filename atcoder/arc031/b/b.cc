#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
const int maxx = 10;
const int maxy = 10;
const char landmark = 'o';
const char seamark = 'x';

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

// dfs
void dfs_two(int x, int y, vector< vector<char> >& v){
  if(x >= maxx || y >= maxy) return;
  if(x < 0|| y < 0) return;
  //cout << "x:" << x << " y:" << y << endl;
  if(v[x][y] == seamark)
    return;
  if(v[x][y] == landmark){
    v[x][y] = seamark;
  }
  
  for(int i = 0; i < 4; i++){
    dfs_two(x+dx[i], y+dy[i], v);
  }
}

int count_land(vector< vector<char> >& v){
  int count = 0;
  for(auto& i : v){
    for(auto& j : i){
      if(j == landmark)
        count++;
    }
  }
  return count;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  vector< vector<char> > v(maxx, vector<char>(maxy, 'a'));
  vector< vector<char> > m(maxx, vector<char>(maxy, 'b'));
  for(int i = 0; i < maxx; i++){
    for(int j = 0; j < maxy; j++){
      scanf("%c", &v[i][j]);
    }
    scanf("\n");
  }
  
  if(count_land(v) == 0){
    cout << "NO" << endl;
    return 0;
  }
  
  for(int i = 1; i < maxx; i++){
    for(int j = 0; j < maxy; j++){
      if(v[i][j] == landmark) continue;
      m = v;
      m[i][j] = landmark;
      dfs_two(i, j, m);
      if(count_land(m) != 0) continue;
      cout << "YES" << endl;
      return 0;
    }
  }

  //land = find_land(v);
  cout << "NO" <<endl;
}

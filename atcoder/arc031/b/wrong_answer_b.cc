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

// 外面加一圈
// wrong think
void dfs_one(int x, int y, vector< vector<char> >& v, vector< vector<bool> >& m){
  if(x >= maxx || y >= maxy) return;
  if(x < 0|| y < 0) return;
  if(m[x][y] == true) return;
  if(v[x][y] == seamark){
    v[x][y] = landmark;
    m[x][y] = true; 
    return;
  }
  else{
    m[x][y] = true;
  }
  
  for(int i = 0; i < 4; i++){
    dfs_one(x+dx[i], y+dy[i], v, m);
  }

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

pair<int, int> find_land(vector< vector<char> >& v){
  for(int i = 0; i < maxx; i++){
    for(int j = 0; j < maxy; j++){
      if(v[i][j] == landmark){
        return {i, j};
      }
    }
  }
  return {-1, -1};
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
  vector< vector<bool> > m(maxx, vector<bool>(maxy, false));
  for(int i = 0; i < maxx; i++){
    for(int j = 0; j < maxy; j++){
      scanf("%c", &v[i][j]);
    }
    scanf("\n");
  }
  
  pair<int, int> land = find_land(v);
  if(land.first == -1 && land.second == -1){
    cout << "NO" << endl;
    return 0;
  }
  

  dfs_one(land.first, land.second, v, m);
  dfs_two(land.first, land.second, v);
  if(count_land(v) == 0) {
    cout << "YES" << endl;
  }
  else cout << "NO" <<endl;
  
  
  
  // why wrong?
  // this is a example
/*
[ [ 'x', 'x', 'o', 'x', 'o', 'o', 'o', 'o', 'o', 'x' ],
  [ 'x', 'o', 'o', 'x', 'o', 'x', 'x', 'o', 'o', 'x' ],
  [ 'o', 'x', 'o', 'o', 'o', 'x', 'o', 'x', 'o', 'x' ],
  [ 'o', 'x', 'o', 'x', 'o', 'o', 'o', 'x', 'x', 'o' ],
  [ 'x', 'x', 'x', 'x', 'x', 'o', 'o', 'o', 'o', 'o' ],
  [ 'o', 'o', 'x', 'o', 'o', 'o', 'o', 'o', 'x', 'x' ],
  [ 'o', 'o', 'o', 'o', 'x', 'o', 'x', 'o', 'o', 'o' ],
  [ 'o', 'x', 'o', 'x', 'o', 'o', 'x', 'x', 'o', 'o' ],
  [ 'o', 'o', 'x', 'o', 'x', 'x', 'o', 'x', 'o', 'x' ],
  [ 'o', 'o', 'o', 'x', 'x', 'o', 'o', 'x', 'o', 'o' ] ]
  */
}

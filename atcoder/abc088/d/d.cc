#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
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
template<typename T> 
void showmatrix_new(T a){
  for(auto j: a){for(auto i : j){ if(i == -1)cout << "."; else cout << "#"; }cout << endl;}
  cout << endl;
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int h, w;
  cin >> h >> w;
  vector< vector<int> > v(h, vector<int>(w, -3));
  for(auto& i : v){
    for(auto& j : i){
      char c ; cin >> c;
      j = c == '.' ? -1 : 0;// white: . black: # 
      //white: -1 black: 0
    }
  }
  
  if(v[0][0] == 0 || v[h-1][w-1] == 0) {cout << -1 << endl; return 0;}
  
  int whitenum = 0;
  int blacknum = 0;
  for(auto& i : v){for(auto& j : i){ if(j== -1) whitenum++; else blacknum++;}};
  
  
  //bfs
  v[0][0] = 0;
  
  queue<pair<int, int>> q;
  q.push({0,0});
  while(!q.empty()){
    pair<int, int> point = q.front();
    q.pop();
    
    int x = point.first;
    int y = point.second;
    for(int i = 0; i < 4; i++){
      int xx = x + dx[i];
      int yy = y + dy[i];
      //cout << "check point " <<x << " " << y << " " <<xx << " " << yy << " queue:" << q.size()<< endl;
      if(xx >= h || yy >= w || xx < 0 || yy < 0) continue;
      if(v[xx][yy] >= 0) continue;
      //showmatrix_new(v);
      q.push({xx, yy});
      v[xx][yy] = 1 + v[x][y];
    }
  }
  
  //cout << "final check point" << endl;
  if(v[h-1][w-1] < 0) {cout << -1 << endl; return 0;}
  
  int step = v[h-1][w-1] + 1;
  int ans = whitenum - step;
  
  cout << ans << endl;

}

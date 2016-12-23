#include <iostream>
#include <vector>
//0 1 2 3 4 5 6 7 8 9

//1 0 0 0 0 0 1 1 1 0

//1 2 3 4 5 6 7 8 9 10
//1 0 1 1 1 1 1 0 0 1
//10 9 5



using namespace std;

int n, a, b;
vector<bool> table;

int trans(int u, int v){
  if(u > v){
    int t = u;
    u = v; 
    v = t;
  }
  //cout << "u:" << u << " v:" << v << endl;

  if(table[u] == table[v])
    return 0;
  
  int end = v - u;
  bool flag;
  if( end > n/2 ) flag = false;
  else flag = true;

  int sol = 1;
  for(int i = 1; i < end; ++i)
    if(table[ (u + i) % n ] == table[v] && flag){
      sol = trans( (u + i) % n, v ) + 1;
      break;
    }
    else if (table[ (u - i + n) % n ] == table[v] && !flag){
      sol = trans( (u - i + n) % n, v ) + 1;
      break;
    }
  //cout << "sol: " << sol << endl;
  return sol;
}

int main(){
  
  //input
  cin >> n >> a >> b;
  a -= 1;
  b -= 1;

  char c;
  while(cin >> c)
    table.push_back(static_cast<int>(c) - '0');

  /*
  for(auto p = table.begin(); p != table.end(); ++p)
    cout << *p << " " ;
  cout << endl;
  */
  
  int t = trans(a, b);

  cout << t << endl;
  return 0;
}

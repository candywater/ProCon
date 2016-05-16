/*c++11*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
  if(a.first != b.first)
    return a.first < b.first;
  else 
    return a.second < b.second;
}

bool compare1(pair<int, int> a, pair<int, int> b){
  return a.first < b.first;
}
bool compare2(pair<int, int> a, pair<int, int> b){
  return a.second > b.second;
}

int main(int args, char *argc[]){

  int n;
  vector<pair<int,int> > a;
  vector<pair<int,int> > b;

  cin >> n;
  for(int i=0;i<n;i++){
    int c,d;
    cin>>c>>d;
    if(c < d)
      a.push_back(make_pair(c,d));
    else 
      b.push_back(make_pair(c,d));
  }

  /*
  cout<<"====="<<endl;
  for(auto i = a.begin(); i != a.end(); i++){
    cout<<i->first<<" "<<i->second<<endl;
  }
  cout<<"====="<<endl;
  */

  sort(a.begin(),a.end(),compare1);
  sort(b.begin(),b.end(),compare2);

  long int max = 0;
  long int now = 0;

  for(auto i = a.begin(); i != a.end(); i++){
    now += (i->first);
    if(now > max) max = now;
    now -= (i->second);
  }
  for(auto i = b.begin(); i!= b.end(); i++){
    now += (i->first);
    if(now > max) max = now;
    now -= (i->second);
  }

  cout<<max<<endl;

  return 0;
}

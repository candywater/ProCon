#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

string res;

//bfs
void solve(int left,int num){

//  printf("left:%d,num:%d\n",left,num);
  
  if(num<0)
    return;

  if(num==0){
    //cout<<"--"<<res<<"--"<<endl;
    //printf("res:%lu\n",res.size());
    res.resize(res.size()-1);
    cout<<res<<endl;
    res.push_back(' ');
    return;
  }

  for(int i=left;i>0;i--){
    res.append(to_string(i));
    res.push_back(' ');
    solve(i,num-i);
    res.resize(res.size()-to_string(i).size()-1);
  }
  return;
}

int main(int args, char *argc[]){
  int num;
  while(cin>>num,num){
    solve(num,num);
    res.clear();
  }
  return 0;
}

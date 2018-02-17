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

using namespace std;
    
vector<int> table;

int solve1(){
  int count=1,res=0;
  int a=*table.begin(),b;
  for(auto it=table.begin()+1;it!=table.end();it++){
    b=*it;
    if(b==a+1)
//      cout<<"b:"<<b<<" ",
      count++;
    else {
      if(count>res)
        res=count;
      count=1;
    }
    a=b;
  }
  return res;
}
int solve2(){
  int count=1,res=0;
  vector<int> len;
  vector<bool> canConnect;
  
  int a=*table.begin(),b;
  for(auto it=table.begin()+1;it!=table.end();it++){
    b=*it;
    if(b==a+1)
      count++;
    else{
      len.push_back(count);
      count=1;
      if(b==a+2)
        canConnect.push_back(true);
      else canConnect.push_back(false);
    }
    a=b;
  }
  len.push_back(count);
  
  vector<int> connect;
  connect.push_back(len[0]);
  for(int ix=0;ix<canConnect.size();ix++){
    if(canConnect[ix]==true)
      connect.push_back(len[ix]+len[ix+1]);
    else
      connect.push_back(len[ix]);
  }

  int maxium=0;
  for(auto ix=connect.begin();ix!=connect.end();ix++)
    if(*ix>maxium)
      maxium=*ix;
  res=maxium+1;

/*
  cout<<endl<<"table:"<<endl;
  for(auto i:table)
    cout<<i<<" ";
  cout<<endl<<"len:"<<endl;
  for(auto i:len)
    cout<<i<<" ";
  cout<<endl<<"canConnect:"<<endl;
  for(auto i:canConnect)
    cout<<i<<" ";
  cout<<endl<<"connect:"<<endl;
  for(auto i:connect)
    cout<<i<<" ";
  cout<<endl;
 */ 
  
  return res;
}

int main(int args, char *argc[]){
  static int n,k;
  while(cin>>n>>k,n&&k){
//    cout<<n<<" "<<k<<endl;
    bool flag=false;
    int tmp;
    table.clear();
    for(int i=0;i<k;i++){
      cin>>tmp;
      table.push_back(tmp);
      if(tmp==0) flag=true;
    }
    sort(table.begin(),table.end());
    if(flag)
      tmp=solve2();
    else 
      tmp=solve1();
    cout<<tmp<<endl;
  }
  return 0;
}

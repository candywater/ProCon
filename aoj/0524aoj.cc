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

void print_0(vector<pair<int, int> > *target,
    multimap<int,int> *table){
  cout<<"target: ";
  for(auto ix=target->begin();ix!=target->end();ix++)
    cout<<"("<<ix->first<<","<<ix->second<<")";
  cout<<endl;

  cout<<"table: ";
  for(auto ix=table->begin();ix!=table->end();ix++)
    cout<<"("<<ix->first<<","<<ix->second<<")";
  cout<<endl;
  cout<<endl;

}

int main(int args, char *argc[]){

  int n,m;
  vector<pair<int,int> > target;
  multimap<int,int> table;
  //log(10^7)=20*log(10)=23
  while(cin>>n,n){
    //initial
    target.clear();
    table.clear();
    //INPUT
    int a,b,c,d;
    cin>>a>>b;
    for(int i=1;i<n;i++)
      cin>>c>>d,
        target.push_back(make_pair(c-a,d-b));

    cin>>m;
    for(int i=0;i<m;i++)
      cin>>c>>d,
        table.insert(make_pair(c,d));

    //print_0(&target,&table);

    //PROCESS
    bool flag;
    bool fflag;
    for(auto ix=table.begin();ix!=table.end();ix++){
      flag=true;
      for(auto iy=target.begin();iy!=target.end();iy++){
        fflag=false;
        for(auto iz=table.lower_bound(ix->first+iy->first);iz!=table.upper_bound(ix->first+iy->first);iz++){
          if(iz->second == ix->second+iy->second){
            fflag=true;
            break;
          }
        }
        //not the same pattern
        if(fflag==false){
          flag=false;
          break;
        }
      }//for range of target
      if(flag==true){
        c=ix->first,
          d=ix->second;
        break;
      }
    }

    if(flag)
      cout<<(c-a)<<" "<<(d-b)<<endl;

  }//while

  return 0;
}

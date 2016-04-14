/*c++11*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>

using namespace std;

class point{
  public:
    int x,y;
    point(){
      x=0,y=0;
    }
    point(int x,int y){
      this->x=x;
      this->y=y;
    }
};

int res=0;

//a---------c
//b--------」
int area(point a,point b,point c){
  int v1x=a.x-c.x;
  int v1y=a.y-c.y;
  int v2x=b.x-c.x;
  int v2y=b.y-c.y;
  int tmp=v1x*v2y-v2x*v1y;

  return (tmp>0?tmp:-tmp);
}

multimap<int,int>::iterator ifExist(int ia,int ib,multimap<int,int> *table){
  if(table->count(ia)==0)
    return table->end();
  multimap<int,int>::iterator tmp;
  tmp=table->lower_bound(ia);
  while(tmp!=table->upper_bound(ia) && tmp->second != ib)
    tmp++;
  if(tmp!=table->upper_bound(ia))
    return tmp;
  else 
    return table->end();
}

/*
   上方面：(a,b),(a+x,b+y),(a-y,b+x),(a+x-y,b+y+x)
   下方面：(a,b),(a+x,b+y),(a+y,b-x),(a+x+y,b+y-x)
 */
void ifRec(multimap<int,int>::iterator a,
    multimap<int,int>::iterator b,
    multimap<int,int> *table){

  int lx=b->first - a->first;
  int ly=b->second - a->second;

  //
  /*cout<<"上方面：";
  printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)\n",
      a->first,a->second,
      b->first,b->second,
      a->first-ly,a->second+lx,
      a->first+lx-ly,a->second+ly+lx);
  cout<<"下方面：";
  printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)\n",
      a->first,a->second,
      b->first,b->second,
      a->first+ly,a->second-lx,
      a->first+lx+ly,a->second+ly-lx);
      */


  //上方面
  auto t1=ifExist(a->first-ly,a->second+lx,table);
  if(t1!=table->end()){
    auto t2=ifExist(a->first+lx-ly, a->second+ly+lx,table);
    if(t2!=table->end()){
      int tmp=area(point(a->first + lx - ly,a->second + lx + ly),
          point(b->first, b->second),point(a->first,a->second));
      res=(res<tmp) ? tmp:res;
      //cout<<"tmp:"<<tmp<<endl;
    }
  }

  //下方面
  t1=ifExist(a->first+ly,a->second-lx,table);
  if(t1!=table->end()){
    auto t2=ifExist(a->first+ly+lx,a->second+ly-lx,table);
    if(t2!=table->end()){
      int tmp=area(point(a->first +ly + lx,a->second + ly-lx),
          point(b->first, b->second),point(a->first,a->second));
      res=(res<tmp)?tmp:res;
      //cout<<"tmp:"<<tmp<<endl;
    }
  }
  return;

}



int main(int args, char *argc[]){
  //(n-1)*(n-2)*2<=18*10^7
  //0~5000,5000*5000=2.5*10^7=25MB
  //65536kb=64MB
  multimap<int,int> table;
  int n;

  while(cin>>n,n){
    res=0;
    table.clear();
    int x,y;
    for(int i=0;i<n;i++){
      cin>>x>>y;
      table.insert(make_pair(x,y));
    }

    for(auto ix=table.begin();ix!=--table.end();ix++){
      auto tmp=ix;
      tmp++;
      for(multimap<int,int>::iterator iy=tmp;iy!=table.end();iy++){
        ifRec(ix,iy,&table);
      }
    }
    cout<<res<<endl;
  }

  return 0;
}

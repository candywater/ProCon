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

int card=-1;

void print(vector<int> *a,vector<int> *b){
  
  cout<<"card:"<<card<<endl;
  printf("a:%lu,b:%lu\n",a->size(),b->size());

  cout<<"a:";
  for(auto ix:*a)
    cout<<ix<<" ";
  cout<<endl;

  cout<<"b:";
  for(auto iy:*b)
    cout<<iy<<" ";
  cout<<endl;
  cout<<endl;

}

int main(int args, char *argc[]){
  int n;
  vector<int> a;
  vector<int> b;

  while(cin>>n,n){
    a.clear();
    b.clear();
    for(int i=0;i<n;i++){
      int tmp;
      cin>>tmp;
      a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    int ia=0;
    for(int i=1;i<=2*n;i++){
      if(i==a[ia]){
        ia++;
        continue;
      }
      b.push_back(i);
    }
    sort(b.begin(),b.end());

//    print(&a,&b);

    card=a[0];
    bool flaga=false;
    bool flagb=false;
    while(!a.empty() && !b.empty()){

      flaga=false;
      //b passed the round
      if(flagb==false)
        card=-1;
      for(unsigned ix=0;ix!=a.size();ix++){
        if(a[ix]>=card){
          card=a[ix];
          a.erase(a.begin()+ix);
          flaga=true;
          break;
        }
      }

//      cout<<"after a;\n";
//      print(&a,&b);
      
      if(a.empty() || b.empty())
        break;

      flagb=false;
      //a passed the round
      if(flaga==false)
        card=-1;
      for(unsigned ix=0;ix!=b.size();ix++){
        if(b[ix]>card){
          card=b[ix];
          b.erase(b.begin()+ix);
          flagb=true;
          break;
        }
      }

//      cout<<"after b;\n";
//      print(&a,&b);
    }//while

    cout<<b.size()<<endl<<a.size()<<endl;
  }

  return 0;
}

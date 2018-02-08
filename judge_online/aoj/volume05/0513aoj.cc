/*c++98*/
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

int n;

void p(int *card){
  printf("card\'s order:");
  for(int i=0;i<2*n;i++)
    printf("%d ",card[i]);
  printf("\b\n");
}
void shuffle(int *card){
  int tmp[n];
  for(int i=n;i<2*n;i++){
    tmp[i-n]=card[i];
  }
  for(int i=n-1;i>=0;i--){
    //bottom half
    card[2*i+1]=tmp[i];
    //top half
    card[2*i]=card[i];
  }
}
void cut(int k,int *card){
  int tmp[k];
  for(int i=0;i<k;i++){
    tmp[i]=card[i];
  }
  for(int i=0;i<2*n-k;i++){
    card[i]=card[i+k];
  }
  for(int i=2*n-k;i<2*n;i++){
    card[i]=tmp[i+k-2*n];
  }
}
int main(int args, char *argc[]){
  int m;
  while(cin>>n>>m){
    int card[2*n];
    for(int i=0;i<2*n;i++)
      card[i]=i+1;
//    p(card);

    while(m--){
      int k;
      cin>>k;
      if(k)
        cut(k,card);
      else
        shuffle(card);
 //     p(card);
    }
    for(int i=0;i<2*n;i++)
      cout<<card[i]<<endl;
  }
  return 0;
}

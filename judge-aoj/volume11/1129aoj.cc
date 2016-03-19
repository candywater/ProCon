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
#include <deque>

using namespace std;

int n=0;//num
int r=0;//round

//just simulate
int main(int args, char *argc[]){
  while(cin>>n>>r){
    if(n==0 && r==0)
      return 0;
    deque<int> cards;
    for(int i=0;i<n;i++)
      cards.push_front(i+1);

    //test
    /*for(int i=0;i<n;i++)
      printf("[%d]:%d ",i,cards[i]);
      puts("");
     */

    int a,b;
    for(int i=0;i<r;i++){
      cin>>a>>b;
      //for(int ix=a-1;ix<=a+b-2;ix++){
      for(int ix=a+b-2;ix>=a-1;ix--){
        int temp=cards[a+b-2];
/*      printf("i:%d ix:%d temp:%d\n",i,ix,temp);*/
        cards.erase(cards.begin()+(a+b-2));
        cards.push_front(temp);
      }
/*      printf("i--%d a:%d b:%d -- ",i,a,b);
      for(int i=0;i<n;i++)
        printf("[%d]:%d ",i,cards[i]);
      puts("");*/
    }

/*    cout<<"last\n";
    for(int i=0;i<n;i++)
      printf("[%d]:%d ",i,cards[i]);
    puts("");*/
    cout<<cards[0]<<endl;

    }
    return 0;
  }

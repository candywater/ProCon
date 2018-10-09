#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>

#define correct 0
#define incorrect 100 
#define light -2
#define heavy 2
/*
#define A 0;
#define B 1;
#define C 2;
#define D 3;
#define E 4;
#define F 5;
#define G 6;
#define H 7;
#define I 8;
#define J 9;
#define K 10;
#define L 11;
 */
//reference:
//https://github.com/YvesChan/codebak/blob/master/POJ%201013%20%E7%A7%B0%E7%A1%AC%E5%B8%81%E3%80%82%E6%9A%B4%E5%8A%9B%EF%BC%8C%E6%A8%A1%E6%8B%9F%EF%BC%8C%E5%A5%87%E8%91%A9%E8%A7%A3%E6%B3%95.cpp
using namespace std;

int alpha[12][3];

int main(void){
  int n;
  cin >> n;
  int table[3]={0};

  for(int i0=0;i0<n;i0++){
    for(int i=0;i<12;i++)
      memset(alpha[i],0,sizeof(alpha[i]));
    string a,b,c;
    for(int i1=0;i1<3;i1++){
      cin>>a>>b>>c; 
      if(c.compare("even")==0){
 //       printf("even[%d]\n",i1);
        table[i1]=0;
        for(int i=0;i<a.size();i++){
          alpha[a[i]-'A'][i1]=1;
          alpha[b[i]-'A'][i1]=1;
        }
      }     
      else if(c.compare("down")==0){
  //      printf("down[%d]\n",i1);
        table[i1]=2;
        for(int i=0;i<a.size();i++){
          alpha[a[i]-'A'][i1]=2;
          alpha[b[i]-'A'][i1]=-2;
        }
      }
      else {
   //     printf("up[%d]\n",i1);
        table[i1]=-2;
        for(int i=0;i<a.size();i++){
          alpha[a[i]-'A'][i1]=2;
          alpha[b[i]-'A'][i1]=-2;
        }
      }
    }
    for(int i=0;i<12;i++){
      char tmp='A';
      if(alpha[i][0]==table[0]
          &&alpha[i][1]==table[1]
          &&alpha[i][2]==table[2]){
       printf("%c is the counterfeit coin and it is light.\n",tmp+i);
      }
       else if(alpha[i][0]==(-table[0])
           &&alpha[i][1]==(-table[1])
           &&alpha[i][2]==(-table[2])){
         printf("%c is the counterfeit coin and it is heavy.\n",tmp+i);
       }
      // printf("%c[0]:%d,[1]:%d,[2]:%d\n",tmp+i,alpha[i][0],alpha[i][1],alpha[i][2]);
    }
  }

  return 0;
}









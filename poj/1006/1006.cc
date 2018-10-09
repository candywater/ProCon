#include <iostream>
#include <stdio.h>

using namespace std;

/*
   periods of length of 
   cycle physical:    23
   cycle emotional:   28
   cycle intellectual:33
   given_day <= 365
 */
int main(void){
    int p,e,i,d;
    int count=0;
    cin >> p >> e >> i >> d;
    while(p!=-1 || e!=-1 || i!=-1 || d!=-1){
        while(p<=d) p+=23;
        while(e<=d) e+=28;
        while(i<=d) i+=33;
        while(p>d && (p-23)>d) p-=23;
        while(e>d && (e-28)>d) e-=28;
        while(i>d && (i-33)>d) i-=33;
        //cycle physicalを基準に、eとiを合わせよう
        //とするつもりだが、なんだかうまく書けない。
        //うまく書けたようだ！！！！:w?
        while((p!=i)||(p!=e)||(i!=e)){
            p+=23;
            while(e<p) e+=28;
            while(i<p) i+=33;
        }
        //cout <<p<<" "<<e<<" "<<i<<" "<<d<<endl;
        count++;
        //Case 1: the next triple peak occurs in 1234 days. 
        cout <<"Case "<< count <<
            ": the next triple peak occurs in " 
            <<p-d<<" days."<<endl;
        cin >> p >> e >> i >> d;
    }
    return 0;
}

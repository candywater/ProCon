#include <stdio.h>
#include <iostream>

using namespace std;
int main(void){
    int a,b,c;
    int cycleA,cycleB;
    cout<<"period of a,b:";
    cin >> cycleA >> cycleB;
    cin >> a >> b >> c;
    while(a<=c) a+=cycleA;
    while(b<=c) b+=cycleB;
    while(a>c && (a-cycleA)>c) a-=cycleA;
    while(b>c && (b-cycleB)>c) b-=cycleB;
    while((a!=b)){
        while(b<a) b+=cycleB;
        a+=cycleA;        
    }
    cout << b-c<<endl;
    return 0;

}

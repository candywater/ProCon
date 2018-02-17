#include <iostream>
#include <stdio.h>

using namespace std;

int main(void){
    double balance;
    double sum=0;
    double average;
    for(int i=0;i<12;i++){
        cin >> balance;
        sum += balance;
    }
    printf("$%.2f\n",sum/12);
    return 0;

}

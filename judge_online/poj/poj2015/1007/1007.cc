#include <iostream>
#include <stdio.h>

using namespace std;
/*
char swapptr(char (**tmp1)[51], char (**tmp2)[51]){
    char (**tmp)[51];
    *tmp=*tmp1;
    *tmp1=*tmp2;
    *tmp2=*tmp;
}
*/
int main(void){
    int length,number;
    cin >> length >> number;
    char str[number][51];
    int score[101];
    for(int i=0;i<101;i++) score[i]=0;
    for(int j=0;j<number;j++){
        scanf("%s",str[j]);
        //count the number of inversions
        for(int k=0;k<length-1;k++){
            for(int l=k+1;l<length;l++){
                if(str[j][k] > str[j][l])
                    score[j]+=1;
            }
        }
    }



    /*//sort order of the output data
    int order[number]={number};
    for(int j=0;j<number-1;j++){
        int s_tmp=score[j];
        int o_tmp=j;
        for(int k=j+1;k<number;k++){
            if(score[k]<s_tmp){
                s_tmp=score[k];
                o_tmp=k;
            }
        }
        order[o_tmp]=j;
    }
*/

    /*
    //sort
    for(int i=0;i<number-1;i++){
        for(int j=i+1;j<number;j++){
            if(score[i]>score[j]){
                int tmp;
                tmp=score[j];
                score[j]=score[i];
                score[i]=tmp;
                swapptr(&str[i],&str[j]);
            }
        }
        }
     */  
    
    /*
    //検証用:w
    for(int i=0;i<number;i++){
        cout << "score:" << score[i] << endl;
    }
    for(int i=0;i<number;i++){
         cout << str[i] << endl;
     }cout << endl;

    string output[number];
    for(int i=0;i<number;i++){
        output[i]=str[i];
    }
    */
    //sort
    for(int i=0;i<number-1;i++){
        for(int j=i+1;j<number;j++){
            if(score[i]>score[j]){
                int tmp=score[i];
                score[i]=score[j];
                score[j]=tmp;
                swap(str[i],str[j]);
            }
        }
    }
    //検証用:w
    /*for(int i=0;i<number;i++){
        cout << "score:" << score[i] << endl;
    }*/
    for(int i=0;i<number;i++){
        cout << str[i] << endl;
    }
    //cout << endl;   
/*
    char (*tmp1)[51]=&str[0];
    cout << *tmp1 << endl;
    cout << tmp1 << endl;
    char (*tmp2)[51]=&str[1];
    cout << *tmp2 << endl;
    cout << tmp2 << endl;
    cout << "str address:" << &str[0] <<endl << &str[1] <<endl;
    char (*tmp)[51]=tmp1;
    tmp1=tmp2;
    tmp2=tmp;
    cout << *tmp1 << endl << *tmp2 << endl;
    cout << tmp1 << endl << tmp2 << endl;
    cout << "str address:" << &str[0] <<endl << &str[1] <<endl;
*/
    /*
    char (**tmp1)[51], (**tmp2)[51];
    *tmp1=&str[0],*tmp2=&str[1];
    swapptr(tmp1,tmp2);
    for(int i=0;i<number;i++){
        cout << str[i] << endl;
    }
    */

    return 0;
}

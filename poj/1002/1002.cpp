#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#define n 1000*100

using namespace std;

int main(void){
    //number Table
    map<int,int> numberTable;
    numberTable.clear();
    //number of database
    int sortNum=0;
    //number of data
    int num;
    //number string
    //     string str;
    const char *number;
    char trueNumber[50]={0};
    //int k;
    //cin >> num ;
    scanf("%d",&num);
    //はじめのnumberの行の改行
    //     getline(cin,str);
    for(int i=0;i<num;i++){
        //index of trueNumber[]
        //string のリセット
        //getline(cin,str);
        //number=str.c_str();
        scanf("%50s",trueNumber);
        number=trueNumber;
        int tmp=0;

        for(int j=0;j<50;j++){
            if(*(number+j)==0) break;
            if(*(number+j)=='-') continue;
            //数字の場合
            if(*(number+j)<='9'){
                tmp=10*tmp+*(number+j)-'0';
            }
            //英字の場合
            else {
                int t=*(number+j)-'A';
                if(t<=15){
                    tmp=10*tmp+t/3+2;
                }
                else {
                    tmp=10*tmp+(t-1)/3+2;
                }
            }
        }
        //cout << tmp << endl;
        /*
           for(int j=0;j<50;j++){
           if(*(number+j)==0)break;
           switch(*(number+j)){
           case '-':break;
           case 'A':case 'B':case 'C':
        //trueNumber[k]='2';
        tmp=10*tmp+2;
        //k++;
        break;
        case 'D':case 'E':case 'F':
        tmp=10*tmp+3;break;
        //trueNumber[k]='3';k++;break;
        case 'G':case 'H':case 'I':
        tmp=10*tmp+4;break;
        //trueNumber[k]='4';k++;break;
        case 'J':case 'K':case 'L':
        tmp=10*tmp+5;break;
        //trueNumber[k]='5';k++;break;
        case 'M':case 'N':case 'O':
        tmp=10*tmp+6;break;
        //trueNumber[k]='6';k++;break;
        case 'P':case 'R':case 'S':
        tmp=10*tmp+7;break;
        //trueNumber[k]='7';k++;break;
        case 'T':case 'U':case 'V':
        tmp=10*tmp+8;break;
        //trueNumber[k]='8';k++;break;
        case 'W':case 'X':case 'Y':
        tmp=10*tmp+9;break;
        //trueNumber[k]='9';k++;break;
        case '1':case '2':case '3':
        case '4':case '5':case '6':                    
        case '7':case '8':case '9':                    
        case '0':
        tmp=10*tmp+*(number+j)-'0';break;
        //trueNumber[k]=*(number+j);k++;break;
        default:
        break;
        }//switch
        }//for 
         */
        //write to telDataBase
        if(numberTable.find(tmp)!=numberTable.end()){
            numberTable[tmp]+=1;
            //cout << tmp << endl;
        }
        else{	
            numberTable.insert(map<int,int>::value_type(tmp,0));
            //cout << tmp << endl;
            sortNum +=1;
        }
    }

    /*quick sort*/
    /*listLength:sortNum+1*/
    //qsort(numberTable,sortNum+1,sizeof(*numberTable),numberComp);

    /*output*/
    int _bool=0;
    map<int,int>::iterator itr;
    for(itr=numberTable.begin();itr != numberTable.end();itr++){
        if(itr->second == 0 ){ 
            continue;
        }
        /*
           if(itr->first <=(100*1000-1) ){
           continue;
           }
           if(itr->first>=(1000*10000)){
           continue;
           }
         */
        char tmp[7];
        int x=itr->first;
        for(int i=7;i>0;i--){
            if(x%10==0)
                tmp[i-1]='0';
            tmp[i-1]=x%10+'0';		
            x=x/10;
        } 
        printf("%c%c%c-%c%c%c%c %d\n",tmp[0],tmp[1],tmp[2],tmp[3],
                tmp[4],tmp[5],tmp[6],itr->second+1);
        _bool=1;
    }
    if(!_bool){
        cout<< "No duplicates." << endl;
    }

    return 0;

}

#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

/*
   Haab calendar(365days)(20days each)(19 monthes)
   pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu, uayet(5days)
   Tzolkin calendar(260days)(13periods,20days each)
   imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau

Haab: 0.pop 0
Tzolkin: 1 imix 0


Sample Input

3
10. zac 0
0. pop 0
10. zac 1995

Sample Output

3
3 chuen 0
1 imix 0
9 cimi 2801
 */


int main(void){

    map<string, int> month_switch;
    month_switch["pop"]=0;
    month_switch["no"]=1;
    month_switch["zip"]=2;
    month_switch["zotz"]=3;
    month_switch["tzec"]=4;
    month_switch["xul"]=5;
    month_switch["yoxkin"]=6;
    month_switch["mol"]=7;
    month_switch["chen"]=8;
    month_switch["yax"]=9;
    month_switch["zac"]=10;
    month_switch["ceh"]=11;
    month_switch["mac"]=12;
    month_switch["kankin"]=13;
    month_switch["muan"]=14;
    month_switch["pax"]=15;
    month_switch["koyab"]=16;
    month_switch["cumhu"]=17;
    month_switch["uayet"]=18;

    map<int, string> Tz_switch;
    Tz_switch[0]="imix";
    Tz_switch[1]="ik";
    Tz_switch[2]="akbal";
    Tz_switch[3]="kan";
    Tz_switch[4]="chicchan";
    Tz_switch[5]="cimi";
    Tz_switch[6]="manik";
    Tz_switch[7]="lamat";
    Tz_switch[8]="muluk";
    Tz_switch[9]="ok";
    Tz_switch[10]="chuen";
    Tz_switch[11]="eb";
    Tz_switch[12]="ben";
    Tz_switch[13]="ix";
    Tz_switch[14]="mem";
    Tz_switch[15]="cib";
    Tz_switch[16]="caban";
    Tz_switch[17]="eznab";
    Tz_switch[18]="canac";
    Tz_switch[19]="ahau";

    int num;
    cin >> num;
    cout << num << endl;
    for(int i=0;i<num;i++){
        int day,month,year;
        char *m=new char;
        scanf("%d. ",&day);
        scanf("%s ",m);
        scanf("%d",&year);
        string mon=m;
        //delete m;
        map<string, int>::iterator tmp=month_switch.find(mon);
        if(tmp!=month_switch.end()){
            month=tmp->second;
        }

        int totalDays;
        totalDays=year*365+month*20+day;

        int TzDay,TzMonth,TzYear;
        string TzD;
        TzYear=totalDays/260;
        totalDays=totalDays%260;

        // cout <<"totalDays:"<< totalDays <<endl;

        TzDay=totalDays%20;
        TzMonth=(totalDays)%13+1;
        //TzMonth=TzMonth?TzMonth:13;
        map<int, string>::iterator TzTmp=Tz_switch.find(TzDay);
        if(TzTmp!=Tz_switch.end()){
            TzD=TzTmp->second;
        }

        cout <<TzMonth<<" "<<TzD<<" "<<TzYear<<endl;
    }
    return 0;

}

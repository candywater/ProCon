#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
	char p = '.';
	string a;
	string b;
	string dit;
	string all;

	char tmp;
	bool flag = false;
	int d;

	cin >> all;

	for(auto ia = all.begin(); ia != all.end(); ia++){
		tmp = *ia;
		if(tmp == p){
			flag = true;
			continue;
		}
		if(tmp == 'e'){
			ia++;
			string td;
			td.assign(ia, all.end());
			d = stoi(td);
			break;
		}
		if(!flag)
			a.push_back(tmp);
		else 
			b.push_back(tmp);
	}

	//debug
	//cout << "a.size:" << a.size() << endl;

	cout << a;
	int i;
	for(i = 0; i < d; i++){
		if(i < b.length())
			printf("%c",b[i]);
		else
			printf("0");
	}
	if(i < b.length() && !(b.length()==1 && b[0]=='0'))
		cout << p;
	else{
		cout << endl;
		return 0;
	}
	for(int ib = i; ib != b.length(); ib++)
		cout << b[ib];
	cout << endl;

	return 0;
}

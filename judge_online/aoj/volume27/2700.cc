//c++11
// 最初は問題を理解し間違えた。。なんだと。。。kが文字列の長さより長い場合では、元の文字列を頭からコピーして、長さがkになるまでコピーするのだと勘違いした。なぜ。。。。。orz
#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool judge(char);
int compareLength(string, string);
void solve(int);

bool judge(char x){
	//a,i,u,e,o
	return (x == 'a' || x == 'i' || x == 'u'
			|| x == 'e' || x == 'o');
}

int compareLength(string a, string b){
	int i = 0;
	while(a[i] == b[i]){
		i++;
	}
	return i;
}

void solve(int n){
	vector<string> table;
	multiset<string> newtable;
	//INPUT
	for(int iz = 0;iz < n;iz++){
		string tmp = "";
		string input;

		cin >> input;
		tmp.push_back(input[0]);

		for(string::iterator i = input.begin(); i != input.end()-1; i++ ){
			if(judge(*i))
				tmp.push_back(*(i+1));
		}
		newtable.insert(tmp);
	}
	
	//resize 
	/*
	for(vector<string>::iterator i = table.begin(); i != table.end(); i++){
		string tmp = *i;
		string res = *i;
		int ix = 0;
		while(res.length() < 50){
			res.push_back(tmp[ix%tmp.length()]);
			ix++;
			ix %= tmp.length();
		}
		newtable.insert(res);
	}
	*/
	/*cout << "===" << endl;
	for(auto i = newtable.begin(); i != newtable.end(); i++){
		cout << *i << endl;
	}
	cout << "===" << endl;*/

	//compare
	int k = 0;
	for(int i  = 1; i <= 50; i++){
		set<string> dup;
		bool flag = true;
		for(auto it = newtable.begin(); it != newtable.end(); it++){
			int index = i;
			if (it->length() <= i)
				index = it->length();
			if(dup.count(string(it->begin(), it->begin()+index)) >= 1){
				flag = false;
				break;
			}
			dup.insert(string(it->begin(), it->begin()+index));
		}
		if(flag){
			k = i;
			break;
		}
	}
	//output
	if( k == 0 )
		cout << "-1" << endl;
	else 
		cout << k << endl;

	return;
}

int main(){
	int n;
	while(cin >> n, n != 0)
		solve(n);
	return 0;
}

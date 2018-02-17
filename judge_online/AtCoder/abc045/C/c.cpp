#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<bool> s;
static vector<int> exp;
static long long int res = 0;

void sum(){
	int i = 0;
	long long int tmp = exp[i];
	i++;
	while(i != exp.size()){
		if(s[i-1] == false)
			tmp = tmp * 10 + exp[i];
		else{
			res += tmp;
			tmp = exp[i];
		}
		i++;
	}
	res += tmp;

	//cout << "log:" << res << endl;
}

void backtrack(int a, int b){
	if(a == b){
		//cout << "log: went sum()" << endl;
		sum();
		return;
	}

	s[a] = true;
	backtrack(a+1, b);
	s[a] = false;
	backtrack(a+1, b);
}

int main(){
	
	string sexp;
	cin >> sexp;

	for(int i = 0;i < sexp.length(); i++)
		exp.push_back(sexp[i]-'0');
	
	int space = exp.size() - 1;
	s.resize(space, false);

	backtrack(0,space);

	cout << res << endl;

	return 0;
}

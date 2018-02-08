#include <stdio.h>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;

	vector< bitset<100> > a(m, bitset<100>());

	for(int i = 0; i < m;i++)
		for(int j = 0; j < n; j++){
			char b;
			cin >> b;
			a[i][j] = b=='1'?1:0;
		}

	int max = -1;
	int tmp = 0;
	for(int i = 0; i < m; i++){
		//cout << "---" << a[i].to_string<char,std::string::traits_type,std::string::allocator_type>() << endl;
		if(a[i].count() != n){
			tmp++;
		}
		else{
			if(max < tmp){
				max = tmp;
			}
			tmp = 0;
		}
	}
	if(max < tmp){
		max = tmp;
	}

	cout << max << endl;

	return 0;
}

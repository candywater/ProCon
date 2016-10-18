/*
	practice of BFS
 */
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static int r,c;
static int step;
static pair<int, int> start;
static pair<int, int> goal;
//value of table[x][y] is the num of step; wall is -2, and the space is -1
static vector<vector<int> > table;
static int dx[4] = {0, 1, 0, -1};
static int dy[4] = {1, 0, -1, 0};

void input();
void init();
int judge(char);
void print();
char judge(int);



void print(){
	cout << endl;
	for(int iy = 0;iy < r; iy++){
		for(int ix = 0;ix < c; ix++)
			cout << judge(table[ix][iy]);
		cout << endl;
	}
	cout << endl;
}

int bfs(){
	queue<pair<int, int> > que;
	que.push(start);
	table[start.first][start.second] = 0;
	while(!que.empty()){
		pair<int, int> tmp = que.front();
		que.pop();

		if(tmp.first == goal.first && tmp.second == goal.second){
			return table[tmp.first][tmp.second];
		}

		for(int i = 0; i < 4; i++){
			int tx = tmp.first + dx[i];
			int ty = tmp.second + dy[i];
			if(tx >= c || tx < 0 || ty >= r || ty < 0){
				continue;
			}
			if(table[tx][ty] == -1){
				que.push(make_pair(tx, ty));
				table[tx][ty] = table[tmp.first][tmp.second] + 1;
			}
		}
	}
	return 0;
}

void input(){
	cin >> r >> c;
	int a,b;
	cin >> a >> b;
	start = make_pair(b - 1, a - 1);
	cin >> a >> b;
	goal = make_pair(b - 1, a - 1);

	init();

	for(int iy = 0; iy < r; iy++){
		for(int ix = 0; ix < c; ix++){
			char tmp;
			cin >> tmp;
			table[ix][iy] = judge(tmp);
		}
	}

}

void init(){
	table.clear();
	table.resize(c, vector<int>(r, false));
}

//# is wall, . is space
int judge(char x){
	if(x == '#') 
		return -2; 
	else return -1; 
}
char judge(int x){
	if(x == -2)
		return '#';
	else if(x == -1)
		return '.';
	else 
		return (x + '0');
}

int main(void){
	input();
	int res = bfs();
	cout << res << endl;
	return 0;
}

/*
ID:well2821
LANG:C++
TASK:milk3
*/
#include <iostream>
using namespace std;
int full[5];
int state[5];
int mapp[100005][5];
int ans[100];
void pour(int x , int y){
	if (state[x] > 0 && state[y] < full[y]){
		if (full[y] - state[y] >= state[x]){
			state[y] += state[x];
			state[x] = 0;
		}
		else{
			state[x] -= full[y] - state[y];
			state[y] = full[y];
		}
	}
}
int sum = 0;
void dfs(int a , int b , int c){
	for (int i = 1 ; i <= sum ; i ++){
		if (mapp[i][1] == a && mapp[i][2] == b && mapp[i][3] == c){
			return;
		}
	}
	if (a == 0 && c >= 0){
		ans[c] = 1;
	}
	sum ++;
	mapp[sum][1] = a;
	mapp[sum][2] = b;
	mapp[sum][3] = c;
	state[1] = a;
	state[2] = b;
	state[3] = c;
	//a -> b
	pour(1,2);
	dfs(state[1] , state[2] , state[3]);
	state[1] = a;
	state[2] = b;
	state[3] = c;
	//a -> c
	pour(1,3);
	dfs(state[1] , state[2] , state[3]);
	state[1] = a;
	state[2] = b;
	state[3] = c;
	//b -> c
	pour(2,3);
	dfs(state[1] , state[2] , state[3]);
	state[1] = a;
	state[2] = b;
	state[3] = c;
	//b -> a
	pour(2,1);
	dfs(state[1] , state[2] , state[3]);
	state[1] = a;
	state[2] = b;
	state[3] = c;
	//c -> a
	pour(3,1);
	dfs(state[1] , state[2] , state[3]);
	state[1] = a;
	state[2] = b;
	state[3] = c;
	//c -> b
	pour(3,2);
	dfs(state[1] , state[2] , state[3]);
	state[1] = a;
	state[2] = b;
	state[3] = c;
}
int main(){
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	cin >> full[1] >> full[2] >> full[3];
	dfs(0,0,full[3]);
	for (int i = 0 ; i <= full[3] ; i ++){
		if (ans[i] != 0){
			cout << i;
			if (i < full[3]){
				cout << " ";
			}
		}
	}
	cout << endl;
	return 0;
}
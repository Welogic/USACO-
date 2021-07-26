/*
ID:well2821
LANG:C++
TASK:wormhole
*/
#include<iostream>
using namespace std;
int n;
double point[20][3];
int tran[20];
int flag = 0;
int startP = 0;
void dfs(int p){
	if (flag == 1){
		return;
	}
	int next = 0;
	for (int i = 1 ; i <= n + 1 ; i ++){
		if (point[p][2] == point[i][2] && point[p][1] < point[i][1]){
			if (next == 0){
				next = i;
			}
			if (point[i][1] < point[next][1]){
				next = i;
			}
		}
	}
	if (next != 0){
		if (next == startP || tran[next] == startP){
			flag = 1;
		}
		dfs(tran[next]);
	}
}
int sum = 0;
void hole(int x){
	if (x > n/2){
		for (int i = 1 ; i <= n ; i ++){
			flag = 0;
			point[n+1][1] = point[i][1] + 0.5;
			point[n+1][2] = point[i][2];
			startP = n + 1;
			dfs(n+1);
			if (flag == 1){
				sum ++;
				break;
			}
		}
		return;
	}
	for (int i = 1 ; i <= n ; i ++){
		if (tran[i] != 0){
			continue;
		}
		for (int j = i + 1 ; j <= n ; j ++){
			if (tran[j] != 0){
				continue;
			}
			tran[i] = j;
			tran[j] = i;
			hole(x+1);
			tran[i] = 0;
			tran[j] = 0;
		}
		break;
	}
}
int main(){
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i ++){
		cin >> point[i][1] >> point[i][2];
	}
	hole(1);
	cout << sum << endl;
	return 0;
}
/*
ID:well2821
LANG:C++
TASK:transform
*/
#include <iostream>
#include <cstring>
using namespace std;
int before[11][11];
int mid[11][11];
int now[11][11];
int after[11][11];
int n;
bool check(int type){
	for (int i = 1 ; i <= n ; i ++){
		for (int j = 1 ; j <= n ; j ++){
			if (type == 1){
				if (mid[i][j] != after[i][j]){
					return false;
				}
			}
			else if (type == 2){
				if (now[i][j] != after[i][j]){
					return false;
				}
			}
			else{
				if (before[i][j] != after[i][j]){
					return false;
				}
			}
		}
	}
	return true;
}
void way(int type){
	for (int i = 1 ; i <= n ; i ++){
		for (int j = 1 ; j <= n ; j ++){
			if (type == 1) mid[j][n+1-i] = before[i][j];
			if (type == 2) mid[n+1-i][n+1-j] = before[i][j];
			if (type == 3) mid[n+1-j][i] = before[i][j];
			if (type == 4) mid[i][n+1-j] = before[i][j];
		}
	}
}
void comb(int type){
	way(4);
	for (int i = 1 ; i <= n ; i ++){
		for (int j = 1 ; j <= n ; j ++){
			if (type == 1) now[j][n+1-i] = mid[i][j];
			if (type == 2) now[n+1-i][n+1-j] = mid[i][j];
			if (type == 3) now[n+1-j][i] = mid[i][j];
		}
	}
}
int main(){
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	cin >> n;
	char c;
	for (int i = 1 ; i <= n ; i ++){
		for (int j = 1 ; j <= n ; j ++){
			cin >> c;
			before[i][j] = (c == '@')?1:0;
			now[i][j] = before[i][j];
		}
	}
	for (int i = 1 ; i <= n ; i ++){
		for (int j = 1 ; j <= n ; j ++){
			cin >> c;
			after[i][j] = (c == '@')?1:0;
		}
	}
	for (int i = 1 ; i <= 4 ; i ++){
		way(i);
		if(check(1)){
			cout << i << endl;
			return 0;
		}
	}
	for (int i = 1 ; i <= 3 ; i ++){
		comb(i);
		if(check(2)){
			cout << 5 << endl;
			return 0;
		}
	}
	if(check(3)){
		cout << 6 << endl;
		return 0;
	}
	cout << 7 << endl;
	return 0;
}
/*
ID:well2821
LANG:C++
TASK:barn1
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int pos[205];
int blank[205];
int main(){
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	int m,s,c;
	cin >> m >> s >> c;
	int minPos = 205;
	int maxPos = 0;
	int blankNum = 0;
	for (int i = 1 ; i <= c ; i ++){
		cin >> pos[i];
		if (pos[i] > maxPos){
			maxPos = pos[i];
		}
		if (pos[i] < minPos){
			minPos = pos[i];
		}
	}
	if (m >= c){
		cout << c << endl;
		return 0;
	}
	for (int i = 1 ; i <= c ; i ++) {
		for (int j = 1 ; j <= c - i; j ++){
			if (pos[j] > pos[j + 1]){
				swap(pos[j] , pos[j+1]);
			}
		}
	}
	for (int i = 1 ; i <= c ; i ++) {
		if (i != 1 && pos[i] - pos[i-1] > 1){
			blankNum++;
			blank[blankNum] = pos[i] - pos[i-1] - 1;
		}
	}
	for (int i = 1 ; i <= blankNum ; i ++) {
		for (int j = 1 ; j <= blankNum - i; j ++){
			if (blank[j] < blank[j + 1]){
				swap(blank[j] , blank[j+1]);
			}
		}
	}
	int ans = maxPos - minPos + 1;
	m --;
	for (int i = 1 ; m > 0 ; i ++){
		ans -= blank[i];
		m --;
	}
	cout << ans << endl;
	return 0;
}
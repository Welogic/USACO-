/*
ID:well2821
LANG:C++
TASK:beads
*/
#include <iostream>
#include <cstring>
using namespace std;
int a[705];
int n;
int search1(int head){
	int sum = 1;
	int c = a[head];
	for (int i = head+1 ; ; i++){
		if (i > n){
			i = 1;
		}
		if (sum > n){
			sum = n;
			break;
		}
		if (c == 3 && a[i] != 3){
			c = a[i];
			sum ++;
			continue;
		}
		if (a[i] == 3 || a[i] == c){
			sum++;
			continue;
		}
		break;
	}
	return sum;
}
int search2(int head){
	int sum = 1;
	int c = a[head];
	for (int i = head-1 ; ; i--){
		if (i < 1){
			i = n;
		}
		if (sum > n){
			sum = n;
			break;
		}
		if (c == 3 && a[i] != 3){
			c = a[i];
			sum ++;
			continue;
		}
		if (a[i] == 3 || a[i] == c){
			sum++;
			continue;
		}
		break;
	}
	return sum;
}
int main(){
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i ++){
		char beat;
		cin >> beat;
		if (beat == 'r'){
			a[i] = 1;
		}
		else if (beat == 'b'){
			a[i] = 2;
		}
		else{
			a[i] = 3;
		}
	}
	int sum = 2;
	int ans = 0;
	for (int i = 1 ; i <= n ; i ++){
		int right = i;
		int left = i-1;
		if (left == 0){
			left = n;
		}
		sum = search1(right) + search2(left);
		if (sum > n){
			sum = n;
		}
		if (sum > ans){
			ans = sum;
		}
	}
	cout << ans << endl;
	return 0;
}
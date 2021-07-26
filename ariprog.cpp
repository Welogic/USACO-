/*
ID:well2821
LANG:C++
TASK:ariprog
*/
#include <iostream>
using namespace std;
int n,m;
int num[130000];
int main(){
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	cin >> n >> m;
	for (int i = 0 ; i <= m ; i ++){
		for (int j = i ; j <= m ; j ++){
			int x = j*j + i*i;
			num[x] = 1;
		}
	}
	int sum = 0;
	int flag = 0;
	int maxNum = m*m*2;
	for (int b = 1 ; b <= maxNum/(n-1) ; b ++){
		if (n >= 4 && b%4 != 0){
			continue;
		}
		for (int a = 0 ; a <= maxNum ; a ++){
			sum = 0;
			if (a + b*(n-1) > maxNum){
				continue;
			}
			for (int k = a ; k <= maxNum ; k += b){
				if (sum == n){
					break;
				}
				if (num[k] == 0){
					break;
				}
				sum ++;
			}
			if (sum == n){
				cout << a << " " << b << endl;
				flag = 1;
			}
		}
	}
	if (flag == 0){
		cout << "NONE" << endl;
	}
	return 0;
}
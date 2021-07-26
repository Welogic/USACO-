/*
ID:well2821
LANG:C++
TASK:milk
*/
#include <iostream>
#include <cstring>
using namespace std;
int p[5005];
int a[5005];

int main(){
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i ++){
		cin >> p[i] >> a[i];
	}
	for (int i = 1 ; i <= m ; i ++) {
		for (int j = 1 ; j <= m - i; j ++){
			if (p[j] > p[j + 1]){
				swap(p[j] , p[j+1]);
				swap(a[j] , a[j+1]);
			}
		}
	}
	int cost = 0;
	for (int i = 1; i <= m ; i ++) {
		if (n >= a[i]){
			cost += a[i]*p[i];
			n -= a[i];
		}
		else{
			cost += n*p[i];
			n = 0;
		}
		if (n == 0){
			break;
		}
	}
	cout << cost << endl;
	return 0;
}
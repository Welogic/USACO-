/*
ID:well2821
LANG:C++
TASK:numtri
*/
#include <iostream>
using namespace std;
int a[1005][1005];
int tree[1005][1005];
int main(){
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i ++){
		for (int j = 1 ; j <= i ; j ++){
			cin >> a[i][j];
			if (i == n){
				tree[i][j] = a[i][j];
			}
		}
	}
	for (int i = n - 1 ; i >= 1 ; i --){
		for (int j = 1 ; j <= i ; j ++){
			tree[i][j] = a[i][j] + max(tree[i+1][j] , tree[i+1][j+1]);
		}
	}
	cout << tree[1][1] << endl;
	return 0;
}
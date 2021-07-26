/*
ID:well2821
LANG:C++
TASK:combo
*/
#include <iostream>
#include <cstring>
using namespace std;
int n;
bool check(int x , int y){
	if (n <= 3 || x == y){
		return true;
	}
	if (x%n+1 == y || (x+1)%n+1 == y){
		return true;
	}
	if (y%n+1 == x || (y+1)%n+1 == x){
		return true;
	}
	return false;
}
int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	cin >> n;
	int x,y,z,a,b,c;
	cin >> x >> y >> z >> a >> b >> c;
	int sum = 0;
	for (int i = 1 ; i <= n ; i ++){
		if (!check(i,x) && !check(i,a)){
			continue;
		}
		for (int j = 1 ; j <= n ; j ++){
			if (!check(j,y) && !check(j,b)){
				continue;
			}
			for (int k = 1 ; k <= n ; k ++){
				if (check(i,a) && check(j,b) && check(k,c)){
					sum++;
				}
				else if (check(i,x) && check(j,y) && check(k,z)){
					sum++;
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}
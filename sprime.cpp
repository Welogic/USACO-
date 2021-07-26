/*
ID:well2821
LANG:C++
TASK:sprime
*/
#include <iostream>
using namespace std;
bool ifPrime(long long x){
	for (long long i = 2 ; i*i <= x ; i ++){
		if (x%i == 0){
			return false;
		}
	}
	return true;
}
int n;
int num = 0;
void dfs(int x){
	if (x == n){
		cout << num << endl;
	}
	for (int i = 1 ; i <= 9 ; i ++){
		if (x == 0 && (i == 1 || i == 4 || i == 6 || i == 9)){
			continue;
		}
		if (x != 0 && (i%2 == 0 || i == 5)){
			continue;
		}
		if (ifPrime(num*10 + i)){
			num = num*10 + i;
			dfs(x+1);
			num /= 10;
		}
	}
}
int main(){
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	cin >> n;
	dfs(0);
	return 0;
}
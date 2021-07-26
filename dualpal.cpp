/*
ID:well2821
LANG:C++
TASK:dualpal
*/
#include <iostream>
#include <cstring>
using namespace std;
char num[100];
int f(int x , int b){
	int a[50];
	int head = 0;
	for (int i = 40 ; ; i--){
		if (x%b == x){
			a[i] = x;
			head = i;
			break;
		}
		a[i] = x%b;
		x = x/b;
	}
	for (int i = head ; i <= 40 ; i ++){
		num[i - head + 1] = a[i];
	}
	return 40-head+1;
}
bool check(int len){
	for (int i = 1 ; i <= len ; i ++){
		if (num[i] != num[len+1-i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s;
	cin >> n >> s;
	int sum = 0;
	for (long long i = s + 1 ; ; i ++){
		if (sum == n){
			break;
		}
		int bases = 0;
		for (int j = 2 ; j <= 10 ; j ++){
			int len = f(i,j);
			if(check(len)){
				bases++;
				if (bases == 2){
					break;
				}
			}
		}
		if (bases == 2){
			sum++;
			cout << i << endl;
		}
	}
	return 0;
}
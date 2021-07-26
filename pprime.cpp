/*
ID:well2821
LANG:C++
TASK:pprime
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
bool ifPalin(long long x){
	int num[50];
	int i = 0;
	for (; x > 0 ; x /= 10){
		i ++;
		num[i] = x%10;
	}
	if (i%2 == 0){
		return false;
	}
	for (int j = 1 ; j <= i ; j ++){
		if (num[j] != num[i - j + 1]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	long long a,b;
	cin >> a >> b;
	if (b >= 9989899){
		b = 9989899;
	}
	for (long long i = a ; i <= b ; i ++){
		if (i == 11 || i == 5){
			cout << i << endl;
		}
		if (i%2 == 0 || i%3 == 0 || i%5 == 0){
			continue;
		}
		if (ifPalin(i) && ifPrime(i)){
			printf("%lld\n" , i);
		}
	}
	return 0;
}
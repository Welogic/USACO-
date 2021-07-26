/*
ID:well2821
LANG:C++
TASK:crypt1
*/
#include <iostream>
#include <cstring>
using namespace std;
int alpha[12];
int data[12];
int n;
bool numCheck(int x){
	for ( ; x > 0 ; ){
		if (data[x%10] == 0){
			return false;
		}
		x /= 10;
	}
	return true;
}
bool check(int x , int y){
	if (x*(y%10) > 999 || x*(y/10) > 999 || x*(y%10) < 100 || x*(y/10) < 100){
		return false;
	}
	if ((x*(y%10)) + (x*(y/10))*10 > 9999 || (x*(y%10)) + (x*(y/10))*10 < 1000){
		return false;
	}
	if (numCheck(x*(y%10)) == false || numCheck(x*(y/10)) == false || numCheck((x*(y%10)) + (x*(y/10))*10) == false){
		return false;
	}
	return true;
}
int nums[10];
int sum = 0;
void f(int x){
	for(int i = 1 ; i <= n ; i ++){
		nums[x] = alpha[i];
		if (x < 5){
			f(x+1);

		}
		else{
			if (check( (nums[1]*100+nums[2]*10+nums[3]) , (nums[4]*10 + nums[5]) )){
				sum++;
			}
		}
	}
}
int main(){
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i ++){
		cin >> alpha[i];
		data[alpha[i]] = 1;
	}
	f(1);
	cout << sum << endl;
	return 0;
}
/*
ID:well2821
LANG:C++
TASK:palsquare
*/
#include <iostream>
#include <cstring>
using namespace std;
char num[100];
int alpha[25] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
int f(int x , int b){
	int a[40];
	int head = 0;
	for (int i = 30 ; ; i--){
		if (x%b == x){
			a[i] = x;
			head = i;
			break;
		}
		a[i] = x%b;
		x = x/b;
	}
	for (int i = head ; i <= 30 ; i ++){
		num[i - head + 1] = alpha[a[i]];
	}
	return 30-head+1;
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
	//freopen("palsquare.in","r",stdin);
	//freopen("palsquare.out","w",stdout);
	int b;
	cin >> b;
	for (int i = 1 ; i <= 300 ; i ++){
		int len = f(i*i,b);
		if (check(len)){
			len = f(i,b);
			for (int i = 1 ; i <= len ; i ++){
				cout << num[i];
			}
			cout << " ";
			len = f(i*i,b);
			for (int i = 1 ; i <= len ; i ++){
				cout << num[i];
			}
			cout << endl;
		}
	}
	return 0;
}
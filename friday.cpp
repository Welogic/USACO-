/*
ID:well2821
LANG:C++
TASK:friday
*/
#include <iostream>
#include <cstring>
using namespace std;

int monthDay[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ans[8] = {0,0,0,0,0,0,0,0};
bool ifRun(int year){
	if (year%4 == 0){
		if (year % 100 == 0 && year % 400 != 0){
			return false;
		}
		return true;
	}
	return false;
}
void check(int x){
	int weekday = 1;
	for (int year = 1900 ; year <= x ; year ++){
		if (ifRun(year)){
			monthDay[2] = 29;
		}
		else{
			monthDay[2] = 28;
		}
		for (int month = 1 ; month <= 12 ; month ++){
			for (int day = 1 ; day <= monthDay[month] ; day ++){
				if (day == 13){
					ans[weekday]++;
				}
				weekday++;
				weekday = (weekday - 1)%7 + 1;
			}
		}
	}
	
}
int main(){
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	int n;
	cin >> n;
	check(1900+n-1);
	for (int i = 6 ; i <= 12 ; i ++){
		cout << ans[(i-1)%7 + 1] << ((i==12)?"\n":" ");
	}
	return 0;
}
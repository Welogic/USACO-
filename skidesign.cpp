/*
ID:well2821
LANG:C++
TASK:skidesign
*/
#include <iostream>
using namespace std;
int h[1005];
int main(){
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> h[i];
	}
	for (int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n - i ; j ++){
			if (h[j] > h[j+1]){
				swap(h[j] , h[j+1]);
			}
		}
	}
	long long ans = 0;
	for (int min = 1 ; min <= n ; min ++){
		long long sum = 0;
		for (int i = 1 ; i <= n ; i ++){
			if (h[i] == min || ((h[i] >= min) && (h[i] <= min + 17))){
				continue;
			}
			if (h[i] < min){
				sum += (min-h[i])*(min-h[i]);
			}
			if (h[i] > min + 17){
				sum += (h[i] - min - 17)*(h[i] - min - 17);
			}
		}
		if (min == 1){
			ans = sum;
		}
		if (sum < ans){
			ans = sum;
		}
	}
	cout << ans << endl;
	return 0;
}
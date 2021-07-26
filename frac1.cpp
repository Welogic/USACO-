/*
ID:well2821
LANG:C++
TASK:frac1
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct frac{
	double up;
	double down;
};
frac a[27000];
int num = 0;
int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b) : a;
}
bool cmp(frac x , frac y){
	double xNum = x.up/x.down;
	double yNum = y.up/y.down;
	if (xNum < yNum) return true;
	else return false;
}
int main(){
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 2 ; i <= n ; i ++){
		for (int j = 1 ; j < i ; j ++){
			frac x;
			x.down = i;
			x.up = j;
			int gcdNum = gcd(x.down , x.up);
			x.down /= gcdNum;
			x.up /= gcdNum;
			int flag = 0;
			for (int k = 1 ; k <= num ; k ++){
				if (a[k].up == x.up && a[k].down == x.down){
					flag = 1;
					break;
				}
			}
			if (flag == 1){
				continue;
			}
			num++;
			a[num].up = x.up;
			a[num].down = x.down;
		}
	}
	sort(a+1 , a+1+num , cmp);
	cout << "0/1\n"; 
	for (int i = 1 ; i <= num ; i ++){
		cout << a[i].up << "/" << a[i].down << "\n";
	}
	cout << "1/1\n";
	return 0;
}

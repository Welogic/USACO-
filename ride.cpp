/*
ID:well2821
LANG:C++
TASK:ride
*/
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	string comet;
	string group;
	cin >> comet >> group;
	long long cNum = 1;
	long long gNum = 1;
	for (int i = 0 ; i < comet.size() ; i ++){
		cNum *= (comet[i] - 'A' + 1);
	}
	for (int i = 0 ; i < group.size() ; i ++){
		gNum *= (group[i] - 'A' + 1);
		
	}
	if (cNum%47 == gNum%47){
		cout << "GO" << endl;
	}
	else{
		cout << "STAY" << endl;
	}
	return 0;
}
/*
ID:well2821
LANG:C++
TASK:gift1
*/
#include <iostream>
#include <cstring>
using namespace std;
struct human{
	string name;
	int give;
	int devide;
	int receive;
	int gift;
};
human s[11];
int n;
int check(string name){
	for (int i = 1 ; i <= n ; i ++){
		if (s[i].name == name){
			return i;
		}
	}
	return 0;
}
void read(int id){
	cin >> s[id].gift >> s[id].devide;
	for (int i = 1 ; i <= s[id].devide ; i ++){
		string name;
		cin >> name;
		s[check(name)].receive += s[id].gift/s[id].devide;
		s[id].give += s[id].gift/s[id].devide;
	}
}
int main(){
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);int 
	cin >> n;
	for (int i = 1 ; i <= n ; i ++){
		cin >> s[i].name;
		s[i].receive = 0;
		s[i].give = 0;
	}
	for (int i = 1 ; i <= n ; i ++){
		string name;
		cin >> name;
		read(check(name));
	}
	for (int i = 1 ; i <= n ; i ++){
		cout << s[i].name << " " << s[i].receive - s[i].give << endl;
	}
	return 0;
}
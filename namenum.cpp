/*
ID:well2821
LANG:C++
TASK:namenum
*/
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
string nameList[4700];
int id[15];
int alpha[27] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int main(){
	
	freopen("dict.txt","r",stdin);
	for (int i = 1 ; i <= 4617 ; i ++){
		cin >> nameList[i];
	}
	cin.clear();
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	long long idNum;
	cin >> idNum;
	int len = 0;
	for (; idNum > 0 ; idNum /= 10){
		len++;
		id[len] = idNum%10;
	}
	
	int found = 0;
	for (int i = 1 ; i <= 4617 ; i ++){
		string name = nameList[i];
		if (name.size() != len){
			continue;
		}
		int flag = 0;
		for (int j = 0 ; j < len ; j ++){
			if (alpha[name[j] - 'A'] != id[len-j]){
				flag = 1;
				break;
			}
		}
		if (flag == 1){
			continue;
		}
		else{
			cout << name << endl;
			found = 1;
		}
	}
	if (found == 0){
		cout << "NONE" << endl;
	}
	return 0;
}
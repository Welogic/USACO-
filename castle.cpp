/*
ID:well2821
LANG:C++
TASK:castle
*/
#include <iostream>
using namespace std;
int c[55][55][6]; // 0.W , 1.N , 2.E , 3.S , 4.color
int dir[3][5] = {{0,-1,0,1},{-1,0,1,0}}; // 0.Xdir , 1.Ydir
int roomSize[2505];
int m,n;

int roomNum = 0;
int maxRoomSize = 0;
void dfs(int x , int y){
	c[x][y][4] = roomNum;
	roomSize[roomNum]++;
	for (int i = 0 ; i < 4 ; i ++){
		int nextX = x + dir[0][i];
		int nextY = y + dir[1][i];
		if (c[x][y][i] == 0 && c[nextX][nextY][4] == 0){
			if (nextX >= 1 && nextX <= n && nextY >= 1 && nextY <= m){
				dfs(nextX , nextY);
			}
		}
	}
}
void counter(){
	for (int i = 1 ; i <= roomNum ; i ++){
		roomSize[i] = 0;
	}
	roomNum = 0;
	for (int i = 1 ; i <= n ; i ++){
		for (int j = 1 ; j <= m ; j ++){
			c[i][j][4] = 0;
		}
	}
	for (int i = 1 ; i <= n ; i ++){
		for (int j = 1 ; j <= m ; j ++){
			if (c[i][j][4] > 0){
				continue;
			}
			roomNum++;
			dfs(i , j);
		}
	}
	for (int i = 1 ; i <= roomNum ; i ++){
		if (roomSize[i] > maxRoomSize){
			maxRoomSize = roomSize[i];
		}
	}
}
int newMRsize = 0;
int pushX , pushY;
char pushDir;
void push(){
	for (int j = 1 ; j <= m ; j ++){
		for (int i = n ; i >= 1 ; i --){
			for (int k = 1 ; k < 3 ; k ++){
				if (c[i][j][k] == 0){
					continue;
				}
				if ((i == 1 && k == 1) || (j == m && k == 2)){
					continue;
				}
				c[i][j][k] = 0; // push
				if (k == 1){
					c[i-1][j][3] = 0;
				}
				if (k == 2){
					c[i][j+1][0] = 0;
				}
				counter();
				if (maxRoomSize > newMRsize){
					newMRsize = maxRoomSize;
					pushX = i;
					pushY = j;
					if (k == 2){
						pushDir = 'E';
					}
					else{
						pushDir = 'N';
					}
				}
				c[i][j][k] = 1; // repair
				if (k == 1){
					c[i-1][j][3] = 1;
				}
				if (k == 2){
					c[i][j+1][0] = 1;
				}
			}
		}
	}
}
int main(){
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	cin >> m >> n;
	for (int i = 1 ; i <= n ; i ++){
		for (int j = 1 ; j <= m ; j ++){
			int a = 0; cin >> a;
			if (a & 1){ c[i][j][0] = 1; }
			if (a & 2){ c[i][j][1] = 1; }
			if (a & 4){ c[i][j][2] = 1; }
			if (a & 8){ c[i][j][3] = 1; }
		}
	}
	counter();
	cout << roomNum << endl;
	cout << maxRoomSize << endl;
	push();
	cout << newMRsize << endl;
	cout << pushX << " " << pushY << " " << pushDir <<endl;
	return 0;
}
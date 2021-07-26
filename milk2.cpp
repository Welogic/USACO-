/*
ID:well2821
LANG:C++
TASK:milk2
*/
#include <iostream>
using namespace std;
int plan[1000005];
int main(){
     freopen("milk2.in","r",stdin);
     freopen("milk2.out","w",stdout);
     int n;
     cin >> n;
     int maxTime = 0;
     int minTime = 1000005;
     for (int i = 1 ; i <= n ; i ++){
          int a,b;
          cin >> a >> b;
          for (int j = a ; j < b ; j ++){
               if (plan[j] == 0){}
               plan[j] = 1;
               if (b > maxTime){
                    maxTime = b;
               }
               if (a < minTime){
                    minTime = a;
               }
          }
     }
     int state = -1;
     int maxNo = 0;
     int maxYes = 0;
     int start = 0;
     int end = 1;
     for (int i = minTime ; i <= maxTime ; i ++){
          if (plan[i] != state){
               end = i;
               if (state == 0){
                    if (end - start > maxNo){
                         maxNo = end - start;
                    }
               }
               if (state == 1){
                    if (end - start > maxYes){
                         maxYes = end - start;
                    }
               }
               state = plan[i];
               start = i;
               continue;
          }
     }
     cout << maxYes << " " << maxNo << endl;
     return 0;
}
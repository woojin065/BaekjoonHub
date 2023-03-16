#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
int T, M, N, K, n, m, answer;
int arr[51][51] = {0};
void p(int i, int j){
  arr[i][j]=2;
  for(int d=0;d<4;d++){
    if(0<=i+di[d]&&i+di[d]<M&&0<=j+dj[d]&&j+dj[d]<N){
      if(arr[i+di[d]][j+dj[d]]==1){
        p(i+di[d], j+dj[d]);
      }
    }
  }
}
int main() {
  cin >> T;
  while (T--) {
    answer=0;
    cin >> M >> N >> K;
    for (int i = 0; i < 51; i++)
      for (int j = 0; j < 51; j++)
        arr[i][j] = 0;
    while (K--) {
      cin >> n >> m;
      arr[n][m] = 1;
    }
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if(arr[i][j]==1){
          answer++;
          p(i, j);
        }
      }
    }
    cout<<answer<<endl;
  }
}
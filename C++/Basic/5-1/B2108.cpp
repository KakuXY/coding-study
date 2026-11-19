#include<iostream>
#include<math.h>
using namespace std;
int main(){

int n,m;
cin >> n >> m;
int arr[n][m] = {};
int new_arr[n][m] = {};
for(int i = 0;i < n;i ++){
  for(int j = 0;j < m;j ++){
  cin >> arr[i][j];
  new_arr[i][j] = arr[i][j];//把输入的数组存储到改变数组中
  }
}

for(int i = 1;i < n-1;i ++){
  for(int j = 1;j < m-1;j ++){
    new_arr[i][j] = round( (arr[i][j] + arr[i-1][j] + arr[i+1][j] + arr[i][j-1] + arr[i][j+1]) / 5.0);
  }
}

for(int i = 0;i < n;i ++){
  for(int j = 0;j < m;j ++){
    cout << new_arr[i][j] << ' ';
  }
  cout << endl;
}

}
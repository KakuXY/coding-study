#include<iostream>
using namespace std;
int main(void){

  int n,m,k;
  cin >> n >> m >> k;

  int arr1[n][m],arr2[m][k];
  for(int i = 0;i < n;i ++){
    for(int j = 0;j < m;j ++){
      cin >> arr1[i][j];
}
  }

  for(int i = 0;i < m;i ++){
    for(int j = 0;j < k;j ++){
      cin >> arr2[i][j];
}
  }

  int arr[n][k] = {};
  for(int i = 0;i < n;i ++){
    for(int j = 0;j < m;j ++){
      for(int l = 0;l < k;l ++){
        arr[i][l] += arr1[i][j] * arr2[j][l];
      }
    }
  }

  for(int i = 0;i < n;i ++){
    for(int j = 0;j < k;j ++){
      cout << arr[i][j] << ' ';
    }
    cout << endl;
}
}
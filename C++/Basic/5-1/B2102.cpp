#include<iostream>
using namespace std;
int main(void){

  int arr[5][5];
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> arr[i][j];
    } 
  }//输入数组

  int max_line[5][1];
  for(int i = 0;i < 5;i ++){
    max_line[i][0] = arr[i][0];
    for(int j = 1;j < 5;j ++){
      if(max_line[i][0] < arr[i][j]) max_line[i][0] = arr[i][j];//找出每行最大数值
    }
  }
  
  int min_row[1][5];
  for(int i = 0;i < 5;i  ++){
    min_row[0][i] = arr[0][i];
    for(int j = 1;j < 5;j ++){
      if(min_row[0][i] > arr[j][i]) min_row[0][i] = arr[j][i];
    }
  }
bool a = 0;
for(int i = 0;i < 5;i ++) {
  for(int j = 0;j < 5;j ++){
if(max_line[i][0] == min_row[0][j]){
  cout << i+1 << ' ' << j+1 << ' ' << max_line[i][0] << endl;
  a = 1;
    }
  }
}

if(a == 0) cout << "not found" << endl;

}
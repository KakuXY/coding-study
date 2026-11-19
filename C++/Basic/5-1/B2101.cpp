#include<iostream>
using namespace std;
int main(){

  int m,n;
  cin >> m >> n;

  int array[m][n];
  for(int i = 0;i < m;i ++){
    for(int j = 0;j < n;j ++){
    cin >> array[i][j];
    }
  } //输入数组

  int sum = 0;
  for(int i = 0;i < m;i ++){
    sum += array[i][0];//第0列所有元素
    if(n>1) sum += array[i][n-1];//最后一列所有元素
  }

   for(int i = 1; i < n - 1;i ++){
    sum += array[0][i];//第0行的第二个元素开始倒数第二个元素为止
    if(m>1) sum += array[m-1][i];//最后一行的第二个元素开始倒数第二个元素为止
   }  
  cout << sum << endl;
}
//1-2-1
#include <iostream>
#include<vector>
using namespace std;
int main() {
  vector<int> arr = {0};
  int sum = 0;
  for(int i = 1;;i++){
    arr.push_back(arr[i - 1] + i);
    sum += arr[i];
    if(sum > 20230610 ){
      cout << i - 1 << endl;
      return 0;
    }
  }
}

//先生の書き方

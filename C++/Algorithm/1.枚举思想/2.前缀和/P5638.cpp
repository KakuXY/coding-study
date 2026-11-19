//1-2-2
#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> dis(n - 1);
  for(int i = 2; i <= n; i++) cin >> dis[i];
  
  int sum = 0;
  for(int i = 2; i <= n; i++){
    sum += dis[i];
    if(n - i == k){
      cout << sum << endl;
      break;
    }
  }
}
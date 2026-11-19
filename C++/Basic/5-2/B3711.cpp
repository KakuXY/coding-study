#include<iostream>
#include<vector>
using namespace std;
int main(){

  int t;
  cin >> t;

  vector<int> num;
  for(auto& n: num) cin >> n;
  

  bool found = false;
  for(size_t i = 0; i < num.size() - 1; i++){
    for(size_t j = i; j < num.size(); j++){
      vector<int> temp = num;
      temp.erase(temp.begin() + i, temp.begin() + j);
      for(auto& n: temp){
        if(n % 4 == 0){
          cout << "Yes" << endl;
          found = true;
        }
      }
    }
  }

  if(!found) cout << "No" <<endl;
}
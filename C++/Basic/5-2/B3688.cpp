#include<iostream>
#include<vector>
using namespace std;

int main(){

  int n;
  cin >> n;

  vector<int> v(n);
  for(auto& x: v){
    cin >> x;
}

  do{
    v.insert(v.begin(), v.back());
    v.pop_back();
    for(auto& x: v){
      cout << x << ' ';
    }
    cout << endl;
    }while(n != v.back());
}


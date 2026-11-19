#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = n - 1;i >= 0;i --){
    cin >> arr[i];
  } 
  for(auto x: arr) cout << x << ' ';
  cout << endl;
}
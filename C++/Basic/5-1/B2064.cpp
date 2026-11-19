#include<iostream>
using namespace std;
int main(){
  int n,fib[31];
  fib[1] = fib[2] = 1;
  for(int i = 3; i <= 30 ; i++){
    fib[i] = fib[i-1] + fib[i-2];
  }
  cin >> n;
  while(n--){
    int a;
    cin >>a ;
    cout << fib[a] <<endl;
  }    
}

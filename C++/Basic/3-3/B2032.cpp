#include<iostream>
using namespace std;
int main(){
  int a1,a2,n,sum;
  cin >> a1 >> a2 >>n;
  sum=a1+(a2-a1)*(n-1);
  cout << sum << endl;
}
#include<iostream>
#include<format>
using namespace std;
int main(){
  int n;
  double sum=0.0;
  cin >> n;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    sum += a;
  }
  double ave=sum/n;
  cout<<format("{} {:.5f}\n",sum,ave);
}
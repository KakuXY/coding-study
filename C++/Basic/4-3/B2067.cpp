#include<iostream>
using namespace std;
int main(){
  int m,n;
  int people=0;
  cin>>m>>n;
  int sum=m;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(sum<a){ 
    people++;
    }else{
    sum-=a;
    }
  }
  cout<<people<<endl;
}
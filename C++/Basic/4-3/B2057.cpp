#include<iostream>
using namespace std;
int main(){
  int n,max=0;
  cin>>n;
  for(int i=0;i<n;i++){
    int score;
    cin>>score;
    if(score>max) max=score;
  }
  cout<<max<<endl;
}
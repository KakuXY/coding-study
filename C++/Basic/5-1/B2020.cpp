#include<iostream>
using namespace std;
int main(){
  int sum=0,child[5];
  for(auto& x:child){
    cin >> x;
  }
  for(int i = 0; i < 5; i ++){
    sum += child[i] % 3;
    child[(i+4)%5] += child[i]/3;
    child[(i+1)%5] += child[i]/3;
    child[i] /= 3; 
  }
  for(auto& x: child) cout << x << " ";
  cout << endl;
  cout << sum << endl;

  //for(int i = 0 ; i < 5 ; i++){
    //int j;
    //sum += child[i] % 3;
    //child[i] /= 3 ;
    //if(i+1>4){
      //j = 0;
      //child[j] += child[i];
    //}
    //child[i+1] += child[i];
    //if(i-1<0){
      //j = 4;
      //child[j] += child[i];
  //}
  //child[i-1] += child[i];
  //}
  //for(int i = 0 ; i < 5 ; i++){
  //cout << child[i] << " ";
  //}
  //cout << endl;
  //cout << sum << endl;
}

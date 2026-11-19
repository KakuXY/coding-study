#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 1 ; i <= n ; i++){

    if(i % 7 == 0) continue;
  
  int j=i;
  int num;
    while(j){
      num = j % 10;
      if(num == 7) break;
      j /= 10;
    }
  if(num == 7) continue;
  sum += i * i; 
    }

    cout << sum << endl;
  }

  //bool seven = false;
  //int j=i;
  //while(j){
      //int num = j % 10;
      //if(num == 7) seven=true;
      //j /= 10;
    //}
  //if(seven) continue;
  

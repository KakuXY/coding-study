#include <iostream>
#include<cmath>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int cnt=0;
  for(int i = 2 ;; i++){
  bool prime=true;
  for(int j = 2 ; j <= sqrt(i) ; j++){
      if(i%j==0){
        prime=false;
        break;
      }
    }
   if(prime) cnt++;
   if(cnt==n){
      cout << i << endl; 
      break;
  }   
  }
}


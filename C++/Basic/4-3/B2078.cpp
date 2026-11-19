#include <iostream>
using namespace std;
int main()
{
  long long m;
  int k;
  cin >> m >> k;
  int cnt=0,num=0;
  while(m){
    num=m%10;
    if(num==3){
      cnt++;
    }
    m/=10;
  }  
  //if(cnt==k){
    //cout<<"YES"<<endl;
  //}else{
    //cout<<"NO"<<endl;
  //}
  cout<<(cnt==k?"YES":"NO")<<endl;
}
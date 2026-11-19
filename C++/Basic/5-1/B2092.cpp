#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int light[5000];
  fill(light,light+n+1,1);
  for (int i = 1; i <= n; i++)
  {
    for (int j = i; j<= n; j++){
    if(j%i==0) light[j] = !light[j];
  }
  }
   for (int i = 1; i <= n; i++){
    if(light[i]==0) cout << i << " " ;
   }
   cout << endl;
}
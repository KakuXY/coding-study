#include <iostream>
#include <string.h>
using namespace std;
int main(){
  char str[101];
  cin >> str;

  char n_str[101];
  int len = strlen(str);
  for(int i = 0; i < len; i++){
    n_str[i] = str[i] + str[(i+1)%len];
  }

  n_str[len] = '\0';
  cout << n_str << endl;
}
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int main(){
  char str[10001];
  cin.getline(str, 10001);

  char n_str[10001];
  int len = strlen(str);

  for(int i = 0; i < len; i++){
    if(isalpha(str[i])){
      if(str[i] == 'a'){
        n_str[i] = 'z';
      }else if(str[i] == 'A'){
        n_str[i] = 'Z';
      }else{
        n_str[i] = str[i] - 1;
      }
    }else{
      n_str[i] = str[i];
  }
}

  n_str[len] = 0;
  cout << n_str << endl;
}
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int main(){
  char str[51];
  cin >> str;

  int len = strlen(str);
  char n_str[51];

  for(int i = 0; i < len; i++){
    if(isupper(str[i])){
      n_str[i] = tolower(str[i]);
    }else{
      n_str[i] = toupper(str[i]);
    }
  }

  for(int i = 0; i < len; i++){
    str[i] = n_str[len - i - 1]; 
  }

  for(int i = 0; i < len; i++){
    if (isupper(str[i])) {
      str[i] = (str[i] - 'A' + 3) % 26 + 'A';
    }else{
      str[i] = (str[i] - 'a' + 3) % 26 + 'a';
    }
  }

  str[len] = 0;

  cout << str << endl;
}

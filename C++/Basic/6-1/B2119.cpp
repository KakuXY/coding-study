#include <iostream>
#include <string.h>
using namespace std;
int main(){
  char str[33];
  cin >> str;
  int len = strlen(str);

  char a[] = "er";
  char b[] = "ly";
  char c[] = "ing";

  if(strstr(str, a) && len - 2 != 0){
    len = len - 2;
  }else if(strstr(str, b) && len - 2 != 0){
    len = len - 2;
  }else if(strstr(str, c) && len - 3 != 0){
    len = len - 3;
  }

  str[len] = 0;

  cout << str << endl;
}
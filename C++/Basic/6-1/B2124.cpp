#include <iostream>
#include <string.h>
using namespace std;
int main(){
  char str[100];
  cin.getline(str, 100);

  char str1[50], str2[50];
  int length = strlen(str);
  int half_length = strlen(str) / 2;

  for(int i = 0; i < half_length; i ++){
    str1[i] = str[i];
    str2[i] = str[length - i - 1];
  }
  
  str1[half_length] = '\0';
  str2[half_length] = '\0';

  int order = strcmp(str1, str2);
  if(order == 0) cout << "yes" << endl;
  else cout << "no" << endl;

}
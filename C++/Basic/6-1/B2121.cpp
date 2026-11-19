#include <iostream>
#include <string.h>
using namespace std;
int main(){
  char str[30000];
  cin.getline(str, 30000);

  char token_max[101];
  char token_min[101];
  char delimiter[] = " ,.";
  char* token = strtok(str, delimiter);
  strcpy(token_max, token);
  strcpy(token_min, token);
  while(token){
    if(strlen(token) < strlen(token_min)) strcpy(token_min, token);
    if(strlen(token) > strlen(token_max)) strcpy(token_max, token);
    token = strtok(NULL, delimiter);
  }

  cout << token_max << endl;
  cout << token_min << endl;
}
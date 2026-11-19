#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int main(){
  char str[255];
  cin.getline(str, 255);//输入数组，不能用cin因为cin遇到空格就结束输入数组了

  int count = 0;//计数
  
  for(size_t i = 0;i < strlen(str);i ++){
    if(isdigit(str[i])) count ++;
  }
  
  cout << count << endl;;
}
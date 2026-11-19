#include <iostream>
#include <string.h>
using namespace std;
int main(){
  char s1[25],s2[25];
  cin >> s1;
  cin >> s2;

  char* c = strstr(s2, s1);
  char* d = strstr(s1, s2);

  bool found = false;

  if(c != NULL){
    cout << s1 << " is substring of " << s2 << endl;
    found = true;
  }else if(d != NULL){
    cout << s2 << " is substring of " << s1 << endl;
    found = true;
  }

  if(!found) cout << "No substring" << endl;

}
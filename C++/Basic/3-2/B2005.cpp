#include<iostream>
#include<format>
using namespace std;
int main(){
  char a;
  cin >> a;
  cout << format("  {:c}  ",a)<< endl;
  cout << format(" {0:}{0:}{0:} ",a) << endl;
  cout << format("{0:}{0:}{0:}{0:}{0:}",a) << endl;
}
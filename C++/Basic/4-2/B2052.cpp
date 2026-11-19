#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int a, b;
  char c;
  cin >> a >> b >> c;
  //  if(b==0){
  //    cout<<"Divided by zero!"<<endl;
  //  }else if(c!='+'&&c!='-'&&c!='*'&&c!='/'){
  //    cout<<"Invalid operator!"<<endl;
  //  }else if(c=='+'){
  //    cout<<a+b<<endl;
  //  }else if(c=='-'){
  //    cout<<a-b<<endl;
  //  }else if(c=='*'){
  //    cout<<a*b<<endl;
  //  }else if(c=='/'){
  //    cout<<floor(a/b)<<endl;
  //  }

  switch (c)
  {
  case '+':
    cout << a + b << endl;
    break;
  case '-':
    cout << a - b << endl;
    break;
  case '*':
    cout << a * b << endl;
    break;
  case '/':
    if (b == 0)
      cout << "Divided by zero!" << endl;
    else
      cout << a / b << endl;
    break;
  default:
    cout << "Invalid operator!" << endl;
  }
}
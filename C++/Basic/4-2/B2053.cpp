#include<iostream>
#include<cmath>
using namespace std;
int main(){
  double a,b,c;
  cin>>a>>b>>c;
  cout.precision(5);
  cout<<fixed;
  if(pow(b,2)-4*a*c>0){
    double x1=(-b+sqrt(pow(b,2)-4*a*c))/2/a;
    double x2=(-b-sqrt(pow(b,2)-4*a*c))/2/a;
    if(x1<x2){
      cout<<"x1="<<x1<<";"<<"x2="<<x2<<endl;
    }else{
      cout<<"x1="<<x2<<";"<<"x2="<<x1<<endl;
    }
  }else if((pow(b,2)-4*a*c==0)){
    double x1=(-b)/2/a;
    cout<<"x1=x2="<<x1<<endl;
  }else{
    cout<<"No answer!"<<endl;
  }
}
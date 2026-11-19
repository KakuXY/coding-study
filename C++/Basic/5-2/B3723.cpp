#include <iostream>
#include <vector>
using namespace std;
int main(){

  int n;
  cin >> n;//初始硬币数量

  vector<long long> value(n);
  for(auto& v:value) cin >> v;//输入硬币的面额

  for(int i = 0; i < n - 1; i++){
    for(int j = 0;j < n - i - 1; j++){
      if(value[j] < value[j + 1]) 
       swap(value[j], value[j + 1]);
    }
  }//冒泡排序从大到小排列

  long long John_v = value.back();//初始化为最小的硬币
  value.pop_back();
  long long Bessie_v = value.back();//初始化为第二小的硬币
  value.pop_back();

  while(!value.empty()){//数组为空时结束

    bool found = false;//判断条件

    for(size_t i = 0; i < value.size(); i++){
    if(John_v >= value[i]){//剩余的硬币不超过钱包中硬币的总额时，选择最大
      John_v += value[i]; 
      value.erase(value.begin() + i);
      found = true;//改变判断条件
      break;
    }
  }
  //剩余的硬币超过钱包中硬币的总额时，选择最小
    if(!found){//如果判断条件!false(!0 = 1)则进入里面取硬币最小值                              
      John_v += value.back(); 
      value.pop_back();
    }

    if(value.empty()) break;//硬币个数为奇数时跳出
    found = false;

    for(size_t i = 0; i < value.size(); i++){
      if(Bessie_v >= value[i]){
        Bessie_v += value[i]; 
        value.erase(value.begin() + i);
        found = true;
        break;
      }
    }
      if(!found){
        Bessie_v += value.back(); 
        value.pop_back();
      }
    }

    cout << John_v << ' ' << Bessie_v << endl;
}

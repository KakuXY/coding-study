#include <iostream>
#include <vector>
using namespace  std;
int main(){
  
int n,m,r;
cin >> n >> m >> r;

vector<int> f1(n);
vector<int> p1(n);
vector<int> f2(n);
vector<int> p2(n);
for(auto& F1: f1) cin >> F1;
for(auto& P1: p1) cin >> P1;
for(auto& F2: f2) cin >> F2;
for(auto& P2: p2) cin >> P2;

vector<int> fusu(n);
for(auto& fusu_poker: fusu) cin >> fusu_poker;

for (int i = 0; i < n - 1; i++) {
  for (int j = 0; j < n - i - 1; j++) {
      if (p2[j] > p2[j + 1]) {
          swap(p2[j], p2[j + 1]);
          swap(f2[j], f2[j + 1]);
      }
  }
}

int a = n;
for(auto& fusu_poker: fusu){
  for(int j = 0; j < a; j++){
    if(f1[fusu_poker - 1] == f2[j]){
      if(p1[fusu_poker - 1] < p2[j]){
        n--;
        f2.erase(f2.begin() + j);
        p2.erase(p2.begin() + j);
        a--;
        break;
      }
    }
  }
}
cout << n << endl;
}



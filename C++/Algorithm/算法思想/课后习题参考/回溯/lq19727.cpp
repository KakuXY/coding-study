/**
 * 24 省赛 Java B组 (7/8)
 * LIST 游戏
 * https://www.lanqiao.cn/problems/19727/learning/
 * https://www.luogu.com.cn/problem/P11047  (数据加强版)
 */

 #include <bits/stdc++.h>
 #ifndef DEBUG
 #define debug
 #endif
 using namespace std;
 
 int main() {
   cin.tie(0)->sync_with_stdio(0);
   vector<set<vector<string>>> patterns = {
     {
       {
         "111",
         "100"
       },
     },
     {
       {
         "1111",
       }
     },
     {
       {
         "111",
         "010",
       }
     },
     {
       {
         "011",
         "110"
       }
     }
   };
   for (auto &pattern : patterns) {
     auto type = *pattern.begin();
     for (int _ = 0; _ < 4; _ ++) {
       int n = type.size(), m = type[0].size();
       auto new_type = vector(m, string(n, '0'));
       for (int i = 0; i < n; i ++) {
         for (int j = 0; j < m; j ++) {
           new_type[j][n - i - 1] = type[i][j];
         }
       }
       type = new_type;
       pattern.insert(new_type);
     }
   }
   debug(patterns);
   int T;
   cin >> T;
   while (T--) {
     int n;
     cin >> n;
     auto board = vector(n, vector(n, 0));
     for (auto &row : board) {
       for (auto &x : row) cin >> x;
     }
     auto can = [&](int x, int y, const vector<string> &type) {
       int xl = type.size(), yl = type[0].size();
       if (x + xl > n || y + yl > n) return false;
       for (int i = 0; i < xl; i ++) {
         for (int j = 0; j < yl; j ++) {
           if (type[i][j] == '1' && board[i+x][j+y] == 0) return false;
         }
       }
       return true;
     };
     
     auto update = [&](int x, int y, const vector<string> &type) {
       int xl = type.size(), yl = type[0].size();
       for (int i = 0; i < xl; i ++) {
         for (int j = 0; j < yl; j ++) {
           if (type[i][j] == '1') board[i+x][j+y] = 0;
         }
       }
     };
     
     auto rollback = [&](int x, int y, const vector<string> &type) {
       int xl = type.size(), yl = type[0].size();
       for (int i = 0; i < xl; i ++) {
         for (int j = 0; j < yl; j ++) {
           if (type[i][j] == '1') board[i+x][j+y] = 1;
         }
       }
     };
     auto traceback = [&](auto &self, int pos, int used) {
       // debug(board);
       if (used == 15) return true;
       if (pos == n * n) return false;
       int x = pos / n, y = pos % n;
       for (int i = 0; i < 4; i ++) {
         if (used & (1 << i)) continue;
         for (auto &type : patterns[i]) {
           if (can(x, y, type)) {
             update(x, y, type);
             if (self(self, pos + 1, used | (1 << i))) return true;
             rollback(x, y, type);
           }
         }
       }
       return self(self, pos + 1, used);
     };
     cout << (traceback(traceback, 0, 0) ? "Yes" : "No") << endl;
   }
 }
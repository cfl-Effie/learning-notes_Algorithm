/*
通配符是一类键盘字符,当我们不知道真正字符或者不想键入完整名字时,常常使用通配符代替一个或多个真正字符。通配符有问号(?)和星号(*)等,其中,“?”可以代替-
个字符,而“*”可以代替零个或多个字符。
你的任务是,给出一个带有通配符的字符串和一个不带通配符的字符串,判断他们是否能够匹配。
例如,1?456可以匹配12456、13456、1a456,但是却不能够匹配23456、1aa456;2*77?8可以匹配24457798、237708、27798。
输入格式
  输入有两行,每行为一个不超过20个字符的字符串,第一行带通配符,第二行不带通配符。
输出格式
  如果两者可以匹配,就输出“matched",否则输出"not matched"。
eg:
  in:
    1*456?
    11111114567
  out:matched
*/
#include <iostream>
#include <cstring>
using namespace std;
char x[22], y[22];
int dp[50][50] = {0};
int main() {
   cin >> (x + 1) >> (y + 1);
   int xlen = strlen(x + 1), ylen = strlen(y + 1);
   dp[0][0] = 1;
   for (int i = 1; i <= xlen; i++) {
       if (x[i] == '*' && dp[i-1][0] == 1)
           dp[i][0] = 1;
       else
           dp[i][0] = 0;
   }
   for (int i = 1; i <= xlen; i++) {
       for (int j = 1; j <= ylen; j++) {
           if (x[i] == y[j] || x[i] == '?')
               dp[i][j] = dp[i-1][j-1];
           if (x[i] == '*')
               dp[i][j] = dp[i-1][j] || dp[i][j-1];
       }
   }
   if (dp[xlen][ylen] == 1)
       cout << "matched" << endl;
   else
       cout << "not matched" << endl;
   return 0;
}

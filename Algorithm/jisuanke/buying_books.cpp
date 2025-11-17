/*
小蒜手里有n元钱全部用来买书，书的价格为10元，20元，50元，100元。
问小蒜有多少种买书方案？（每种书可购买多本）
输入格式
  一个整数n，代表总共钱数。（1<=n<=1000）
输出格式
  一个整数，代表选择方案种数。
eg:
  in:20
  out:2
  in:15
  out:0
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 10 != 0 || n < 10) {
        cout << 0;
        return 0;
    }
    
    int amount = n / 10;
    vector<int> coins = {1, 2, 5, 10}; // 对应10元、20元、50元、100元（除以10后）
    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;
    
    for (int c : coins) {
        for (int i = c; i <= amount; i++) {
            dp[i] += dp[i - c];
        }
    }
    cout << dp[amount];
    return 0;
}

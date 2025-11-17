/*
给定一个1~N的排列A1,A2,…AN,每次操作小蒜可以选择一个数,把它放到数组的最左边。
请计算小蒜最少进行几次操作就能使得新数组是递增排列的。
输入格式
  第一行包含一个整数N。
  第二行包含N个两两不同整数A1,A2,…AN。(1≤Ai≤N)。
  1≤N≤100000。
输出格式
  一个整数代表答案
eg:
  in:
    5
    2 3 1 4 5
  out:
    1
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int target = n;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == target) {
            target--;
        }
    }
    cout << target << endl;
    return 0;
}

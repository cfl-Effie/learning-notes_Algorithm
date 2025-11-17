/*
进行一次独木舟的旅行活动,独木舟可以在港口租到,并且之间没有区别。一条独木舟最多只能乘坐两个人,且乘客的总重量不能超过独木舟的最大承载量。我们要尽量减少
这次活动中的花销,所以要找出可以安置所有旅客的最少的独木舟条数。现在请写一个程序,读入独木舟的最大承载量、旅客数目和每位旅客的重量。根据给出的规则,计算
要安置所有旅客必须的最少的独木舟条数,并输出结果。
输入格式
  第一行输入s(1≤s≤10),表示测试数据的组数;
  每组数据的第一行包括两个整数w,n,80≤w≤200,1≤n≤300,w 为一条独木舟的最大承载量,n为人数;
  接下来的一组数据为每个人的重量(不能大于船的承载量);
输出格式
  每组人数所需要的最少独木舟的条数。
eg:
  in:
    3
    85 6
    5 84 85 80 84 83
    90 3
    90 45 60
    100 5
    50 50 90 40 60
  out:
    5
    3
    3
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int s;
    cin >> s;
    while (s--) {
        int w, n;
        cin >> w >> n;
        int weights[n];
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }
        sort(weights, weights + n);
        int left = 0, right = n - 1;
        int count = 0;
        while (left <= right) {
            if (weights[left] + weights[right] <= w) {
                left++;
            }
            right--;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}

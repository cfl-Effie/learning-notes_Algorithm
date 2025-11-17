/*
小蒜想将正整数n拆分为若干个互不相等的自然数之和,问如何拆分可以使得它们的乘积最大?
输入格式
  一个正整数n。n≤10000。
输出格式
  一行,包含若干个互不相等的自然数 -- 乘积最大的一种拆分方案。
  这些自然数需从小到大输出,两个自然数之间用单个空格隔开。
eg:
  in:15
  out:2 3 4 6
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    vector<int> arr;
    int cur = 2;
    while (n >= cur) {
        arr.push_back(cur);
        n -= cur;
        cur++;
    }
    
    int k = arr.size();
    if (n > 0) {
        int t = n / k;
        int r0 = n % k;
        
        for (int i = 0; i < k; i++) {
            arr[i] += t;
        }
        
        for (int i = 0; i < r0; i++) {
            arr[k - 1 - i] += 1;
        }
    }
    
    for (int i = 0; i < k; i++) {
        cout << arr[i];
        if (i < k - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}

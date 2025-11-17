/*
某班有n个同学,每个同学有一个外向程度ai。由于要进行某个活动,需要把他们分成若干个小组,每个小组的人数至少为m人。不同外向程度的人在一个小组会产生不开
心值,定义一个小组的不开心值为组内成员外向程度最大值和最小值的差,一个班级的不开心值为所有小组不开心值的最大值。
那么问题来了,如何分组使得班级的不开心值最小,请你求出这个最小的班级不开心值。
输入格式
  第一行两个整数n,m,分别表示人数和每个小组最少的人数要求。
  第二行n个整数ai,表示每个同学的外向程度。
输出格式
  一个整数,表示最小的班级不开心值。
数据范围
  对于30%的数据:1≤m≤n≤20,1≤ai≤100。
  对于60%的数据:1≤m≤n≤1000,1≤ai≤1000。
  对于100%的数据:1≤m≤n≤5·10^5,1≤ai≤10^9。
eg:
  in: 第一个样例,只要每个人各自一个组,不开心值就都是0。
    5 1
    2 4 6 8 10
  out:0
  in:第二个样例,最佳的分组情况为:9,11一个组,6,3,5一个组,两个组的不开心值分别为2和3,那么班级的不开心值为3。
    5 2
    9 11 6 3 5 
  out:3
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    int low = 0, high = a[n-1] - a[0];
    int ans = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        vector<bool> dp(n+1, false);
        vector<int> pre(n+1, -1);
        dp[0] = true;
        pre[0] = 0;
        int left = 0;
        
        for (int i = 1; i <= n; i++) {
            while (left < i && a[i-1] - a[left] > mid) {
                left++;
            }
            int min_index = left;
            int max_index = i - m;
            if (max_index < 0) {
                dp[i] = false;
            } else {
                if (min_index <= max_index) {
                    if (pre[max_index] >= min_index) {
                        dp[i] = true;
                    } else {
                        dp[i] = false;
                    }
                } else {
                    dp[i] = false;
                }
            }
            if (dp[i]) {
                pre[i] = i;
            } else {
                pre[i] = pre[i-1];
            }
        }
        
        if (dp[n]) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}

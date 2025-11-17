/*
在一个旧式的火车站旁边有一座桥,其桥面可以绕河中心的桥墩水平旋转。一个车站的职工发现桥的长度最多能容纳两节车厢,如果将桥旋转180度,则可以把相邻两节车
厢的位置交换,用这种方法可以重新排列车厢的顺序。于是他就负责用这座桥将进站的车厢按车厢号从小到大排列。他退休后,火车站决定将这一工作自动化,其中一项重要
的工作是编一个程序,输入初始的车厢顺序,计算最少用多少步就能将车厢排序。
输入格式
  第一行是车厢总数N(1≤N≤10000)。
  第二行是N个不同的数表示初始的车厢顺序。
输出格式
  一个整数,最少的旋转次数。
eg:
  in:
    5
    3 5 1 4 2
  out:6
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int steps = 0;
    vector<int> sortedArr = arr;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (sortedArr[j] > sortedArr[j+1]) {
                swap(sortedArr[j], sortedArr[j+1]);
                steps++;
            }
        }
    }
    
    cout << steps << endl;
    return 0;
}

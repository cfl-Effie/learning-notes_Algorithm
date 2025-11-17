/*
蒜头君发完了赈灾物资,接下来还得去统计受灾的影响程度,真是辛苦啊。假定蒜国为NxN个区域,每个区域的水位(深度)已知,我们划定一块2×2的区域为受灾最严
重区域。
输入格式
  第一行输入一个正整数N(2≤N≤10)表示区域边宽度。
  接下来有NxN个整数,表示各个区域的水位(深度)。
输出格式
  输出共一行,一个实数,表示受灾最严重区域的平均水位(深度),保证数据范围都在231内,并且保留两位小数。
eg:
  in:
    3
    1 2 3
    2 3 4
    3 4 5
  out:4.00
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<vector<int>>waterLevel(N,vector<int>(N));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>waterLevel[i][j];
        }
    }
    
    double maxAvg=0;
    for (int i=0;i<N-1;i++)
    {
        for (int j=0;j<N-1;j++)
        {
            double avg=waterLevel[i][j]/4.0+waterLevel[i][j+1]/4.0+waterLevel[i+1][j]/4.0+waterLevel[i+1][j+1]/4.0;
            if(avg>maxAvg)
                maxAvg=avg;
        }
    }
    cout<<fixed<<setprecision(2)<<maxAvg<<endl;
    return 0;
}

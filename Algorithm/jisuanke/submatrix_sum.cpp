/*
给出一个n行m列的矩阵,矩阵的每个位置有一个非负整数a[i][j],有q次询问,每次询问求一个左上角为(a,b),右下角为(c,d)的子矩阵的所有数之和。
输入格式
  第一行两个整数n,m,表示矩阵的行和列的大小。
  接下来n行每行m个整数,为矩阵内容。
  接下来一行为一个整数q,表示询问次数。
  接下来q行每行4个整数a,b,c,d,含义见题面。
输出格式
  共q行,第i行为第i个询问的答案。
数据范围
  n×m≤100,000, a[i][j]≤1000,q≤100,000,1≤a≤c≤n,1≤b≤d≤m。
eg:
  in:
    3 5
    1 2 3 4 5
    3 2 1 4 7
    2 4 2 1 2
    3
    1 1 3 5
    2 2 3 3
    1 1 3 3
  out:
    43
    9
    20
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int i,j;
    vector<vector<int>>matrix(n+1,vector<int>(m+1));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>prefix(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            prefix[i][j]=matrix[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    int q;
    cin>>q;
    int a,b,c,d;
    for(i=0;i<q;i++)
    {
        cin>>a>>b>>c>>d;
        cout<<prefix[c][d]-prefix[c][b-1]-prefix[a-1][d]+prefix[a-1][b-1]<<endl;
    }
    return 0;
}

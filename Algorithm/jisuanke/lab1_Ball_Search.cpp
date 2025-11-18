/*
在蒜国里流行着一种游戏。
游戏规则为：在一堆球中，每个球上都有一个整数编号 i(0≤i≤10^9)，编号可重复，现在说一个随机整数 k(0≤k≤10^9+100)，判断编号为 k 的球是否在这堆球中（存在为 "YES"），否则为 "NO"）。先给出者为胜。现在有一个人想玩玩这个游戏，但他又很懒。他希望你能帮助他取得胜利。
本题输入输出量较大，请使用scanf/printf。
输入格式
  第一行有两个整数m,n(1<=m<=10^6,1<=n<=10^6)，两数之间以一个空格分隔；m表示这堆球里有 m 个球，n 表示这个游戏进行 n 次。
  第二行输入 m 个整数，分别表示这 m 个球的编号 i，相邻两数之间以一个空格分隔。
  第三行输入 n 个整数，分别表示每次游戏中的随机整数 k，相邻两数之间以一个空格分隔。
输出格式
  输出 "YES" 或 "NO" 。
eg:
  in:
    6 4
    23 34 46 768 343 343
    2 4 23 343
  out:
    NO
    NO
    YES
    YES
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    freopen("ball.in","r",stdin);
    freopen("ball.out","w",stdout);
    int m,n;
    scanf("%d %d",&m,&n);
    int i,j;
    vector<bool>number(1000000002,0);
    for(i=0;i<m;i++)
    {
        scanf("%d",&j);
        if(!number[j])
            number[j]=1;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        if(number[j])
            printf("YES\n");
        else
            printf("NO\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

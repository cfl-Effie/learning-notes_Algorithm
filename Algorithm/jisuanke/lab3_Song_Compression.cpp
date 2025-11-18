/*
蒜头君的电脑里面有一些歌。现在他需要把这些歌装进一个硬盘里面。
硬盘大小有限,由于蒜头君下载的都是无损版本,每首歌的占用空间比较大,硬盘不一定装得下,然后他需要压缩其中的一部分歌曲这样他才能将尽可能多的歌曲装进他的硬盘里。
但是他想尽量压缩的歌曲数量尽量少,他不知道该怎么做,就来找你帮忙了。
输入格式
  输入的第一行包含两个整数n和m(1≤n≤105,1≤m≤109),分别表示蒜头君电脑里面歌曲的个数和他的硬盘大小(单位:字节)。
  然后输入n行,每一行两个整数ai和bi(1≤bi<ai≤109),分别表示第i首歌曲原本的大小和被压缩后的大小(单位:字节)。
输出格式
  输出只有一个整数,蒜头君至少需要压缩的歌曲的数量。
  如果所有的歌曲都压缩的硬盘还是装不下,输出-1。
eg:
  in:
    4 21
    10 8
    7 4
    3 1
    5 4
  out:2
  in:
    4 16
    10 8
    7 4
    3 1
    5 4
  out:-1
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    int i,a,b,c,f=0;
    long long int all1=0,all2=0,d,e=0;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        c=a-b;
        arr[i]=c;
        all1+=a;
        all2+=b;
    }
    if(all2>m)
    {
        cout<<-1;
        return 0;
    }
    else if(all1==m)
    {
        cout<<0;
        return 0;
    }
    else
    {
        // 将节省空间按从大到小排序
        sort(arr.begin(), arr.end());
        d=all1-m;
        for(i=n-1;i>=0&&e<d;i--)
        {
            e+=arr[i];
            f++;
        }
        cout<<f;
        return 0;
    }
}

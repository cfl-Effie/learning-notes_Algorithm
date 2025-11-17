/*
如果一个二进制数包含连续的两个1,我们就称这个二进制数是非法的。
小Hi想知道在所有n位二进制数(一共有2^n个)中,非法二进制数有多少个。
例如对于n=3,有011,110,111三个非法二进制数。
由于结果可能很大,你只需要输出模10^9+7的余数。
输入格式
  一个整数n(1≤n≤100)。
输出格式
  n位非法二进制数的数目模109+7的余数。
eg:
  in:3
  out:3
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m=0;
    int a1=3,a2=5,temp;
    if(n==0||n==1)
        cout<<0;
    else if(n==2)
        cout<<1;
    else if(n==3)
        cout<<3;
    else
    {
        for(int i=4;i<=n;i++)
        {
            temp=a2;
            a2=(a1+a2)%1000000007;
            a1=temp;
        }
        m=a2;
        long long pow2n=1;
        for(int i=0;i<n;i++)
            pow2n=(pow2n*2)%1000000007;
        cout<<(pow2n-m+1000000007)%1000000007;
    }
    return 0;
}

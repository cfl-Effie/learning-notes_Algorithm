/*
给定A、B、C三根足够长的细柱,在A柱上放有2n个中间有孔的圆盘,共有n个不同的尺寸,每个尺寸都有两个相同的圆盘,注意这两个圆盘是不加区分的(下图为
n=3的情形)。现要将这些圆盘移到C柱上,在移动过程中可放在B柱上暂存。要求:
  (1)每次只能移动一个圆盘;
  (2)A、B、C三根细柱上的圆盘都要保持上小下大的顺序;
任务:
  设An为2n个圆盘完成上述任务所需的最少移动次数,对于输入的n,输出An。
输入格式:
  输入一个正整数n,表示在A柱上放有2n个圆盘。
输出格式:
  输出一个正整数,为完成上述任务所需的最少移动次数An。
数据范围:
  对于50%的数据，1<=n<=25;
  对于100%的数据，1<=n<=200;
  设法建立An与An-1的递推关系式。
eg:
  in:1
  out:2
  in:2
  out:6
*/
#include<iostream>
#include<cstring>
using namespace std;

const int MAX_LEN=1000;

int main()
{
    int n;
    cin>>n;
    int a[MAX_LEN]={0};
    a[0]=1;
    int len=1;
    int k=n+1;
    for(int i=0;i<k;i++)
    {
        int carry=0;
        for(int j=0;j<len;j++)
        {
            int temp=a[j]*2+carry;
            a[j]=temp%10;
            carry=temp/10;
        }
        if(carry)
        {
            a[len]=carry;
            len++;
        }
    }
    a[0]-=2;
    for(int i=len-1;i>=0;i--)
    {
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}

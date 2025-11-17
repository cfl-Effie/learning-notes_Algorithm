/*
现在,我想让你猜一个数字x(1000≤x≤9999),它满足以下要求:
  (1) x%a=0;
  (2)(x+1)%b=0;
  (3)(x+2)%c=0;
  其中1≤a,b,c≤100。
给你a,b,c的值,你能告诉我x是多少吗?
输入格式
  输入的第一行为t,表示测试样例的个数。接下来的t行每行包括a,b,c三个整数。
输出格式
  对于每一个测试样例,输出所求的x(最小的),如果x不存在,则输出 Impossible。
eg:
  in:
    2
    44 38 49
    25 56 3
  out:
    Impossible
    2575
*/
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int x=-1;
        for(int i=(1000+a-1)/a*a;i<=9999;i+=a)
        {
            if((i+1)%b==0&&(i+2)%c==0)
            {
                x=i;
                break;
            }
        }
        if(x==-1)
        {
            cout<<"Impossible"<<endl;
        }else
        {
            cout<<x<<endl;
        }
    }
    return 0;
}

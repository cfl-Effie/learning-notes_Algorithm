/*
在一个非降序列中,查找与蒜头君的给定值最接近的元素。
输入格式
  第一行包含一个整数n,为非降序列长度。1≤n≤100000。
  第二行包含n个整数,为非降序列各元素。所有元素的大小均在0~1,000,000,000之间。
  第三行包含一个整数m,为要询问的给定值个数。1≤m≤10000。
  接下来m行,每行一个整数,为要询问最接近元素的给定值。所有给定值的大小均在0~1,000,000,000之间。
输出格式
  m行,每行一个整数,为最接近相应给定值的元素值,保持输入顺序。若有多个值满足条件,输出最小的一个。
eg:
  int:
    3
    2 5 8
    2
    10
    5
  out:
    8
    5
*/
#include<iostream>
#include<vector>
using namespace std;

int searchNumber(int n,const vector<int>& number,int a)
{
    int left=0;
    int right=n-1;
    while(left<right)
    {
        // 防止直接相加可能导致的整数溢出
        int middle=left+(right-left)/2;
        if(number[middle]>=a)
            right=middle;
        else
            left=middle+1;
    }
    if((a-number[left-1])<=(number[left]-a))
        return number[left-1];
    else
        return number[left];
}
int main()
{
    int n,m;
    int i;
    cin>>n;
    vector<int>number(n);
    for(i=0;i<n;i++)
    {
        cin>>number[i];
    }
    cin>>m;
    int target;
    for(i=0;i<m;i++)
    {
        cin>>target;
        if(target<=number[0])
            cout<<number[0]<<endl;
        else if(target>=number[n-1])
            cout<<number[n-1]<<endl;
        else
            cout<<searchNumber(n,number,target)<<endl;
    }
}

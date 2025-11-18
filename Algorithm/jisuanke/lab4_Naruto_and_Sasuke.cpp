/*
佐助被大蛇丸诱骗走了，鸣人在多少时间内能追上他呢？
已知一张地图(以二维矩阵的形式表示)以及佐助和鸣人的位置。
地图上的每个位置都可以走到,只不过有些位置上有大蛇丸的手下,需要先打败大蛇丸的手下才能到这些位置。
鸣人有一定数量的查克拉,每一个单位的查克拉可以打败一个大蛇丸的手下。假设鸣人可以往上下左右四个方向移动,每移动一个距离需要花费1个单位时间,打败大蛇丸的手下不需要时间。
如果鸣人查克拉消耗完了,则只可以走到没有大蛇丸手下的位置,不可以再移动到有大蛇丸手下的位置。佐助在此期间不移动,大蛇丸的手下也不移动。请问,鸣人要追上佐助最少需要花费多少时间?
输入格式
  输入的第一行包含三个整数:M,N,T。代表M行N列的地图和鸣人初始的查克拉数量T。0<M,N<200,0≤T<10
  后面是M行N列的地图,其中@代表鸣人,+代表佐助。*代表通路,#代表大蛇丸的手下。
输出格式
  输出包含一个整数R,代表鸣人追上佐助最少需要花费的时间。如果鸣人无法追上佐助,则输出-1。
eg:
  in:
    4 4 1
    #@##
    **##
    ###+
    ****
  out:6
  in:
    4 4 2
    #@##
    **##
    ###+
    ****
  out:4
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

struct Now
{
    int x,y,chakela,step;
    Now(int _x, int _y, int _c, int _s):x(_x),y(_y),chakela(_c),step(_s){}
};

int main()
{
    freopen("naruto.in","r",stdin);
    freopen("naruto.out","w",stdout);
    int m,n,t;
    cin>>m>>n>>t;
    vector<vector<char>>map(m,vector<char>(n));
    int mingrenx,mingreny,zuozhux,zuozhuy;
    for(int i=0;i<m;i++) 
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='@')
            {
                mingrenx=j;
                mingreny=i;
            }
            if(map[i][j]=='+')
            {
                zuozhux=j;
                zuozhuy=i;
            }
        }
    }
    
    vector<vector<vector<bool>>>road(m,vector<vector<bool>>(n,vector<bool>(t+1,false)));
    queue<Now>q;
    q.push(Now(mingrenx,mingreny,t,0));
    road[mingreny][mingrenx][t]=true;
    int wayx[4]={0,1,0,-1};
    int wayy[4]={1,0,-1,0};
    while(!q.empty())
    {
        Now current=q.front();
        q.pop();
        if(current.x==zuozhux&&current.y==zuozhuy)
        {
            cout<<current.step<<endl;
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        for(int i=0;i<4;i++)
        {
            int nowx=current.x+wayx[i];
            int nowy=current.y+wayy[i];
            if(nowx<0||nowx>=n||nowy<0||nowy>=m)
                continue;
            if(map[nowy][nowx]=='*'||map[nowy][nowx] =='+')
            {
                if(!road[nowy][nowx][current.chakela])
                {
                    road[nowy][nowx][current.chakela]=true;
                    q.push(Now(nowx,nowy,current.chakela,current.step+1));
                }
            }
            else if(map[nowy][nowx]=='#'&&current.chakela>0)
            {
                if(!road[nowy][nowx][current.chakela-1])
                {
                    road[nowy][nowx][current.chakela-1]=true;
                    q.push(Now(nowx,nowy,current.chakela-1,current.step+1));
                }
            }
        }
    }
    cout<<-1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

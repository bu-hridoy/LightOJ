/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1257
#include<bits/stdc++.h>
using namespace std;
int visited[30005],Dis[30005],Dis2[30005];

int BFS(int s,vector<pair<int,int> >G[30005])
{
    int MX=0,start;
    queue<int>Q;
    Q.push(s);
    visited[s]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        int sz=G[u].size();

        for(int i=0; i<sz; i++)
        {
            int v=G[u][i].first;

            if(visited[v]==0)
            {
                visited[v]=1;
                Dis[v]=Dis[u]+G[u][i].second;

                if(Dis[v]>MX)
                {
                    MX=Dis[v];
                    start=v;
                }
                Q.push(v);
            }
        }
    }
    return start;

}
int main()
{
    int T,t=0;
    scanf("%d",&T);
    while(T--)
    {
        vector<pair<int,int> >G[30005];
        int N;
        scanf("%d",&N);

        for(int i=1; i<N; i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            G[x].push_back(make_pair(y,w));
            G[y].push_back(make_pair(x,w));
            visited[i]=0;
            Dis[i]=0;
            Dis2[i]=0;
        }
        visited[0]=0;
        Dis[0]=0;
        Dis2[0]=0;

        int last=BFS(0,G);
        memset(visited,0,sizeof(visited));
        memset(Dis,0,sizeof(Dis));


        int Sec_last=BFS(last,G);

         memset(visited,0,sizeof(visited));
        for(int i=0; i<N; i++)
        {
            Dis2[i]=Dis[i];
            Dis[i]=0;
        }
        int ans=BFS(Sec_last,G);
        printf("Case %d:\n",++t);
        for(int i=0; i<N; i++)
            printf("%d\n",max(Dis[i],Dis2[i]));
    }
}

/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1074

#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int> , long long int > >V;
vector<int>VV[202];
int cost[202],dis[202],visited[202];
int N,Mx=1000000;

void bel()
{
    int sz=V.size();
    for(int i=0; i<N; i++)
     {
         for(int j=0; j<sz; j++)
         {
             int u=V[j].first.first;
             int v=V[j].first.second;
             int w=V[j].second;

             if(dis[u]+w<dis[v] && visited[u]==1 && visited[v]==1)
                dis[v]=dis[u]+w;
         }
     }

}
void dfs(int u)
{
    visited[u]=1;
    int sz=VV[u].size();

    for(int i=0; i<sz; i++)
    {
        int v=VV[u][i];
        if(visited[v]==0)
            dfs(v);
    }
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        for(int i=0; i<=201; i++)
        {
            cost[i]=0;
            dis[i]=Mx;
            visited[i]=0;
            VV[i].clear();
        }
        V.clear();
        dis[1]=0;


        scanf("%d",&N);
        for(int i=1; i<=N; i++)
            scanf("%d",&cost[i]);

        int E;
        scanf("%d",&E);
        for(int i=0; i<E; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            VV[x].push_back(y);
            long long int w=cost[y]-cost[x];
            long long int sum=w*w*w;
            V.push_back(make_pair(make_pair(x,y),sum));
        }
        dfs(1);
        bel();

        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++t);
        for(int i=0; i<q; i++)
        {
            int node;
            scanf("%d",&node);
            int ans=dis[node];
            if(ans<3 || ans>=Mx)
                printf("?\n");
            else
                printf("%d\n",ans);
        }
    }
}

/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1108

#include<bits/stdc++.h>
using namespace std;
vector<int>Rev[1005];
vector<int>ans;
vector<pair<pair<int,int> ,int> >V;

int visited[1005],dis[1005],N;

void dfs(int u)
{
    visited[u]=1;
    ans.push_back(u);
    int sz=Rev[u].size();

    for(int i=0; i<sz; i++)
        {
            int v=Rev[u][i];
            if(visited[v]==0)
                dfs(v);
        }
}

int belmanford()
{
    int sz=V.size(),cheak=0;
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<sz; j++)
        {
            int u=V[j].first.first;
            int v=V[j].first.second;
            int w=V[j].second;

            if(dis[u]+w<dis[v])
                dis[v]=dis[u]+w;
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<sz; j++)
        {
            int u=V[j].first.first;
            int v=V[j].first.second;
            int w=V[j].second;

            if(dis[u]+w<dis[v])
                {
                dis[v]=dis[u]+w;
                    cheak=1;
                    if(visited[u]==0)
                        dfs(u);

                }
        }
    }

    return cheak;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        int E;
        scanf("%d%d",&N,&E);

        for(int i=0; i<=1000; i++)
        {
            dis[i]=0;//INT_MAX;
            Rev[i].clear();
            visited[i]=0;

        }
        V.clear();
        ans.clear();

        for(int i=0; i<E; i++)
        {
            int X,Y,W;
            scanf("%d%d%d",&X,&Y,&W);
            V.push_back(make_pair(make_pair(Y,X),W));
            Rev[Y].push_back(X);
        }

        if(belmanford()==0)
            printf("Case %d: impossible\n",++t);
        else
        {
            sort(ans.begin(),ans.end());
            int sz=ans.size();

            printf("Case %d:",++t);
            for(int i=0;i<sz;i++)
                printf(" %d",ans[i]);
                    printf("\n");
        }
    }
}

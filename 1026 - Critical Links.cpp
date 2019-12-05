/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1026

#include<bits/stdc++.h>
using namespace std;

int par[10005];
int visited[10005],low[10005],dis[10005],AP[10005];
vector<int>V[10005];
vector<pair<int,int> >ans;
int Time;

bool cmp(pair<int,int>A, pair<int,int>B)
{
    if(A.first==B.first)
        return A.second<B.second;
    return A.first<B.first;
}

void ap(int u)
{
    int child=0;
    visited[u]=1;
    low[u]=dis[u]=++Time;
    int sz=V[u].size();

    for(int i=0; i<sz; i++)
    {
        int v=V[u][i];

        if(visited[v]==0)
        {
            child++;
            par[v]=u;
            ap(v);

            low[u]=min(low[u],low[v]);

            if(dis[u]<low[v])
                ans.push_back(make_pair(min(u,v),max(u,v)));
        }
        else if(par[u]!=v)
                low[u]=min(low[u],dis[v]);

    }
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        for(int i=0; i<10002; i++)
        {
            par[i]=-1;
            visited[i]=0;
            low[i]=0;
            dis[i]=0;
            V[i].clear();
            AP[i]=0;
        }
        Time=0;
        ans.clear();

        int node;
        scanf("%d",&node);

        for(int i=0; i<node; i++)
        {
            int x,q;
            scanf("%d (%d)",&x,&q);

            for(int i=0; i<q; i++)
            {
                int y;
                scanf("%d",&y);
                V[x].push_back(y);
            }
        }

        for(int i=0; i<node; i++)
        {
            if(visited[i]==0)
                ap(i);
        }
        int sz=ans.size();
        sort(ans.begin(),ans.end(),cmp);

        printf("Case %d:\n",++t);
        printf("%d critical links\n",sz);
        for(int i=0; i<sz; i++)
        {
            int x=ans[i].first;
            int y=ans[i].second;
            printf("%d - %d\n",x,y);
        }
    }
}

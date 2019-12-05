/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1174

#include<bits/stdc++.h>
using namespace std;
vector<int>V[105];
int visited[105];
void BFS(int s,int level[])
{
    level[s]=0;
    visited[s]=1;
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        int sz=V[u].size();

        for(int i=0; i<sz; i++)
        {
            int v=V[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }

}
int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        int node,edge,dis[105],dim[105];

        scanf("%d%d",&node,&edge);

        for(int i=0; i<=node+1; i++)
        {
            dis[i]=0;
            dim[i]=0;
            V[i].clear();
            visited[i]=0;
        }

        for(int i=0; i<edge; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            V[x].push_back(y);
            V[y].push_back(x);
        }

        int s,d;
        scanf("%d%d",&s,&d);

        BFS(s,dis);
        memset(visited,0,sizeof(visited));
        BFS(d,dim);

        int Mx=0;
        for(int i=0; i<node; i++)
        {
           // cout<<dim[i]<<" "<<dis[i]<<endl;
            Mx=max(Mx,dim[i]+dis[i]);
        }
        printf("Case %d: %d\n",++t,Mx);

    }
}

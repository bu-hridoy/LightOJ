/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1271

#include<bits/stdc++.h>
using namespace std;

vector<int>V[50005];
int visited[50005];
int Arr[50005],par[50005];

void bfs(int s, int f)
{
    for(int i=0; i<=50004; i++)
    {
        sort(V[i].begin(),V[i].end());
        visited[i]=0;
        par[i]=-1;
    }
    visited[s]=1;
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        if(u==f)
            return ;

        int sz=V[u].size();

        for(int i=0; i<sz; i++)
        {
            int v=V[u][i];

            if(visited[v]==0)
            {
                visited[v]=1;
                q.push(v);
                par[v]=u;
            }
        }
    }
}

void print(int u)
{
    if(par[u]==-1)
    {
        printf("%d",u);
        return;
    }
    print(par[u]);
    printf(" %d",u);
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        int N;
        scanf("%d",&N);

        for(int i=0; i<50004; i++)
            V[i].clear();

        for(int i=0; i<N; i++)
        {
            scanf("%d",&Arr[i]);

            if(i==0)
                continue;
            V[Arr[i]].push_back(Arr[i-1]);
            V[Arr[i-1]].push_back(Arr[i]);
        }
        printf("Case %d:\n",++t);
        bfs(Arr[0],Arr[N-1]);
        print(Arr[N-1]);
        printf("\n");
    }
}

/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1357

#include<bits/stdc++.h>
using namespace std;
long long int N,P,notvisited;
long long int visited[100005];
vector<long long int>V[100005];

void DFS(long long int u)
{
    notvisited+=1;
    visited[u]=1;
    int sz=V[u].size();

    for(int i=0; i<sz; i++)
    {
        long long int v=V[u][i];

        if(visited[v]==0)
            DFS(v);
    }
    P+=(N-notvisited);
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%lld",&N);

        P=0;
        notvisited=0;
        for(int i=0; i<N+3; i++)
        {
            V[i].clear();
            visited[i]=0;
        }

        for(int i=0; i<N-1; i++)
        {
            long long int x,y;
            scanf("%lld%lld",&x,&y);
            V[x].push_back(y);
            V[y].push_back(x);
        }
        DFS(1);

        printf("Case %d: %lld %lld\n",++t,N-1,P);
    }
}

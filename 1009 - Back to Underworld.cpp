/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1009

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        int S,n,C=0,level[100005]={0},visited[100005]={0},ara[20005]={0};

        vector<int>V[100005];
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            V[x].push_back(y);
            V[y].push_back(x);
            ara[x]++;
            ara[y]++;
        }

        for(int l=0; l<=20003; l++)
        {
            vector<int>VV,VV1;

            if(ara[l]>0){
            S=l;
            queue<int>Q;
            Q.push(S);
            level[S]=0;
            visited[S]=1;
            VV.push_back(S);

            while(!Q.empty())
            {
                int u=Q.front();
                ara[u]=0;
                Q.pop();
                int sz=V[u].size();

                for(int i=0; i<sz; i++)
                {
                    int v=V[u][i];
                    if(visited[v]==0)
                    {
                        ara[v]=0;
                        visited[v]=1;
                        level[v]=level[u]+1;

                        if(level[v]%2==0)
                            VV.push_back(v);

                        else VV1.push_back(v);

                        Q.push(v);
                    }
                }
            }

            int p=VV.size();
            int q=VV1.size();
            C=C+max(p,q);
            }
        }
    printf("Case %d: %d\n",++t,C);

    }
}

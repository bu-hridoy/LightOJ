/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1141

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,t=0,prime[1005];
    scanf("%d",&T);
    prime[0]=0;
    prime[1]=0;

    for(int i=2; i<=1003; i++)
    {
        int cheak=0;
        int root=sqrt(i);
        for(int j=2; j<=root; j++)
        {
            if(i%j==0)
            {
                cheak=1;
                break;
            }
        }

        if(cheak==1)
            prime[i]=0;
        else
            prime[i]=1;
    }


    while(T--){
    int N,M,arr[1005],k=0;
    scanf("%d%d",&N,&M);

        int visited[1005],level[1005],ans=-1;
        for(int i=0; i<1003; i++)
        {
            visited[i]=0;
            level[i]=0;
        }

        queue<int>q;
        q.push(N);
        visited[N]=1;
        level[N]=0;

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            if(u==M)
            {
                ans=level[u];
                break;
            }

            for(int i=2; i<u; i++)
            {
                int v=u+i;

                if(visited[v]==0 && v<=M && u%i==0 && prime[i]==1)
                {
                    visited[v]=1;
                    q.push(v);
                    level[v]=level[u]+1;
                }
            }
        }

        if(ans==-1)
            printf("Case %d: -1\n",++t);
        else
            printf("Case %d: %d\n",++t,ans);

    }
}

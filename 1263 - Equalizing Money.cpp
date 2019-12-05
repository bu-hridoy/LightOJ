/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1263

#include<bits/stdc++.h>
using namespace std;

vector<int>V[1005];
bool visited[1005];
int sum=0,cnt=0,Arr[1005];

void DFS(int u)
{
    visited[u]=true;
    int sz=V[u].size();
    sum+=Arr[u];
    cnt+=1;

    for(int i=0; i<sz; i++)
    {
        int v=V[u][i];
        if(visited[v]==false)
            DFS(v);
    }
}

int main()
{
    int T;
    int t=0;
    scanf("%d",&T);

    while(T--)
    {
        cnt=0;sum=0;
        for(int i=0; i<=1003; i++)
        {
            visited[i]=false;
            V[i].clear();
            Arr[i]=0;
        }
        int n,m,Total=0;
        scanf("%d%d",&n,&m);

        for(int i=1; i<=n; i++){
            scanf("%d",&Arr[i]);
            Total+=Arr[i];
        }

        for(int i=0; i<m; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);

            V[x].push_back(y);
            V[y].push_back(x);
        }

        if((Total%n)!=0)
            printf("Case %d: No\n",++t);


        else{
        int flag=0;
        int div=Total/n;
        for(int i=1; i<=n; i++)
        {
            if(visited[i]==false)
            {
                DFS(i);
                if(div*cnt!=sum)
                {
                    flag=1;
                    break;
                }
            }
        }

        if(flag==0)
            printf("Case %d: Yes\n",++t);
        else
            printf("Case %d: No\n",++t);
        }

    }
}

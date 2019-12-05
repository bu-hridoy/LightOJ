/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1040

#include<bits/stdc++.h>
using namespace std;
int arr[55][55];
int visited[55];
int Par[55],Node;
vector<int>V[55];
vector< pair<int, pair<int,int> > > E;

void init()
{
    for(int i=0; i<=53; i++)
    {
        V[i].clear();
        visited[i]=0;
        Par[i]=i;
    }
    E.clear();
}

void DFS(int u)
{
    visited[u]=1;
    int sz=V[u].size();

    for(int i=0; i<sz; i++)
    {
        int v=V[u][i];

        if(visited[v]==0)
            DFS(v);
    }
}

int Find(int A)
{
    if(Par[A]==A)
        return A;

    Par[A]=Find(Par[A]);
    return Par[A];
}

int Krushkal()
{
    sort(E.begin(),E.end());
    int sz=E.size();

    int flag=0,ANSS=0;

    for(int i=0; i<sz; i++)
    {
        int a=E[i].second.first;
        int b=E[i].second.second;
        int w=E[i].first;

        int M=Find(a);
        int N=Find(b);

        if(M!=N)
        {
            Par[M]=N;
            flag++;
            ANSS+=w;
        }
        if(flag==Node-1)
            break;
    }

    return ANSS;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        int N,ANS=0,Count=0;
        scanf("%d",&N);
        memset(arr,0,sizeof(arr));
        init();

        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                scanf("%d",&arr[i][j]);

        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
        {
            if(i==j)
            {
                if(arr[i][j]>0)
                   {
                       ANS+=arr[i][j];
                      continue;
                   }
            }
            if(arr[i][j]>0){
                Count+=arr[i][j];
                E.push_back(make_pair(arr[i][j], make_pair(i,j)));
                V[j].push_back(i);
                V[i].push_back(j);
            }
        }

        int Componant=0;
        Node=N;
        for(int i=1; i<=N; i++)
        {
            if(visited[i]==0)
            {
                Componant++;
                DFS(i);
            }
        }

        if(Componant>1)
             printf("Case %d: -1\n",++t);
        else
        {
            int ans=Krushkal();
            if(ans==Count)
                printf("Case %d: %d\n",++t,ANS);
            else
            printf("Case %d: %d\n",++t,(Count-ans)+ANS);
        }
    }
}

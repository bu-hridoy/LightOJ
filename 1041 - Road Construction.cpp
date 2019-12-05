/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1041

#include<bits/stdc++.h>
using namespace std;

vector<int>V[105];
vector<pair<int, pair<int,int> > > E;
int visited[105],Par[105],Node;

void init()
{
    for(int i=0; i<=102; i++)
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
    if(Par[A]==A) return A;
    Par[A]=Find(Par[A]);
    return Par[A];
}

int Krushkal()
{
    sort(E.begin(),E.end());
    int sz=E.size();
    int ANS=0,flag=0;

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
            ANS+=w;
            flag++;
        }
        if(flag==Node-1)
            break;
    }
    return ANS;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        int edge,index=1;
        scanf("%d",&edge);

        map<string,int>mp;
        map<string,bool>mark;
        init();
        for(int i=0; i<edge; i++)
        {
            string S,S2;
            int num;
            cin>>S>>S2>>num;

            if(mark[S]==false)
            {
                mark[S]=true;
                mp[S]=index++;
            }
            if(mark[S2]==false)
            {
                mark[S2]=true;
                mp[S2]=index++;
            }
            int x=mp[S];
            int y=mp[S2];

            E.push_back(make_pair(num,make_pair(x,y)));
            V[x].push_back(y);
            V[y].push_back(x);
        }

        Node=index-1;
        int Componant=0;
        for(int i=1; i<=Node; i++)
        {
            if(visited[i]==0)
            {
                DFS(i);
                Componant++;
            }
        }
        if(Componant>1)
            printf("Case %d: Impossible\n",++t);
        else
        {
            int Ans=Krushkal();
            printf("Case %d: %d\n",++t,Ans);
        }
    }
}

/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1029

#include<bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int,int> > >V;
int N;
int Par[105];

void init(int N)
{
    for(int i=0; i<=N; i++)
    {
        Par[i]=i;
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
    int sz=V.size(),ans=0,flag=0;
    for(int i=0; i<sz; i++)
    {
        int a=V[i].second.first;
        int b=V[i].second.second;
        int w=V[i].first;

        int M=Find(a);
        int N=Find(b);

        if(M!=N)
        {
            Par[M]=N;
            flag++;
            ans+=w;
        }
    }
    return ans;
}
int Krushkal2()
{
        int sz=V.size(),ans=0,flag=0;
        for(int i=sz-1; i>=0; i--)
        {
        int a=V[i].second.first;
        int b=V[i].second.second;
        int w=V[i].first;

        int M=Find(a);
        int N=Find(b);

        if(M!=N)
        {
            Par[M]=N;
            flag++;
            ans+=w;
        }
        }
    return ans;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while(T--)
    {
        int N,x,y,w;
        scanf("%d",&N);
        V.clear();

        while(scanf("%d%d%d",&x,&y,&w))
        {
            if(x==0 && y==0 && w==0)
                break ;
            V.push_back(make_pair(w,make_pair(x,y)));
        }
             sort(V.begin(),V.end());
            init(N);

            int first=Krushkal();

            init(N);
            int second=Krushkal2();
            int ans=first+second;

            if(ans%2==0)
                printf("Case %d: %d\n",++t,ans/2);
            else
                printf("Case %d: %d/2\n",++t,ans);
    }
}

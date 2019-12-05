/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1059

#include<bits/stdc++.h>
using namespace std;
#define in long long int

in Par[10005];
in Node,Cost;
vector<pair<in, pair<in,in> > > E;


void init(in N)
{
    for(int i=0; i<=N+3; i++){
        Par[i]=i;
    }
}

in Find(in A)
{
    if(Par[A]==A)
        return A;
    Par[A]=Find(Par[A]);
    return Par[A];
}

in krushkal()
{
    sort(E.begin(),E.end());
    in sz=E.size();
    in ans=0;

    for(int i=0; i<sz; i++)
    {
        in a=E[i].second.second;
        in b=E[i].second.first;
        in w=E[i].first;

        in M=Find(a);
        in N=Find(b);

        if(w>=Cost)
            break;

        if(M!=N)
        {
            Par[M]=N;
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
        in Edge;
        scanf("%lld%lld%lld",&Node,&Edge,&Cost);

        init(Node);
        for(int i=0; i<Edge; i++){
        in X,Y,W;
        scanf("%lld%lld%lld",&X,&Y,&W);
        E.push_back(make_pair(W,make_pair(X,Y)));

        }

        in ans=krushkal();
        in cnt=0;
        for(int i=1; i<=Node; i++)
        {
            if(Par[i]==i)
            {
                cnt++;
            }
        }
        printf("Case %d: %lld %lld\n",++t,(cnt*Cost)+ans,cnt);
        E.clear();
    }
}

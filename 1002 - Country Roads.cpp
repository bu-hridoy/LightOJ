/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1002

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        priority_queue<pii,vector<pii>,greater<pii> >q;
        vector<pair<int,int> >V[505];
        int d[505];

        int node,edge;
        scanf("%d%d",&node,&edge);

        for(int i=0; i<edge; i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);

            V[x].push_back(make_pair(w,y));
            V[y].push_back(make_pair(w,x));
        }

        for(int i=0; i<node+2; i++)
            d[i]=INT_MAX;

        int s;
        scanf("%d",&s);
        q.push(make_pair(0,s));
        d[s]=0;

        while(!q.empty())
        {
            pair<int,int>P=q.top();
            q.pop();

            int u=P.second;

            for(int i=0;i<V[u].size(); i++)
            {
                int v=V[u][i].second;
                int w=V[u][i].first;

                if(max(d[u],w)<d[v]){
                    d[v]=max(d[u],w);
                    q.push(make_pair(w,v));
            }
            }
        }
        printf("Case %d:\n",++t);
        for(int i=0; i<node; i++)
        {
         if(i!=s)
         {
             if(d[i]!=INT_MAX) printf("%d\n",d[i]);
             else printf("Impossible\n");
         }
         else
            printf("0\n");
       }
    }
}

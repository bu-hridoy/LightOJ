/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1221

    #include<bits/stdc++.h>
    using namespace std;
    int dis[105], N,R,P;
    vector<pair<pair<int,int> , int > >V;

    bool Bellman_Ford(int s)
    {
        for(int i=0; i<=100; i++)
        {
            dis[i]=0;//INT_MAX;
        }
        dis[s]=0;
        int sz=V.size();

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<sz; j++)
            {
                int x=V[j].first.first;
                int y=V[j].first.second;
                int cost=V[j].second;

                if(dis[x]+cost<dis[y])
                {
                    dis[y]=dis[x]+cost;
                }
            }
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<sz; j++)
            {
                int x=V[j].first.first;
                int y=V[j].first.second;
                int cost=V[j].second;

                if(dis[x]+cost<dis[y])
                {
                    return true;
                }
            }
        }
        return false;
    }

    int main()
    {
        int T,t=0;
        scanf("%d",&T);

        while(T--)
        {
           V.clear();
            scanf("%d%d%d",&N,&R,&P);

            for(int i=0; i<R; i++)
            {
                int X,Y,I,E,W;
                scanf("%d%d%d%d",&X,&Y,&I,&E);
                W=P*E-I;
                V.push_back(make_pair(make_pair(X,Y),W));
            }
            if(Bellman_Ford(0))
                printf("Case %d: YES\n",++t);
            else
                printf("Case %d: NO\n",++t);
        }
    }


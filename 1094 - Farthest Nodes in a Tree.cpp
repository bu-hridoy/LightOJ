/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1094

    #include<bits/stdc++.h>
    using namespace std;
    #define lld long long int
    lld visited[30005],dis[30005];
    vector<pair<lld,lld> >V[30005];
    lld Mx;
    lld BFS(lld S)
    {
        lld start,Mx1=0;
            queue<lld>q;
            q.push(S);
            visited[S]=1;

            while(!q.empty())
            {
                lld value=q.front();
                q.pop();
                int sz=V[value].size();

                for(int i=0; i<sz; i++)
                {
                    if(visited[V[value][i].first]==0)
                    {
                        visited[V[value][i].first]=1;
                        dis[V[value][i].first]=dis[value]+V[value][i].second;

                        if(dis[V[value][i].first]>Mx1){
                                Mx1=dis[V[value][i].first];
                                start=V[value][i].first;
                        }
                        q.push(V[value][i].first);
                    }
                }
            }
            Mx=Mx1;
            return start;
    }

    int main()
    {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        lld T,t=0;
        cin>>T;

        while(T--)
        {
            for(int i=0; i<=30004; i++)
            V[i].clear();
            lld node,x,y,N,w;
            cin>>node;
            N=node;
            while(node-- && node>0)
            {
                cin>>x>>y>>w;
                V[x].push_back(make_pair(y,w));
                V[y].push_back(make_pair(x,w));
            }


            memset(visited,0,sizeof(visited));
            memset(dis,0,sizeof(dis));

            lld st=BFS(1);

            memset(visited,0,sizeof(visited));
            memset(dis,0,sizeof(dis));

           lld p= BFS(st);

          printf("Case %lld: %lld\n",++t,Mx);
        }
    }


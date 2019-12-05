/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1175

    #include<bits/stdc++.h>
    using namespace std;
    const int INF = 0x3f3f3f3f;
    char Arr[203][203];
    int R,C;
    int fx[]={0,0,+1,-1};
    int fy[]={+1,-1,0,0};

    int dis[203][203];
    bool escape(int i, int j)
    {
        if(i==0 || i==R-1 || j==0 || j==C-1)
            return true ;
        return false;
    }

    bool valid(int i, int j)
    {
        if(i>=0 && i<R && j<C && j>=0)
            return true;
        return false;
    }

    void  BFS_Fire()
    {
        queue<pair<int,int> >qq;
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                if(Arr[i][j]=='F'){
                    qq.push(make_pair(i,j));
                        dis[i][j]=0;
                }

            while(!qq.empty())
            {
            pair<int,int>P=qq.front();
            qq.pop();
            int x=P.first;
            int y=P.second;

            for(int i=0; i<4; i++)
            {
                int dx=x+fx[i];
                int dy=y+fy[i];

                if(valid(dx,dy) && Arr[dx][dy]!='#' && dis[dx][dy]>dis[x][y]+1)
                {
                    dis[dx][dy]=dis[x][y]+1;
                    qq.push(make_pair(dx,dy));
                }
            }
        }

    }

    int  BFS_Jane(int sc,int sd)
    {
        if(escape(sc, sd)) return 1;
        queue<pair<int,int> >q;
        q.push(make_pair(sc,sd));
        dis[sc][sd]=0;
        while(!q.empty())
        {
            pair<int,int>P=q.front();
            q.pop();

            int x=P.first;
            int y=P.second;

            for(int i=0; i<4; i++)
            {
                int dx=x+fx[i];
                int dy=y+fy[i];

                if(valid(dx,dy) && Arr[dx][dy]!='#' )
                        if(dis[dx][dy]>dis[x][y]+1)
                        {
                           dis[dx][dy]=dis[x][y]+1;
                            if(escape(dx,dy)){
                                return dis[dx][dy]+1;
                            }
                            q.push(make_pair(dx,dy));
                        }
            }
        }
        return -1;
    }

    int main()
    {
        int T,t=0;
        scanf("%d",&T);

        while(T--){
        int xx,yy;
        scanf("%d%d",&R,&C);

        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++){
                cin>>Arr[i][j];
                dis[i][j]=INF;
                if(Arr[i][j]=='J')
                {
                    xx=i;
                    yy=j;
                }
            }

            BFS_Fire();

            int ans=BFS_Jane(xx,yy);

            if(ans==-1)
                printf("Case %d: IMPOSSIBLE\n",++t);
            else
                printf("Case %d: %d\n",++t,ans);
        }
    }




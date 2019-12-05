    /// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1238

    #include<bits/stdc++.h>
    using namespace std;
    int fx[]={+1,-1,0,0};
    int fy[]={0,0,+1,-1};

    int main()
    {
        int T,t=0;
        scanf("%d",&T);

        while(T--)
        {
            char arr[25][25];
            int n,m,hx,hy,level[25][25],visited[25][25];
            scanf("%d%d",&n,&m);
            int ax,ay,bx,by,cx,cy;

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    cin>>arr[i][j];
                    if(arr[i][j]=='h')
                    {
                        hx=i;
                        hy=j;
                    }

                    if(arr[i][j]=='a')
                    {
                        ax=i;
                        ay=j;
                    }
                     if(arr[i][j]=='b')
                    {
                        bx=i;
                        by=j;
                    }
                     if(arr[i][j]=='c')
                    {
                        cx=i;
                        cy=j;
                    }
                }
            }

            queue<pair<int,int> >q;
            q.push(make_pair(hx,hy));
            memset(level,0,sizeof(level));
            memset(visited,0,sizeof(visited));
            visited[hx][hy]=1;

            while(!q.empty())
            {
                pair<int,int>P=q.front();
                q.pop();
                int x=P.first;
                int y=P.second;

                for(int i=0; i<4; i++)
                {
                    int xx=fx[i]+x;
                    int yy=fy[i]+y;

                    if(xx>=0 && yy>=0 && xx<n && yy<m && visited[xx][yy]==0 && arr[xx][yy]!='#' && arr[xx][yy]!='m')
                    {
                        visited[xx][yy]=1;
                        q.push(make_pair(xx,yy));
                        level[xx][yy]=1+level[x][y];
                    }
                }
            }

            int ans=max(level[ax][ay],level[bx][by]);
            ans=max(ans,level[cx][cy]);

            printf("Case %d: %d\n",++t,ans);
        }
    }



/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1337
#include<bits/stdc++.h>
using namespace std;
char Arr[505][505];
int mat[505][505],n,m;

int fx[]={+1,-1,0,0};
int fy[]={0,0,+1,-1};

void bfs(int sc,int sd)
{
    queue<pair<int,int> >q;
    q.push(make_pair(sc,sd));
    mat[sc][sd]=0;

    vector<pair<int,int> >V;
    int cnt=0;
    while(!q.empty())
    {
        pair<int,int>P=q.front();
        q.pop();

        int x=P.first;
        int y=P.second;

        if(Arr[x][y]=='C')
            cnt++;
        V.push_back(make_pair(x,y));

        for(int i=0; i<4; i++)
        {
            int dx=x+fx[i];
            int dy=y+fy[i];

            if(dx>=0 && dx<n && dy>=0 && dy<m)
            {
                if(Arr[dx][dy]!='#' && mat[dx][dy]==-1)
                {
                    mat[dx][dy]=1;
                    q.push(make_pair(dx,dy));
                }
            }
        }
    }

    int sz=V.size();
    for(int i=0; i<sz; i++)
    {
        int x=V[i].first;
        int y=V[i].second;
        mat[x][y]=cnt;
    }
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        int q;
        scanf("%d%d%d",&n,&m,&q);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>Arr[i][j];
                mat[i][j]=-1;
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==-1 && Arr[i][j]!='#')
                    bfs(i,j);
            }
        }

        printf("Case %d:\n",++t);
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",mat[x-1][y-1]);
        }
    }
}

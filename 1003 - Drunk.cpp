/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1003

#include<bits/stdc++.h>
using namespace std;
vector<int>V[10008];
int visited[10008],reset[10008];

bool DFS(int n)
{
    if(visited[n]==0)
    {
        visited[n]=1;
        reset[n]=1;

        int sz=V[n].size();

        for(int i=0; i<sz; i++)
        {
            int v=V[n][i];
            if(visited[v]==0 && DFS(v))
                return true;
            else if(reset[v]==1)
                return true;
        }
    }

    reset[n]=0;
    return false;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        int m,k=0;
        map<string,int>mp;
        for(int i=0; i<10005; i++){
            V[i].clear();
            visited[i]=0;
            reset[i]=0;
        }

        scanf("%d",&m);

        for(int i=0; i<m; i++)
        {
            string s1,s2;
            cin>>s1>>s2;

            if(mp[s1]==0)
                mp[s1]=++k;
            if(mp[s2]==0)
                mp[s2]=++k;

           int x=mp[s1];
           int y=mp[s2];

           V[x].push_back(y);
        }

        int flag=0;

        for(int i=1; i<=k; i++)
        {
            if(DFS(i))
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("Case %d: No\n",++t);
        else
            printf("Case %d: Yes\n",++t);
    }
}

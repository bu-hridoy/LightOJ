/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1049

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        int node,LEFT[102],RIGHT[102];
        scanf("%d",&node);

        for(int i=0; i<=node+1; i++)
        {
            LEFT[i]=0;
            RIGHT[i]=0;
        }

        int C=0,D=0;
        for(int i=1; i<=node; i++)
        {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);

            if(LEFT[a]==0 && RIGHT[b]==0)
            {
                LEFT[a]=1;
                RIGHT[b]=1;
                C=C+w;
            }
            else
            {
                RIGHT[a]=1;
                LEFT[b]=1;
                D=D+w;
            }
        }
        printf("Case %d: %d\n",++t,min(C,D));
    }
}

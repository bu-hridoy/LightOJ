/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1088

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        vector<int>V;
        vector<int>::iterator a,b;
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            V.push_back(x);
        }

        printf("Case %d:\n",++t);
        while(q--)
        {
            int l,h;
            scanf("%d%d",&l,&h);
            l-=1;
            h+=1;
            a=lower_bound(V.begin(),V.end(),h);
            b=upper_bound(V.begin(),V.end(),l);
            printf("%d\n",a-b);
        }
    }
}

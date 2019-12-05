/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1082

#include<bits/stdc++.h>
using namespace std;
#define lld long long int
lld arr[100005],Tree[400005];

void init(lld node, lld b, lld e)
{
    if(b==e)
    {
        Tree[node]=arr[b];
        return ;
    }
    lld L=2*node;
    lld R=2*node+1;
    lld Mid=(b+e)/2;

    init(L,b,Mid);
    init(R,Mid+1,e);

    Tree[node]=min(Tree[L],Tree[R]);
}


int query(lld node,lld b,lld e,lld i,lld j)
{
    if(j<b || i>e) return INT_MAX;
    if(i<=b && j>=e){
        return Tree[node];
    }
    lld L=2*node;
    lld R=2*node + 1;
    lld Mid=(b+e)/2;

    lld Q=query(L,b,Mid,i,j);
    lld Q1=query(R,Mid+1,e,i,j);


    return min(Q,Q1);
}

int main()
{
    lld T,t=0;
    scanf("%lld",&T);
    while(T--){
    memset(arr,0,sizeof(arr));
    memset(Tree,0,sizeof(Tree));

    lld N,q;
    scanf("%lld%lld",&N,&q);

    for(int i=1; i<=N; i++)
    {
        scanf("%lld",&arr[i]);
    }

    init(1,1,N);

    printf("Case %lld:\n",++t);

    while(q--){
        lld rng_1,rng_2;
        scanf("%lld%lld",&rng_1,&rng_2);

        lld ans=query(1,1,N,rng_1,rng_2);
        printf("%lld\n",ans);
    }

    }
}

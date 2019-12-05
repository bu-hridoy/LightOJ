/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1164

#include<bits/stdc++.h>
using namespace std;

#define     I(X)            scanf("%d",&(X))
#define     II(X, Y)        scanf("%d%d",&(X),&(Y))
#define     III(X,Y,Z)      scanf("%d%d%d",&(X),&(Y),&(Z))
#define ll long long int

ll Arr[100005],Tree[400005],Lazy[400005];

ll init(int node, int S, int E)
{
    if(S==E)
    {
        Tree[node]=Arr[S];
        return Arr[S];
    }
    int L=2*node;
    int R=2*node+1;
    int mid=(S+E)/2;

    ll x=init(L,S,mid);
    ll y=init(R,mid+1,E);

    Tree[node]=x+y;
}

ll update(int node, int S, int E, int i, int j, int val)
{
    if(Lazy[node]!=0)
    {
        Tree[node]+=Lazy[node]*(E-S+1);
        if(S!=E)
        {
            Lazy[node*2 ]+=Lazy[node];
            Lazy[node*2 +1]+=Lazy[node];
        }
        Lazy[node]=0;
    }

    if(S>j || E<i)
        return 0;

    if(S>=i && E<=j)
    {
        Tree[node]+=(E-S+1)*val;
        if(S!=E)
        {
            Lazy[node*2]+=val;
            Lazy[2*node+1]+=val;
        }
        return 0;
    }

    int L=2*node;
    int R=2*node+1;
    int mid=(S+E)/2;

    update(L,S,mid,i,j,val);
    update(R,mid+1,E,i,j,val);

    Tree[node]=Tree[L]+Tree[R];
}

ll query(int node, int S, int E, int i, int j)
{
    if(S>E || S>j || E<i)
        return 0;

    if(Lazy[node]!=0)
    {
        Tree[node]+=Lazy[node]*(E-S+1);
        if(S!=E)
        {
            Lazy[node*2]+=Lazy[node];
            Lazy[2*node+1]+=Lazy[node];
        }
        Lazy[node]=0;
    }

    if(S>=i && E<=j)
        return Tree[node];


    int L=2*node;
    int R=2*node+1;
    int mid=(S+E)/2;

    ll q1=query(L,S,mid,i,j);
    ll q2=query(R,mid+1,E,i,j);

    return q1+q2;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--){

    memset(Lazy,0,sizeof Lazy);
    memset(Arr,0,sizeof Arr);
    memset(Tree,0,sizeof Tree);

    int n,q;
    scanf("%d%d",&n,&q);

    printf("Case %d:\n",++t);

        while(q--){
                int a,b,x,l;
             I(l);
        if(l==0){
       III(a,b,x);
        update(1,0,n-1,a,b,x);
        }
        else{
            II(a,b);
            ll ans=query(1,0,n-1,a,b);
            printf("%lld\n",ans);
        }
        }
    }
}


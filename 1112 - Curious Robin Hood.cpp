/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1112

#include<bits/stdc++.h>
using namespace std;

/*-------------------------- HRIDOY ROY -------------------------*/

#define     fRead           freopen("input.txt","r",stdin)
#define     fWrite          freopen("output.txt","w",stdout)

#define     I(X)            scanf("%d",&(X))
#define     II(X, Y)        scanf("%d%d",&(X),&(Y))
#define     III(X,Y,Z)      scanf("%d%d%d",&(X),&(Y),&(Z))
#define     IL(X)           scanf("%lld",&(X))
#define     IIL(X, Y)       scanf("%lld%lld",&(X),&(Y))
#define     pb              push_back
#define     popb            pop_back
#define     lld             long long int
#define     ull             unsigned long long int
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     MOD             1000000009
#define     f               first
#define     s               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     mp              make_pair
#define     show            printf("---***---")
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     pii             pair<int,int>
#define     PLL             pair<lld,lld>
#define     MAX             100000000000014
#define     MIN             -100000000000014
#define     gti             greater<int>
#define     gtL             greater<lld>
#define     PI1             acos(-1.0)
#define     pi2             2.0*acos(0.0)
#define     endl            '\n'

int Day12[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int prime100[]={2, 3, 5, 7, 11, 13, 17, 19, 23,29,31, 37, 41, 43, 47, 53, 59,61, 67,71, 73, 79, 83, 89, 97, 101, 103 };

template <typename T> inline bool isLeap(T y) {return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false);}
template <typename T> inline T GCD (T a,T b ) {a = abs(a);b = abs(b); if(a < b) swap(a, b); while ( b ) { a = a % b; swap ( a, b ); } return a;}
template <typename T> inline T LCM(T x,T y){T tp = GCD(x,y);if( (x / tp) * 1. * y > 9e18) return 9e18;return (x / tp) * y;}
template <typename T> inline T BIGMOD(T A,T B,T M = MOD){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
template <typename T> inline T BigMod(T A,T B,T M){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}

//----------------------------- O.D.Y.W.F.M ----------------------------------//
lld arr[100005],Tree[400004];

void init(int node, int S, int E)
{
    if(S==E)
    {
        Tree[node]=arr[S];
        return ;
    }

    int L=node*2;
    int R=node*2+1;
    int mid=(S+E)/2;

    init(L,S,mid);
    init(R,mid+1,E);

    Tree[node]=Tree[L]+Tree[R];
}

lld querytwo(int node, int S, int E, int i ,int j)
{
    if(S>j || E<i)
        return 0;

    if(S>=i && E<=j)
        return Tree[node];

    int L=node*2;
    int R=node*2+1;
    int mid=(S+E)/2;

    lld q1=querytwo(L,S,mid,i,j);
    lld q2=querytwo(R,mid+1,E,i,j);

    return q1+q2;
}

lld queryone(int node, int S, int E, int i ,int j)
{
    if(S>j || E<i)
        return 0;

    if(S>=i && E<=j)
        return Tree[node];

    int L=node*2;
    int R=node*2+1;
    int mid=(S+E)/2;

    lld q1=querytwo(L,S,mid,i,j);
    lld q2=querytwo(R,mid+1,E,i,j);

    return q1+q2;
}

void update(int node, int S, int E, int i, lld val, int no)
{
    if(S>i || E<i)
        return ;
    if(S>=i && E<=i)
    {
        if(no==1)
        Tree[node]=val;

        else
            Tree[node]+=val;

        return ;
    }
    int L=node*2;
    int R=node*2+1;
    int mid=(S+E)/2;

    update(L,S,mid,i,val,no);
    update(R,mid+1,E,i,val,no);

    Tree[node]=Tree[L]+Tree[R];
}

int main()
{
    int T,t=0;
    I(T);

    while(T--)
    {
        int n,q;
        II(n,q);

        for(int i=1; i<=n; i++)
        {
            lld A;
            IL(A);
            arr[i]=A;
        }

        init(1,1,n);
        printf("Case %d:\n",++t);

        while(q--)
        {
            int no;
            I(no);

            if(no==1)
            {
                int x;
                I(x);
                x+=1;
                lld ans=queryone(1,1,n,x,x);
                printf("%lld\n",ans);
                update(1,1,n,x,0,1);
            }
            else if(no==2)
            {
                lld x,val;
                I(x);
                x+=1;
                IL(val);
                update(1,1,n,x,val,2);
            }
            else
            {
                int x,y;
                II(x,y);
                x+=1;
                y+=1;
                lld ans=querytwo(1,1,n,x,y);
                printf("%lld\n",ans);
            }
        }
    }
}

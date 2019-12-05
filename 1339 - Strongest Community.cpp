/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1339

#include<bits/stdc++.h>
using namespace std;

int l=0,r=-1,sum=0,k,Arr[100005],ans[50005];
int cntcnt[100005];
int cnt[100005];

struct query{
    int l,r,id;
}q[50005];
/*

bool cmp(query A, query B)
{
  if (A.l / k != B.l / k) return A.l< B.l;
  return (A.r < B.r)^(A.l/k%2);
}

*/

bool cmp(query a, query b)
{
    int x=a.l/k;
    int y=b.l/k;

    if(x==y)
        return a.r<b.r;
    return x<y;
}

void Add (int x) {
    int v=Arr[x];
    cntcnt[cnt[v]]--;
    cnt[v]++;
    cntcnt[cnt[v]]++;
    if (sum < cnt[v]) {
        sum++;
    }
}

void Remove(int x) {
    int v=Arr[x];
    cntcnt[cnt[v]]--;
    cnt[v]--;
    cntcnt [cnt[v]]++;
    if (cntcnt[sum] == 0) {
        sum--;
    }
}

int main()
{
    int t=0,T;
    scanf("%d",&T);
    while(T--){

    l=0;
    r=-1;
    sum=0;
    memset(cntcnt,0,sizeof cntcnt);
    memset(cnt,0,sizeof cnt);

    int n,c,Q;
    scanf("%d%d",&n,&c);
    scanf("%d",&Q);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&Arr[i]);
    }

    for(int i=1; i<=Q; i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    k=sqrt(n);
    sort(q, q+Q, cmp);
    sum=0;

    for(int i=1; i<=Q; i++)
    {
        while(l > q[i].l) Add(--l);
        while(r < q[i].r) Add(++r);
        while(l < q[i].l) Remove(l++);
        while(r > q[i].r) Remove(r--);
        ans[q[i].id]=sum;
    }
    printf("Case %d:\n",++t);
    for(int i=1; i<=Q; i++)
        printf("%d\n",ans[i]);
    }
}

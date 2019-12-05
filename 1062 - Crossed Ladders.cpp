/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1062
#include<bits/stdc++.h>
using namespace std;
double last=0.000000000008;
double H(double h1, double h2)
{
    double h;
    h=(h1*h2)/(h1+h2);
    return h;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        double x,y,c,m,low,high,mid;
        scanf("%lf%lf%lf",&x,&y,&c);

        low=0.0;
        high=min(x,y);

        while(1)
        {
            mid=(low+high)/2;
            double h1=sqrt((y*y)-(mid*mid));
            double h2=sqrt((x*x)-(mid*mid));

            double C=H(h1,h2);
            if(C>c)
            low=mid;

            else if(C<c)
            high=mid;
            if(abs(C-c)<=last)
            {
                printf("Case %d: %.10f\n",++t,mid);
                break ;
            }
        }
    }
}

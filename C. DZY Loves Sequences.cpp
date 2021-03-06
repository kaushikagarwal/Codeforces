/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9

#define fs          first
#define sc          second
#define pb(a)       push_back(a)
#define mp(a,b)     make_pair(a,b)
#define sp          printf(" ")
#define nl          printf("\n")

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define tc1(x)      printf("Case %d: ",x)
#define tc2(x)      printf("Case #%d: ",x)
#define tc3(x)      printf("Case %d:\n",x)
#define tc4(x)      printf("Case #%d:\n",x)

#define pr1(x)      cout<<x<<"\n"
#define pr2(x,y)    cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<"\n"
/* defining macros */

using namespace std;

template <class T> inline T bigmod(T b, T p, T m)
{
    T ret;
    if(p==0) return 1;
    if(p&1)
    {
        ret=(bigmod(b,p/2,m)%m);
        return ((b%m)*ret*ret)%m;
    }
    else
    {
        ret=(bigmod(b,p/2,m)%m);
        return (ret*ret)%m;
    }
}
template <class T> inline T _sqrt(T a)
{
    return (T)sqrt((double)a);
}
template <class T, class X> inline T _pow(T a, X b)
{
    T res=1;
    for(int i=1; i<=b; i++)
        res*=a;
    return res;
}
/* template functions */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef pair<double, double>pdd;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<double>vd;
/* type definition */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction array */

int tc=1;
const long long int mx=100000;
/* global declaration */

struct node
{
    LL a,b,c;
};

int main()
{
    LL x[mx+5],i,j,k,ans,n,l,tmp1,tmp2,idx1,idx2;
    node nn;
    while(cin>>n)
    {
        vector<node>vp;
        l=1;
        k=0;
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&x[i]);
            if(i>1 && x[i]<=x[i-1])
            {
                nn.a=l;
                nn.b=i-1;
                nn.c=i-l;
                vp.pb(nn);
                l=i;
            }
            if(i==n)
            {
                nn.a=l;
                nn.b=i;
                nn.c=i-l+1;
                vp.pb(nn);
            }
        }
        if(n<=2 || vp.size()==1)
        {
            pr1(n);
            return 0;
        }
        ans=k=0;
        for(i=0; i<vp.size()-1; i++)
        {
            if(vp[i].c==1 || vp[i+1].c==1)
            {
                k=vp[i].c+vp[i+1].c;
                ans=max(ans,k);
            }
            else
            {
                idx1=vp[i].b;
                idx2=vp[i+1].a;
                tmp1=x[idx2]-1;
                tmp2=x[idx1]+1;
                if(tmp1>x[idx1-1] || tmp2<x[idx2+1])
                {
                    k=vp[i].c+vp[i+1].c;
                    ans=max(ans,k);
                }
                else
                {
                    k=max(vp[i].c,vp[i+1].c)+1;
                    ans=max(ans,k);
                }
            }
        }
        pr1(ans);
    }
    return 0;
}

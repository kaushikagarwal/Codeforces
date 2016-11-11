/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define iin(x)        scanf("%d",&x)
#define din(x)        scanf("%lf",&x)
#define lin(x)        scanf("%lld",&x)
#define clin(x)       scanf("%I64d",&x)

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define fast          ios::sync_with_stdio(0)
#define read          freopen("input.txt","r",stdin)
#define write         freopen("output.txt","w",stdout)
#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")
#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")
#define prflag3(flag) printf("%s\n",(flag)?"yes":"no")
/* macro definitions */

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
/* type definitions */

LL MOD_EXPO(LL b, LL p, LL m)
{
    if(p==0) return 1;
    LL ret=MOD_EXPO(b,p/2,m)%m;
    ret=(ret*ret)%m;
    return ((p&1) ? (ret*b)%m : ret%m);
}
LL POWER(LL N, LL K)
{
    LL i,ans=1;
    for(i=1; i<=K; i++) ans*=N;
    return ans;
}
int SET(int N, int pos)
{
    return (N | (1<<pos));
}
int RESET(int N, int pos)
{
    return (N & !(1<<pos));
}
bool CHECK(int N, int pos)
{
    return (N & (1<<pos));
}
/* necessary functions */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction arrays */

int tc=1;
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=1e3;
const long long int mod=1e9+7;
/* global declarations */

char str[mx+5];
bool x[mx+5];
bool dsu[mx+5];

void sieve(void)
{
    int i,j,s;
    x[0]=x[1]=true;
    for(i=4; i<=mx; i+=2) x[i]=true;
    s=sqrt(mx);
    for(i=3; i<=s; i+=2)
    {
        if(!x[i])
        {
            for(j=i+i; j<=mx; j+=i) x[j]=true;
        }
    }
    return;
}

int main()
{
    int n,i,k;
    bool flag;
    char ch;
    sieve();
    while(scanf("%s",str+1)!=EOF)
    {
        map<char,int>mp;
        set<int>s;
        setzero(dsu);

        n=strlen(str+1);
        for(i=1; i<=n; i++) mp[str[i]]++;
        for(i=1; i<=n; i++)
        {
            k=1;
            while(!x[i] && i<=n/2 && i*k<=n)
            {
                dsu[i*k]=true;
                s.insert(i*k);
                k++;
            }
        }
        flag=false;
        for(i=0; i<26; i++)
        {
            if(mp[i+'a']>=s.size())
            {
                ch='a'+i;
                flag=true;
                break;
            }
        }
        for(i=1; i<=n; i++)
        {
            if(dsu[i])
            {
                str[i]=ch;
                mp[ch]--;
            }
        }
        ch='a';
        for(i=1; i<=n; i++)
        {
            if(!dsu[i])
            {
                while(!mp[ch]) ch++;
                str[i]=ch;
                mp[ch]--;
            }
        }
        if(flag) printf("YES\n%s\n",str+1);
        else printf("NO\n");
    }
    return 0;
}

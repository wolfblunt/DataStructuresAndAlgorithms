// LUOGU_RID: 91472608
#include<bits/stdc++.h>
#define eps 1e-10
#define N 201001
#define MAX 1001
#define PI acos(-1)
#define inf 1e18
using namespace std;
typedef long long ll;
typedef double db;
inline void read(ll &ret)
{
    ret=0;ll pd=0;char c=getchar();
    while(!isdigit(c)){pd|=c=='-';c=getchar();}
    while(isdigit(c)){ret=(ret<<1)+(ret<<3)+(c^48);c=getchar();}
    ret=pd?-ret:ret;
    return;
}
ll T,s,t,ans[N],l,a[N];
ll n,m,k,x,y,z,b[N];
bool vis[N];
ll d[N];
priority_queue<pair<ll,ll> >q;
vector<pair<ll,ll> >v[N];
int main()
{
	read(n);
	read(m);
	read(k);
	read(l);
	t=n+1;
	for(int i=1;i<=n;i++)
		v[i].clear(),b[i]=false,ans[i]=inf;
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=l;i++)
		read(x),b[x]=true;
	for(int i=1;i<=m;i++)
	{
		read(x);
		read(y);
		read(z);
		v[x].push_back(make_pair(y,z));
		v[y].push_back(make_pair(x,z));
	}
	for(int i=0;(1<<i)<=n;i++)
	{
		v[0].clear();
		for(int j=1;j<=n;j++)
			if(!v[j].empty()&&v[j].back().first==t)
				v[j].pop_back();
		for(int j=1;j<=n;j++)
		{
			if(b[j])
			{
				if((1<<i)&a[j])
					v[s].push_back(make_pair(j,0));
				else
					v[j].push_back(make_pair(t,0));
			}
		}
		for(int j=s;j<=t;j++)
			d[j]=inf,vis[j]=false;
		d[s]=0;
		q.push(make_pair(-d[s],s));
		while(!q.empty())
		{
			ll ver=q.top().second;
			q.pop();
			if(vis[ver])
				continue;
			vis[ver]=true;
			for(int j=0;j<v[ver].size();j++)
			{
				ll to=v[ver][j].first,dis=v[ver][j].second;
				if(d[to]>d[ver]+dis)
				{
					d[to]=d[ver]+dis;
					q.push(make_pair(-d[to],to));
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(!((1<<i)&a[j]))
				ans[j]=min(ans[j],d[j]);	
		}
		v[0].clear();
		for(int j=1;j<=n;j++)
			if(!v[j].empty()&&v[j].back().first==t)
				v[j].pop_back();
		for(int j=1;j<=n;j++)
		{
			if(b[j])
			{
				if((1<<i)&a[j])
					v[j].push_back(make_pair(t,0));
				else
					v[s].push_back(make_pair(j,0));
			}
		}
		for(int j=s;j<=t;j++)
			d[j]=inf,vis[j]=false;
		d[s]=0;
		q.push(make_pair(-d[s],s));
		while(!q.empty())
		{
			ll ver=q.top().second;
			q.pop();
			if(vis[ver])
				continue;
			vis[ver]=true;
			for(int j=0;j<v[ver].size();j++)
			{
				ll to=v[ver][j].first,dis=v[ver][j].second;
				if(d[to]>d[ver]+dis)
				{
					d[to]=d[ver]+dis;
					q.push(make_pair(-d[to],to));
				}
			}
		}
		for(int j=1;j<=n;j++)
			if((1<<i)&a[j])
				ans[j]=min(ans[j],d[j]);
	}
	for(int i=1;i<=n;i++)
		if(ans[i]==inf)
			printf("-1 ");
		else
			printf("%lld ",ans[i]);
	putchar('\n');
	exit(0);
}
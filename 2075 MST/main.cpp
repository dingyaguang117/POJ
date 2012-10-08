#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <map>

using namespace std;

#define typec double // type of cost
#define V 10005
const typec inf = 0x3f3f3f3f; // max of cost

int vis[V]; typec lowc[V];
typec cost[V][V];

typec prim(typec cost[][V], int n) // vertex: 0 ~ n-1
{
int i, j, p;
typec minc, res = 0;
memset(vis, 0, sizeof(vis));
vis[0] = 1;
for (i=1; i<n; i++) lowc[i] = cost[0][i];
for (i=1; i<n; i++) {
minc = inf; p = -1;
for (j=0; j<n; j++)
if (0 == vis[j] && minc > lowc[j]) {
minc = lowc[j]; p = j;
}
if (inf == minc) return -1; // 原图不连通
res += minc; vis[p] = 1;
for (j=0; j<n; j++)
if (0 == vis[j] && lowc[j] > cost[p][j])
lowc[j] = cost[p][j];
}
return res;
}

int main()
{
	double has,v;
	int N,M,i,j=0;
	map<string,int> Map;
	string s,s2;

	scanf("%lf",&has);
	scanf("%d",&N);
	for(i=0;i<N;++i)
	{
		cin>>s;
		Map.insert(map<string,int>::value_type(s,j++));
	}
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			cost[i][j]=inf;
	cin>>M;
	for(i=0;i<M;++i)
	{
		cin>>s>>s2>>v;
		cost[Map[s]][Map[s2]]=v;
		cost[Map[s2]][Map[s]]=v;
	}
	v=prim(cost,N);
	if(v>has)
		cout<<"Not enough cable"<<endl;
	else
		printf("Need %.1lf miles of cable\n",v);
	return 0;
}
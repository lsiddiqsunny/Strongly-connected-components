/*problem link: https://www.hackerrank.com/contests/world-codesprint-11/challenges/hackerland/copy-from/1302215493*/

#include<bits/stdc++.h>
using namespace std;
#define mx 50005
bitset <50010> b[50010];
vector<int>g[mx],rg[mx],path,newg[mx];
int visited[mx],scc[mx],prio[mx];
int numscc;
void go(int v){
	if(visited[v]){
		return;
	}
	visited[v] = 1;
	b[v][v] = 1;
	for(int i = 0; i < newg[v].size(); i++){
		int to = newg[v][i];
		go(to);
		b[v] |= b[to];
	}
}
void dfs1(int s)
{
    visited[s]=1;
    for(int i=0; i<g[s].size(); i++)
    {

        int v=g[s][i];
        if(visited[v]==0) dfs1(v);
    }
    path.push_back(s);
}
void dfs2(int s)
{
    visited[s]=1;
    scc[s]=numscc;
    for(int i=0; i<rg[s].size(); i++)
    {

        int v=rg[s][i];
        if(visited[v]==0) dfs2(v);
    }

}
void dfs3(int s)
{
    visited[s]=1;
    for(int i=0; i<newg[s].size(); i++)
    {

        int v=g[s][i];
        if(visited[v]==0) dfs3(v);
    }
    path.push_back(s);
}
int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    path.clear();
    vector<pair<int,int> > query;
    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x,d;
            cin>>x>>d;
            n++;
            if(d==0)
            {
                g[x].push_back(n);
                rg[n].push_back(x);
            }
            else
            {
                rg[x].push_back(n);
                g[n].push_back(x);
            }
        }
        else
        {
            int x,y;
            cin>>x>>y;
            query.push_back(make_pair(x,y));
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }
    reverse(path.begin(),path.end());
    for(int i=0; i<mx; i++)
    {
        visited[i]=0;
    }
    for(int i=0; i<path.size(); i++)
    {

        if(visited[path[i]]==0)
        {
            numscc=path[i];
            dfs2(path[i]);

        }
    }
    // cout<<numscc<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<g[i].size(); j++)
        {
            int v=g[i][j];
            if(scc[i]!=scc[v])
            {
                newg[scc[i]].push_back(scc[v]);
            }
        }
    }
    path.clear();
    for(int i=0; i<mx; i++)
    {
        visited[i]=0;
    }
   for(int i = 1; i <= n; i++){
		if(scc[i] == i) go(i);
	}
    for(int i=0; i<query.size(); i++)
    {
        int u=query[i].first,v=query[i].second;
        u=scc[u],v=scc[v];

        if(b[u][v]==1)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }



}

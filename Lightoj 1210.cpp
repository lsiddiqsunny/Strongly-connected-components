/*
Problem link: http://www.lightoj.com/volume_showproblem.php?problem=1210 */

#include<bits/stdc++.h>
using namespace std;
#define mx 200005

vector<int>g[mx],rg[mx],s;
int scc[mx];
int visited[mx];
int numscc;

void dfs1(int u)
{
    visited[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(visited[v]==0) dfs1(v);
    }
    s.push_back(u);
}
void dfs2(int u)
{
    visited[u]=1;
    scc[u]=numscc;
    for(int i=0; i<rg[u].size(); i++)
    {
        int v=rg[u][i];
        if(visited[v]==0) dfs2(v);
    }

}
void setting()
{
    for(int i=0; i<mx; i++)
    {
        g[i].clear();
        rg[i].clear();
        visited[i]=0;
        scc[i]=-1;
        numscc=0;
    }
    s.clear();
}
int main()
{
    int test;
    scanf("%d",&test);

    for(int cs=1; cs<=test; cs++)
    {
        setting();


        int n;
        int m;
        scanf("%d%d",&n,&m);


        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        for(int i=1; i<=n; i++)
        {
            if(visited[i]==0)
            {
                dfs1(i);
            }
        }
        memset(visited,0,sizeof visited);
        reverse(s.begin(),s.end());

        for(int i=0; i<n; i++)
        {

            if(visited[s[i]]==0)
            {
                dfs2(s[i]);
                numscc++;
            }
        }
        // cout<<numscc<<endl;
        int in[numscc],out[numscc];
        for(int i=0; i<numscc; i++) in[i]=out[i]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<g[i].size(); j++)
            {
                if(scc[i]!=scc[g[i][j]])
                {
                    in[scc[g[i][j]]]++;
                    out[scc[i]]++;
                }
            }
        }
        int tin=0,tout=0;
        for(int i=0; i<numscc; i++)
        {//cout<<in[i]<<" "<<out[i]<<endl;
            if(in[i]==0) tin++;
            if(out[i]==0) tout++;
        }
        //
        int ans=max(tin,tout);
        if (n == 1 || numscc == 1) ans = 0;
        cout<<"Case "<<cs<<": "<<ans<<endl;

    }
}


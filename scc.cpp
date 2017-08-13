
#include<bits/stdc++.h>
using namespace std;
#define mx 50005

vector<int>g[mx],rg[mx],path,newg[mx];
int visited[mx],scc[mx];
int numscc;

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

int main()
{
    int n,m;
    cin>>n>>m;//taking input number of edges and vertexes
    int u,v;


    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);//making orginal graph
        rg[v].push_back(u); //making reverse graph
    }

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }
    reverse(path.begin(),path.end()); //making topological sort

    for(int i=0; i<mx; i++)
    {
        visited[i]=0;
    }
    int           co=0;
    for(int i=0; i<path.size(); i++)
    {

        if(visited[path[i]]==0)
        {    co++;
            numscc=path[i];
            dfs2(path[i]);

        }
    }
    cout<<co<<endl; //number of strongly connected components
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<g[i].size(); j++)
        {
            int v=g[i][j];
            if(scc[i]!=scc[v])
            {
                newg[scc[i]].push_back(scc[v]); //making scc graph
            }
        }
    }


}

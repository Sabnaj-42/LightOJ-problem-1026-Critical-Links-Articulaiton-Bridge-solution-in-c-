#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10005];
int visit[10005],in[10005],low[10005];
int timer ;
vector<pair<int,int>>ans;
void dfs_bridge(int node,int parent)
{
    visit[node]=1;
    in[node]=low[node]=timer;
    timer++;
    for(int child:graph[node])
    {
        if(child==parent)continue;
        if(visit[child]==1)
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            dfs_bridge(child,node);
            if(low[child]>in[node])
            {
                if(node<child)
                  ans.push_back({node,child});
                else ans.push_back({child,node});
            }
            node[low]=min(low[node],low[child]);

        }
    }
}

int  main()
{
   int t;cin>>t;
   for(int k=1;k<=t;k++)
   {
       for(int i=0;i<10005;i++)
       {
           visit[i]=0;in[i]=0;low[i]=0;
       }
       ans.clear();
       for(int i=0;i<10005;i++)graph[i].clear();
       int n,tmp;cin>>n;tmp=n;
       while(tmp--)
       {
          int u,m=0;cin>>u;
         string s;
       cin>>s;
       for(int j=1;s[j]!=')';j++)
       {
           int d=s[j]-'0';
           m*=10;
           m+=d;
       }

       while(m--)
       {
           int v;cin>>v;
           graph[u].push_back(v);
           graph[v].push_back(u);
       }
       }
       for(int i=0;i<n;i++)
       {
           if(visit[i]==0)
          {
            timer=0;dfs_bridge(i,-1);
          }
       }
       printf("Case %d:\n",k);
       cout<<ans.size()<<" critical links"<<endl;
       sort(ans.begin(),ans.end());
       for(int i=0;i<ans.size();i++)
       {
           cout<<ans[i].first<<" - "<<ans[i].second<<endl;
       }

   }
}

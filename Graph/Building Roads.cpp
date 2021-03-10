#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[],vector<bool>&visited,int src){
    if(visited[src])return;
    visited[src]=1;
    for(auto u:adj[src]){
        dfs(adj,visited,u);
    }
}

int main(){
    int n,e;
    cin>>n;
    cin>>e;
    vector<int>adj[n+1];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count=-1;
    int u=-1;
    int v=-1;
    vector<bool>visited(n+1,0);
    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            count++;
            dfs(adj,visited,i);
            if(u==-1){
                u=i;
            }else if(v==-1){
                v=i;
                ans.push_back({u,v});
            }else{
                u=v;
                v=i;
                ans.push_back({u,v});
            }
        }
    }
    cout<<count<<endl;
    for(auto u:ans){
        cout<<u.first<<" "<<u.second<<endl;
    }
}
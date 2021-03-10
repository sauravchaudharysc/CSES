#include<bits/stdc++.h>
using namespace std;


void bfs(vector<int>adj[],int n){
    queue<pair<int,int>>q;
    vector<bool>visited(n+1,0);
    vector<int>parent(n+1,0);
    q.push({1,1});
    parent[1]=-1;
    int ans=-1;
    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        int src=top.first;
        int computer=top.second;
        if(src==n){
            ans=computer;
            break;
        }
        if(visited[src])continue;
        visited[src]=1;
        for(auto u:adj[src]){
            if(!visited[u]){
                q.push({u,computer+1});
                if(parent[u]==0)
                parent[u]=src;
            }
        }
    }
   
    if(ans!=-1){
        cout<<ans<<endl;
        vector<int>result;
        while(n!=-1){
            result.push_back(n);
            n=parent[n];
        }
        reverse(result.begin(),result.end());
        for(auto u:result){
            cout<<u<<" ";
        }
        cout<<endl;
    }    
    else{
        cout<<"IMPOSSIBLE"<<endl;
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
    bfs(adj,n);
}
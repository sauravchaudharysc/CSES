#include<bits/stdc++.h>
using namespace std;
void bfscolorassign(vector<int>adj[],vector<int>&colors,int src,int n,bool &flag){
    queue<pair<int,int>>q;
    vector<int>visited(n+1,0);
    q.push({src,1});
    colors[src]=1;
    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        int pupil=top.first;
        int color=top.second;
        visited[pupil]=1;
        for(auto u:adj[pupil]){
            if(!visited[u]){
                if(color==1){
                    colors[u]=2;
                    q.push({u,0});
                }else{
                    q.push({u,1});
                    colors[u]=1;
                }
            }else if(color==colors[u]){
                flag=1;
                return;
                
            }
        }
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
    vector<int>colors(n+1,0);
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(colors[i]==0)
        bfscolorassign(adj,colors,i,n,flag);
        if(flag==1){
            break;
        }
    }
    if(flag==1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cout<<colors[i]<<" ";
    }
    cout<<endl;
}
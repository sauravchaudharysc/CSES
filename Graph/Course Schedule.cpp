#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void dfsHelper(vector<ll>adj[],vector<bool>&visited,vector<ll>&st,ll src){
    visited[src]=1;
    for(auto u:adj[src]){
        if(!visited[u]){
            dfsHelper(adj,visited,st,u);
        }
    }
    st.push_back(src);
}

bool detectCycle(vector<ll>adj[],vector<bool>&visited,vector<bool>&instack,ll src){
    visited[src]=1;
    instack[src]=1;
    for(auto u:adj[src]){
        if((!visited[u] && detectCycle(adj,visited,instack,u)) || instack[u]){
            return true;
        }
    }
    instack[src]=0;
    return false;
}

void dfs(vector<ll>adj[],ll n){
    vector<bool>visit(n+1,0);
    vector<bool>instack(n+1,0);
    for(ll i=1;i<=n;i++){
        if(!visit[i]){
                if(detectCycle(adj,visit,instack,i)){
                    cout<<"IMPOSSIBLE"<<endl;
                    return;
                }
        }
    }
    vector<bool>visited(n+1,0);
    vector<ll>st;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
                dfsHelper(adj,visited,st,i);
        }
    }
    for(auto u:st){
        cout<<u<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e;
    cin>>n>>e;
    vector<ll>adj[n+1];
    for(ll i=0;i<e;i++){
        ll a,b;
        cin>>a>>b;
        adj[b].push_back(a);
    }
    dfs(adj,n);
}
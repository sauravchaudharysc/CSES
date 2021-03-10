#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void dfsHelper(vector<ll>adj[],stack<ll>&st,vector<bool>&visited,ll src){
    visited[src]=1;
    for(auto u:adj[src]){
        if(!visited[u]){
            dfsHelper(adj,st,visited,u);
        }
    }
    st.push(src);
}

void assignkingdom(vector<ll> adj[],vector<bool> &visited,vector<ll> &ans,ll u,ll k){
    visited[u] = 1;
    ans[u] = k;
    for(auto v : adj[u]){
        if(!visited[v])
           assignkingdom(adj,visited,ans,v,k);
    }
}

void kosaraju(vector<ll>adj[],ll n,vector<ll>adjR[]){
    stack<ll>st;
    vector<bool>visited(n+1,0);
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfsHelper(adj,st,visited,i);
        }
    }
    ll component=0;
    vector<bool>ivisited(n+1,0);
    vector<ll> ans(n+1,0);
    
    while(!st.empty()){
        ll x = st.top();
        st.pop();
        if(ivisited[x]){
            continue;
        }    
        component++;
        assignkingdom(adjR,ivisited,ans,x,component);
    }
    
    cout<<component<<endl;
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}


int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+1];
    vector<ll>adjR[n+1];
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adjR[v].push_back(u);
    }
    kosaraju(adj,n,adjR);
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll ans=0;
ll mod=1e9+7;

void dfsHelper(vector<ll>adj[],vector<bool>&visited,vector<ll>&st,ll src){
    visited[src]=1;
    for(auto u:adj[src]){
        if(!visited[u])
        dfsHelper(adj,visited,st,u);
    }
    st.push_back(src);
}


void dfs(vector<ll>adj[],ll n){
    vector<bool>visited(n+1,0);
    vector<ll>st;
    dfsHelper(adj,visited,st,1);
    reverse(st.begin(),st.end());
    vector<ll>dist(n+1,0);
    vector<ll>path(n+1,0);
    ll z=st.size();
    ll i=0;
    while(st[i]!=1){
        i++;
    }
    for(i;i<z;i++){
        if(st[i]==n)break;
        for(auto u:adj[st[i]]){
            if(dist[u]<dist[st[i]]+1){
                dist[u]=dist[st[i]]+1;
                path[u]=st[i];
            }
        }
    }
    
    if(path[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        stack<ll>st ;
        while(n!=1){
            st.push(n);
            n=path[n];
        }
        st.push(n);
        cout<<st.size()<<endl;
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
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
        adj[a].push_back(b);
    }
    dfs(adj,n);
}
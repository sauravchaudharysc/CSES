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

void kosaraju(vector<ll>adj[],ll n,vector<ll>adjR[]){
    stack<ll>st;
    stack<ll>temp;
    vector<bool>visited(n+1,0);
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfsHelper(adj,st,visited,i);
        }
    }
    ll component=0;
    ll ans=0;
    vector<bool>ivisited(n+1,0);
    while(!st.empty()){
        ll x = st.top();
        st.pop();
        if(ivisited[x])continue;
        if(ans){
            cout<<"NO"<<endl;
            cout<<x<<" "<<temp.top()<<endl;
            return ;
        }
        dfsHelper(adjR,temp,ivisited,x);
        ans=1;
    }
    cout<<"YES"<<endl;
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
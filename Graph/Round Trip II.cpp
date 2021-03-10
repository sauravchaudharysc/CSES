#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll detectCycle(vector<ll>adj[],vector<bool>&visited,vector<ll>&st,vector<bool>&instack,ll src){
    visited[src]=1;
    instack[src]=1;
    st.push_back(src);
    for(auto u:adj[src]){
        if(!visited[u]){
            ll ans = detectCycle(adj,visited,st,instack,u);
            if(ans!=-1){
                return ans;
            }
        }
        else if (instack[u] ){
            return u;
        }
    }
    st.pop_back();
    instack[src]=0;
    return -1;
}

void dfs(vector<ll>adj[],ll n){
    vector<bool>visited(n+1,0);
    vector<bool>instack(n+1,0);
    vector<ll>st;
    ll cycle=0;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            cycle = detectCycle(adj,visited,st,instack,i);
            if(cycle!=-1){
                break;
            }
        }
    }
    if(cycle==-1){
            cout<<"IMPOSSIBLE"<<endl;
    }else{
        bool flag=0;
        list<ll>s;
        for(auto u:st){
            if(u==cycle){
                flag=1;
            }
            if(flag==1)
            s.push_back(u);
        }
        s.push_back(cycle);
        cout<<s.size()<<endl;
        for(auto u:s){
            cout<<u<<" ";
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
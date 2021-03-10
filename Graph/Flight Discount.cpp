#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class Edge{
    public:
    ll u;
    ll v;
    ll w;
};

void dijkstra(vector<pair<ll,ll>>adj[],vector<ll>&dist,ll src,ll n){
    for(ll i=1;i<=n;i++){
        dist[i]=LLONG_MAX;
    }
    vector<bool>visited(n+1,0);
    dist[src]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        pair<ll,ll> top = pq.top();
        pq.pop();
        ll weight = top.first;
        ll node = top.second;
        visited[node]=1;
        for(auto u:adj[node]){
            if(!visited[u.first]){
                if(dist[u.first]>dist[node]+u.second){
                    dist[u.first]=dist[node]+u.second;
                    pq.push({dist[u.first],u.first});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll e;
    cin>>e;
    vector<pair<ll,ll>>adj1[n+1];
    vector<pair<ll,ll>>adj2[n+1];
    vector<Edge>adjList(e);
    for(ll i=0;i<e;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj1[a].push_back({b,c});
        adj2[b].push_back({a,c});
        adjList[i].u=a;
        adjList[i].v=b;
        adjList[i].w=c;
    }
    
    vector<ll>dist1(n+1,0);
    vector<ll>dist2(n+1,0);
    dijkstra(adj1,dist1,1,n);
    dijkstra(adj2,dist2,n,n);
    ll ans=LLONG_MAX;
    for(ll i=0;i<e;i++){
        ll u =adjList[i].u;
        ll v =adjList[i].v;
        ll w =adjList[i].w;
        w=w/2;
        if(dist1[u]!=LLONG_MAX && dist2[u]!=LLONG_MAX)
        ans=min(ans,dist1[u]+dist2[v]+w);
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod=1e9+7;

void dijkstra(vector<pair<ll,ll>>adj[],ll src,ll n){
    
    //To Store Min Path
    vector<ll>dist(n+1,0);
    
    //To Store Count of Minimum Price Routes
    vector<ll>routes(n+1,0);
    routes[1]=1;
    
    //To Store Minimum Number of Flight to reach nth Node
    vector<ll>minFlight(n+1,0);
    
    //To Store Maximum Number of Flight to reach nth Node
    vector<ll>maxFlight(n+1,0);
    
    for(ll i=1;i<=n;i++){
        dist[i]=LLONG_MAX; 
    }
    
    //Min Heap to Pick the Shortest Path Each Time
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    
    
    //Initialise the first vertex distance as zero
    pq.push({0,src});
    
    while(!pq.empty()){
        pair<ll,ll> top = pq.top();
        pq.pop();
        ll weight = top.first;
        ll node = top.second;
        
        //If we already have the optimal path
        if(dist[node]<weight)continue;
        
        for(auto u:adj[node]){
                //If we have a better path to reach the current node
                if(dist[u.first]>weight+u.second){
                    dist[u.first]=weight+u.second;
                    //If we get a minimum distance, we need to remove old path count
                    //routes[u.first]=(routes[u.first]+routes[node])%mod;
                    //Include only those path which give mincost routes
                    routes[u.first]=(routes[node])%mod;
                    minFlight[u.first]=1+minFlight[node];
                    maxFlight[u.first]=1+maxFlight[node];
                    pq.push({dist[u.first],u.first});
                }else if(dist[u.first]==weight+u.second){
                    routes[u.first]=(routes[u.first]+routes[node])%mod;
                    minFlight[u.first]=min(minFlight[u.first],1+minFlight[node]);
                    maxFlight[u.first]=max(maxFlight[u.first],1+maxFlight[node]);
                }
        }
    }
    cout<<dist[n]<<" "<<routes[n]<<" "<<minFlight[n]<<" "<<maxFlight[n];    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e;
    cin>>n>>e;
    vector<pair<ll,ll>>adj[n+1];
    for(ll i=0;i<e;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    dijkstra(adj,1,n);
}
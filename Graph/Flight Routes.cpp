#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void dijkstra(vector<pair<ll,ll>>adj[],ll src,ll n,ll k){
    //2d Array to Store the Distance of K Shortest Paths
    vector<vector<ll>>dist(n+1,vector<ll>(k));
    
    for(ll i=1;i<=n;i++){
     for(ll j=0;j<k;j++){
        dist[i][j]=LLONG_MAX; 
     }    
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
        
        //If the node largest distance is less than current path it reach 
        if(dist[node][k-1]<weight)continue;
        
        
        for(auto u:adj[node]){
                //If we have a better path to reach the current node
                if(dist[u.first][k-1]>weight+u.second){
                    dist[u.first][k-1]=weight+u.second;
                    pq.push({dist[u.first][k-1],u.first});
                    //Sort the distance
                    sort(dist[u.first].begin(),dist[u.first].end());
                }
        }
    }
    for(ll i=0;i<k;i++){
        cout<<dist[n][i]<<" ";    
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e,k;
    cin>>n>>e>>k;
    vector<pair<ll,ll>>adj[n+1];
    for(ll i=0;i<e;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    dijkstra(adj,1,n,k);
}
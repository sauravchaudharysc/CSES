#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Edge{
    public:
    ll u;
    ll v;
    ll w;
};

int main(){
    ll n;
    cin>>n;
    ll e;
    cin>>e;
    vector<Edge>adjList(e);
    for(ll i=0;i<e;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adjList[i].u=a;
        adjList[i].v=b;
        c=(-1)*c;
        adjList[i].w=c;
    }
    vector<ll>dist(n+1,0);
    vector<ll>parent(n+1,-1);
    for(ll i=1;i<=n;i++){
        dist[i]=LLONG_MAX;
    }
    dist[1]=0;
    for(ll i=0;i<n-1;i++){
        for(ll j=0;j<e;j++){
            ll u =adjList[j].u;
            ll v =adjList[j].v;
            ll w =adjList[j].w;
            if(dist[u]!=LLONG_MAX && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }
    for(ll i=0;i<n-1;i++){
        for(ll j=0;j<e;j++){
                ll u =adjList[j].u;
                ll v =adjList[j].v;
                ll w =adjList[j].w;
                if(dist[u]!=LLONG_MAX && (dist[u]==LLONG_MIN || dist[v]>dist[u]+w) ){
                    dist[v]=LLONG_MIN;
                }
        }
    }
    if(dist[n]==LLONG_MIN){
        cout<<"-1"<<endl;
    }else{
        cout<<(-1)*dist[n]<<endl;
    }
}
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
        adjList[i].w=c;
    }
    vector<ll>dist(n+1,0);
    vector<ll>parent(n+1,-1);
    
    for(ll i=0;i<n-1;i++){
        bool lflag=0;
        for(ll j=0;j<e;j++){
            ll u =adjList[j].u;
            ll v =adjList[j].v;
            ll w =adjList[j].w;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                parent[v]=u;
                lflag=1;
            }
        }
        if(lflag==0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    bool flag=0;
    ll node;
    for(ll j=0;j<e;j++){
            ll u =adjList[j].u;
            ll v =adjList[j].v;
            ll w =adjList[j].w;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                parent[v]=u;
                node=u;
                flag=1;
            }
    }

    if(flag==1){
        for(ll i=1;i<=n;i++){
            node=parent[node];
        }
        cout<<"YES"<<endl;
        list<ll> lst;
        lst.push_front(node);
        ll ans=node;
        while(node!=parent[ans]){
            lst.push_front(parent[ans]);
            ans=parent[ans];
        }
        lst.push_front(node);
        for(auto u:lst){
            cout<<u<<" ";
        }
    }else{
        cout<<"NO"<<endl;
    }
}
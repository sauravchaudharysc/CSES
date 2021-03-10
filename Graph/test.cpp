#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int parent[100005];

ll findParent(ll u){
    if(u!=parent[u]){
        return parent[u]=findParent(parent[u]);
    }
    return u;
}

int main(){
 ll n,m;
 cin>>n>>m;
 
 vector<ll>size(n+1,1);
 for (ll i = 1; i <=n; i++) {
    parent[i]=i;
 }
 ll component=n;

     ll a,b;
     ll maxSize =1;    
 while(m--){
     cin>>a>>b;
     ll u=findParent(a);
     ll v= findParent(b);
        if(u!=v){
            component--;
            if(size[u]>size[v]){
            parent[v]=parent[u];
            size[u]=size[u]+size[v];
            size[v]=0;
            maxSize=max(maxSize,size[u]);    
            }else{
            parent[u]=parent[v];
            size[v]=size[u]+size[v];
            size[u]=0;
            maxSize=max(maxSize,size[v]);
            }
            
        }
        cout<<component<<" "<<maxSize<<endl;
 }
}
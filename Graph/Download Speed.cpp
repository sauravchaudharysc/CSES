#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[501][501];
ll rGraph[501][501];
bool bfs(ll src,ll sink,ll parent[]){
    bool visited[sink+1];
    memset(visited,0,sizeof(visited));
    queue<ll>q;
    q.push(src);
    visited[src]=true;
    parent[src]=-1;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
         for (int v = 1; v<=sink; v++) {
             if(!visited[v] && rGraph[u][v]>0){
                //If we find a connection to the sink node
                if(v==sink){
                    parent[v]=u;
                    return true;
                } 
                q.push(v);
                parent[v]=u;
                visited[v]=true;
             }
         }     
    }
    //Unable to reach sink
    return false;
}

ll fordFulkerson(ll src,ll sink){
    /*Fill residual graph with given capacities in the original
    graph. Residual graph indicates residual capacity of edge
    from i to j.*/
    for(ll i=1;i<=sink;i++){
        for(ll j=1;j<=sink;j++){
            rGraph[i][j]=arr[i][j];
        }
    }
    //Path is stored to find minimum edge weight in the path. 
    ll parent[sink+1];
    ll maxFlow=0;
    while(bfs(src,sink,parent)){
        ll pathflow = LLONG_MAX;
        for(ll i=sink; i!=src; i=parent[i]){
            ll j= parent[i];
            pathflow = min(pathflow,rGraph[j][i]);
        }
        for(ll i=sink; i!=src; i=parent[i]){
            ll j= parent[i];
            rGraph[j][i]-=pathflow;
            rGraph[i][j]+=pathflow;
        }
        maxFlow+=pathflow;
    }
    return maxFlow;
}
int main(){
    ll n,e;
    cin>>n>>e;
    memset(arr,0,sizeof(arr));
    for(ll i=0;i<e;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        //If there exist multiple paths between u and v
        arr[a][b]+=c;
    }
    /*// To Display Input Array
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    cout<<fordFulkerson(1,n);
}
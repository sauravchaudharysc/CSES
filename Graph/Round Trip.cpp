#include<bits/stdc++.h>
using namespace std;
 
bool dfs(vector<int>adj[],vector<bool>&visited,vector<int>&path,int src,int parent){
    visited[src]=1;
    path.push_back(src);
    for(auto u:adj[src]){
        if(!visited[u]){
            bool ans = dfs(adj,visited,path,u,src);
            if(ans) return true;
        }
//we arrive here if we find if a neighbour is already visited
//we check if its neighbour isnt parent if yes then there exist cycle        
        else if(u!=parent){
            path.push_back(u);
            return true;
        }
    }
    //Remove element when it doesnt give cycle
    //visited[src]=0;
    path.pop_back();
    return false;
}
 
int main(){
    int n,e;
    cin>>n;
    cin>>e;
    vector<int>adj[n+1];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
        vector<bool>visited(n+1,0);
        bool ans=0;
        vector<int>path;
    for(int i=1;i<=n;i++){
        if(!visited[i])
        ans= dfs(adj,visited,path,i,i);
        if(ans==1)break;
    }    
         
    if(ans){
        list<int>ll;
        int k=path.size()-1;
        int num=path[k];
        k--;
        ll.push_front(num);
        while(path[k]!=num){
            ll.push_front(path[k]);
            k--;
        }
        ll.push_front(num);
        cout<<ll.size()<<endl;
        for(auto it=ll.begin();it!=ll.end();it++){
            cout<<*it<<" ";
        }
        
    }else{
        cout<<"IMPOSSIBLE"<<endl;    
    }    
    
}
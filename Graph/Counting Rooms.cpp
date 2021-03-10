#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj,int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m){
        return;
    }
    if(adj[i][j]==-1){
        return ;
    }
    if(adj[i][j]==1){
        return ;
    }
    adj[i][j]=1;
    dfs(adj,i+1,j,n,m);
    dfs(adj,i-1,j,n,m);
    dfs(adj,i,j+1,n,m);
    dfs(adj,i,j-1,n,m);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int> (m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='#'){
                adj[i][j]=-1;
            }else{
                adj[i][j]=0;
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==0){
                count++;
                dfs(adj,i,j,n,m);
            }
        }
    }
    cout<<count<<endl;
}